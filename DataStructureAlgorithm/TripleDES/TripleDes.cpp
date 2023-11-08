//compiler: clang 10(msvc), x64, cpu speed: 3.60GHz ~ 4.20GHz
#include <iostream>
#include <bitset>//just for study
#include <Windows.h>//for time check
typedef unsigned char uc;
using namespace std;

class TripleDes {
	static uc ParityBitDrop[56]; //Parity Drop Permutation Table
	static uc CompressionPbox[48]; //Permuted choice 2
	static uc IP[64]; //Initial permutation
	//static uc IP_1[64]; //Final permutation
	static uc IP_1_New[64]; //Final permutation myNew
	static uc EP[48]; //Expansion function
	static uc P[32]; //Permutation
	static uc SBOX[8][4][16]; //Substitution boxes
	bitset<64> plaintext, k1, k2, ciphertext, decrypttext;
	bitset<48> key1[16], key2[16];
	void MakeKey();
	void PC_1(bitset<64> &in, bitset<28> &out1, bitset<28> &out2, uc *box) {//Permuted choice 1 (Pbox+Split in makekey)
		int i = 0;
		for (; i < 28; ++i) {
			if (in[64 - box[i]]) {
				out1.set(27 - i);
			}
		}
		for (int j = 27; i < 56; ++i, --j) {
			if (in[64 - box[i]]) {
				out2.set(j);
			}
		}
	}
	template<size_t N, size_t M>
	void Pbox(bitset<N> &in, bitset<M> &out, uc *box) {//permutation box
		int m = M - 1;
		for (int i = 0; i < M; ++i) {
			if (in[N - box[i]]) {
				out.set(m - i);
			}
		}
	}
	void ShiftCb(bitset<28> &in1, bitset<28> &in2, bitset<56> &out, int c) {//(Shift+Combine in makekey)
		int sc = 28 - c;
		bitset<28> temp = in1 >> sc;
		in1 <<= c;
		in1 |= temp;
		temp = in2 >> sc;
		in2 <<= c;
		in2 |= temp;
		long long temp2 = in1.to_ullong();
		temp2 <<= 28;
		temp2 += in2.to_ullong();
		out = temp2;
	}
	void TripleDesEnc();
	void TripleDesDec();
	void F(bitset<32> &in, bitset<32> &out, bitset<48> &k) {//f function in enc and dec
		bitset<48> ep;
		bitset<32> s, sr;
		Pbox(in, ep, TripleDes::EP);
		ep ^= k;
		Sbox(ep, s);
		Pbox(s, sr, TripleDes::P);
		out = sr;
	}
	void Sbox(bitset<48> &in, bitset<32> &out) {//Substitution boxes function
		bitset<6> div[8];
		unsigned long div_r = 0;
		int c = 47;
		for (int i = 0; i < 8; ++i) {
			for (int j = 5; j >= 0; --j, --c) {
				div[i][j] = in[c];
			}
		}
		int x = 0, y = 0;
		for (int i = 0; i < 8; ++i) {
			x = div[i][5];
			x <<= 1;
			y = div[i][4];
			y <<= 1;
			y += div[i][3];
			y <<= 1;
			y += div[i][2];
			y <<= 1;
			y += div[i][1];
			x += div[i][0];
			div_r += TripleDes::SBOX[i][x][y];
			if (i != 7)	div_r <<= 4;
		}
		out = div_r;
	}
	void PboxSplit_IP(bitset<64> &in, bitset<32> &out1, bitset<32> &out2) {//pbox+split in enc, dec
		int i = 0;
		for (; i < 32; ++i) {
			if (in[64 - TripleDes::IP[i]])
				out1.set(31 - i);
		}
		for (; i < 64; ++i) {
			if (in[64 - TripleDes::IP[i]])
				out2.set(63 - i);
		}
	}
	void CombPbox_IP_1(bitset<32> &in1, bitset<32> &in2, bitset<64> &out) {//Combine+Pbox in enc, dec
		long long temp = in1.to_ullong();
		temp <<= 32;
		temp += in2.to_ullong();
		for (int i = 0; i < 64; ++i) {
			if (temp & 1LL)
				out.set(63 - TripleDes::IP_1_New[i]);
			temp >>= 1;
		}
	}
public:
	TripleDes(bitset<64> plaintext = 0, bitset<64> k1 = 0, bitset<64> k2 = 0) {
		this->plaintext = plaintext;
		this->k1 = k1;
		this->k2 = k2;
		MakeKey();
		TripleDesEnc();
		TripleDesDec();
	}
	void UpdatePlaintext(bitset<64> plaintext) {
		this->plaintext = plaintext;
		TripleDesEnc();
		TripleDesDec();
	}
	void UpdateKeys(bitset<64> k1, bitset<64> k2) {
		this->k1 = k1;
		this->k2 = k2;
		MakeKey();
		TripleDesEnc();
		TripleDesDec();
	}
	void UpdateAll(bitset<64> plaintext, bitset<64> k1, bitset<64> k2) {
		this->plaintext = plaintext;
		this->k1 = k1;
		this->k2 = k2;
		MakeKey();
		TripleDesEnc();
		TripleDesDec();
	}
	long long FinalEnc() {
		return ciphertext.to_ullong();
	}
	long long FinalDec() {
		return decrypttext.to_ullong();
	}
	void pr() {
		cout << "k1 : " << hex << k1.to_ullong() << endl;
		cout << "k2 : " << hex << k2.to_ullong() << endl;
		cout << "3des___plaintext : " << hex << plaintext.to_ullong() << endl;
		cout << "3des__ciphertext : " << hex << ciphertext.to_ullong() << endl;
		cout << "3des_decrypttext : " << hex << decrypttext.to_ullong() << endl;
	}
};
void TripleDes::TripleDesDec() {
	bitset<64> ip, comb, ip_1;
	bitset<32> L, R, f, Lfxor;
	PboxSplit_IP(ciphertext, L, R);
	for (int i = 15; i >= 0; --i) {
		F(R, f, key1[i]);
		Lfxor = L ^ f;
		if (i > 0) {
			L = R;
			R = Lfxor;
		}
	}
	CombPbox_IP_1(Lfxor, R, ip_1);
	ip.reset();

	L.reset();
	R.reset();
	PboxSplit_IP(ip_1, L, R);
	ip_1.reset();
	for (int i = 0; i < 16; ++i) {
		F(R, f, key2[i]);
		Lfxor = L ^ f;
		if (i < 15) {
			L = R;
			R = Lfxor;
		}
	}
	CombPbox_IP_1(Lfxor, R, ip_1);
	ip.reset();

	L.reset();
	R.reset();
	PboxSplit_IP(ip_1, L, R);
	ip_1.reset();
	for (int i = 15; i >= 0; --i) {
		F(R, f, key1[i]);
		Lfxor = L ^ f;
		if (i > 0) {
			L = R;
			R = Lfxor;
		}
	}
	CombPbox_IP_1(Lfxor, R, ip_1);
	decrypttext = ip_1;
}
void TripleDes::TripleDesEnc() {
	bitset<64> ip, comb, ip_1;
	bitset<32> L, R, f, Lfxor;
	PboxSplit_IP(plaintext, L, R);
	for (int i = 0; i < 16; ++i) {
		F(R, f, key1[i]);
		Lfxor = L ^ f;
		if (i < 15) {
			L = R;
			R = Lfxor;
		}
	}
	CombPbox_IP_1(Lfxor, R, ip_1);
	ip.reset();

	L.reset();
	R.reset();
	PboxSplit_IP(ip_1, L, R);
	ip_1.reset();
	for (int i = 15; i >= 0; --i) {
		F(R, f, key2[i]);
		Lfxor = L ^ f;
		if (i > 0) {
			L = R;
			R = Lfxor;
		}
	}
	CombPbox_IP_1(Lfxor, R, ip_1);
	ip.reset();

	L.reset();
	R.reset();
	PboxSplit_IP(ip_1, L, R);
	ip_1.reset();
	
	for (int i = 0; i < 16; ++i) {
		F(R, f, key1[i]);
		Lfxor = L ^ f;
		if (i < 15) {
			L = R;
			R = Lfxor;
		}
	}
	CombPbox_IP_1(Lfxor, R, ip_1);
	ciphertext = ip_1;
}
void TripleDes::MakeKey() {
	bitset<56> k_lr1, k_lr2;
	bitset<48> fin1, fin2;
	bitset<28> lf1, ri1, lf2, ri2;
	PC_1(k1, lf1, ri1, TripleDes::ParityBitDrop);
	PC_1(k2, lf2, ri2, TripleDes::ParityBitDrop);
	for (int i = 0; i < 16; ++i) {//1,2,9,16 round - 2shift
		if (i == 0 || i == 1 || i == 8 || i == 15) {
			ShiftCb(lf1, ri1, k_lr1, 1);
			ShiftCb(lf2, ri2, k_lr2, 1);
		}
		else {
			ShiftCb(lf1, ri1, k_lr1, 2);
			ShiftCb(lf2, ri2, k_lr2, 2);
		}
		Pbox(k_lr1, fin1, TripleDes::CompressionPbox);
		Pbox(k_lr2, fin2, TripleDes::CompressionPbox);
		key1[i] = fin1;
		key2[i] = fin2;
		fin1.reset();
		fin2.reset();
	}
}
//123456ABCD132536 - plaintext
//29B4F390E2E9807D - 3DES ciphertext
int main() {
	LARGE_INTEGER Start, End, Frequency;
	double Time;
	QueryPerformanceFrequency(&Frequency);
	QueryPerformanceCounter(&Start);
	TripleDes des(0x123456ABCD132536, 0xAABB09182736CCDD, 0xEEFF23408293AA15);//first
	QueryPerformanceCounter(&End);
	Time = (double)(End.QuadPart - Start.QuadPart) / Frequency.QuadPart;
	des.pr();
	cout << "3DES make key, enc, dec time : " << Time << " (sec)" << endl;

	cout << "\nkey change 2^16times" << endl;
	long long a1 = 0xEEFF23408293AA15, a2 = 0xAABB09182736CCDD;
	QueryPerformanceFrequency(&Frequency);
	QueryPerformanceCounter(&Start);
	for (int i = 0; i < 65536; ++i) {//2^16 change
		des.UpdateKeys(a1, a2);
		a1 -= 1;
		a2 -= 1;
	}
	QueryPerformanceCounter(&End);
	Time = (double)(End.QuadPart - Start.QuadPart) / Frequency.QuadPart;
	des.pr();
	cout << "3DES change key, enc, dec time : " << Time << " (sec)" << endl;
}

uc TripleDes::ParityBitDrop[56] =
{
	57,49,41,33,25,17,9,1,
	58,50,42,34,26,18,10,2,
	59,51,43,35,27,19,11,3,
	60,52,44,36,63,55,47,39,
	31,23,15,7,62,54,46,38,
	30,22,14,6,61,53,45,37,
	29,21,13,5,28,20,12,4
};
uc TripleDes::CompressionPbox[48] =
{
	14,17,11,24,1,5,3,28,
	15,6,21,10,23,19,12,4,
	26,8,16,7,27,20,13,2,
	41,52,31,37,47,55,30,40,
	51,45,33,48,44,49,39,56,
	34,53,46,42,50,36,29,32
};
uc TripleDes::IP[64] =
{
	58,50,42,34,26,18,10,2,
	60,52,44,36,28,20,12,4,
	62,54,46,38,30,22,14,6,
	64,56,48,40,32,24,16,8,
	57,49,41,33,25,17,9,1,
	59,51,43,35,27,19,11,3,
	61,53,45,37,29,21,13,5,
	63,55,47,39,31,23,15,7
};
/*uc TripleDes::IP_1[64] =
{
	40,8,48,16,56,24,64,32,
	39,7,47,15,55,23,63,31,
	38,6,46,14,54,22,62,30,
	37,5,45,13,53,21,61,29,
	36,4,44,12,52,20,60,28,
	35,3,43,11,51,19,59,27,
	34,2,42,10,50,18,58,26,
	33,1,41,9,49,17,57,25
};*/
uc TripleDes::IP_1_New[64] =//myNew
{
	6,14,22,30,38,46,54,62,
	4,12,20,28,36,44,52,60,
	2,10,18,26,34,42,50,58,
	0,8,16,24,32,40,48,56,
	7,15,23,31,39,47,55,63,
	5,13,21,29,37,45,53,61,
	3,11,19,27,35,43,51,59,
	1,9,17,25,33,41,49,57
};
uc TripleDes::EP[48] =
{
	32,1,2,3,4,5,
	4,5,6,7,8,9,
	8,9,10,11,12,13,
	12,13,14,15,16,17,
	16,17,18,19,20,21,
	20,21,22,23,24,25,
	24,25,26,27,28,29,
	28,29,30,31,32,1
};
uc TripleDes::P[32] =
{
	16,7,20,21,29,12,28,17,
	1,15,23,26,5,18,31,10,
	2,8,24,14,32,27,3,9,
	19,13,30,6,22,11,4,25
};
uc TripleDes::SBOX[8][4][16] =
{
	{
		{ 14,4,13,1,2,15,11,8,3,10,6,12,5,9,0,7 },
		{ 0,15,7,4,14,2,13,1,10,6,12,11,9,5,3,8 },
		{ 4,1,14,8,13,6,2,11,15,12,9,7,3,10,5,0 },
		{ 15,12,8,2,4,9,1,7,5,11,3,14,10,0,6,13 }
	},
	{
		{ 15,1,8,14,6,11,3,4,9,7,2,13,12,0,5,10 },
		{ 3,13,4,7,15,2,8,14,12,0,1,10,6,9,11,5 },
		{ 0,14,7,11,10,4,13,1,5,8,12,6,9,3,2,15 },
		{ 13,8,10,1,3,15,4,2,11,6,7,12,0,5,14,9 }
	},
	{
		{ 10,0,9,14,6,3,15,5,1,13,12,7,11,4,2,8 },
		{ 13,7,0,9,3,4,6,10,2,8,5,14,12,11,15,1 },
		{ 13,6,4,9,8,15,3,0,11,1,2,12,5,10,14,7 },
		{ 1,10,13,0,6,9,8,7,4,15,14,3,11,5,2,12 }
	},
	{
		{ 7,13,14,3,0,6,9,10,1,2,8,5,11,12,4,15 },
		{ 13,8,11,5,6,15,0,3,4,7,2,12,1,10,14,9 },
		{ 10,6,9,0,12,11,7,13,15,1,3,14,5,2,8,4 },
		{ 3,15,0,6,10,1,13,8,9,4,5,11,12,7,2,14 }
	},
	{
		{ 2,12,4,1,7,10,11,6,8,5,3,15,13,0,14,9 },
		{ 14,11,2,12,4,7,13,1,5,0,15,10,3,9,8,6 },
		{ 4,2,1,11,10,13,7,8,15,9,12,5,6,3,0,14 },
		{ 11,8,12,7,1,14,2,13,6,15,0,9,10,4,5,3 }
	},
	{
		{ 12,1,10,15,9,2,6,8,0,13,3,4,14,7,5,11 },
		{ 10,15,4,2,7,12,9,5,6,1,13,14,0,11,3,8 },
		{ 9,14,15,5,2,8,12,3,7,0,4,10,1,13,11,6 },
		{ 4,3,2,12,9,5,15,10,11,14,1,7,6,0,8,13 }
	},
	{
		{ 4,11,2,14,15,0,8,13,3,12,9,7,5,10,6,1 },
		{ 13,0,11,7,4,9,1,10,14,3,5,12,2,15,8,6 },
		{ 1,4,11,13,12,3,7,14,10,15,6,8,0,5,9,2 },
		{ 6,11,13,8,1,4,10,7,9,5,0,15,14,2,3,12 }
	},
	{
		{ 13,2,8,4,6,15,11,1,10,9,3,14,5,0,12,7 },
		{ 1,15,13,8,10,3,7,4,12,5,6,11,0,14,9,2 },
		{ 7,11,4,1,9,12,14,2,0,6,10,13,15,3,5,8 },
		{ 2,1,14,7,4,10,8,13,15,12,9,0,3,5,6,11 }
	}
};