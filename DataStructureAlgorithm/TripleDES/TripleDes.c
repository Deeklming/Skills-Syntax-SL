//compiler: clang 10(msvc), x64, cpu speed: 3.60GHz ~ 4.20GHz
#include <stdio.h>
#include <windows.h>//for time check

void Pbox(long long in, long long *out, unsigned char *box, int a, int c);
void Split(long long in, long *left, long *right, int c);
void Shift(long in, long *out, int c);
void Combine(long in1, long in2, long long *out, int c);
void F(long in, long *out, long long key);
void Sbox(long long in, long *out);

void make_key(long long in, long long *out);
void make_enc(long long in, long long *out, long long *key);
void make_dec(long long in, long long *out, long long *key);

unsigned char ParityBitDrop[56] =//Parity Drop Permutation Table
{
	57,49,41,33,25,17,9,1,
	58,50,42,34,26,18,10,2,
	59,51,43,35,27,19,11,3,
	60,52,44,36,63,55,47,39,
	31,23,15,7,62,54,46,38,
	30,22,14,6,61,53,45,37,
	29,21,13,5,28,20,12,4
};
unsigned char CompressionPbox[48] =//Permuted choice 2
{
	14,17,11,24,1,5,3,28,
	15,6,21,10,23,19,12,4,
	26,8,16,7,27,20,13,2,
	41,52,31,37,47,55,30,40,
	51,45,33,48,44,49,39,56,
	34,53,46,42,50,36,29,32
};
unsigned char IP[64] =//Initial permutation
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
unsigned char IP_1[64] =//Final permutation
{
	40,8,48,16,56,24,64,32,
	39,7,47,15,55,23,63,31,
	38,6,46,14,54,22,62,30,
	37,5,45,13,53,21,61,29,
	36,4,44,12,52,20,60,28,
	35,3,43,11,51,19,59,27,
	34,2,42,10,50,18,58,26,
	33,1,41,9,49,17,57,25
};
unsigned char EP[48] =//Expansion function
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
unsigned char P[32] =//Permutation
{
	16,7,20,21,29,12,28,17,
	1,15,23,26,5,18,31,10,
	2,8,24,14,32,27,3,9,
	19,13,30,6,22,11,4,25
};
unsigned char SBOX[8][4][16] =//Substitution boxes
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
//123456ABCD132536 - plaintext
//C0B7A8D05F3A829C - DES ciphertext
//29B4F390E2E9807D - 3DES ciphertext
int main(int argc, char *argv[]) {
	LARGE_INTEGER Start, End, Frequency;
	double Time;
	long long plaintext = 0x123456ABCD132536;//input plaintext
	long long k1 = 0xAABB09182736CCDD;//input key1
	long long k2 = 0xEEFF23408293AA15;//input key2
	long long key1[16] = { 0, };//use key1
	long long key2[16] = { 0, };//use key2
	long long ciphertext = 0, decrypttext = 0, dctemp = 0;//_, _, temptext

	printf("-----------------DES----------------\n");
	printf("DES___plaintext : %llX\n", plaintext);
	QueryPerformanceFrequency(&Frequency);
	QueryPerformanceCounter(&Start);
	make_key(k1, key1);//make key1
	make_enc(plaintext, &ciphertext, key1);//encryption
	make_dec(ciphertext, &decrypttext, key1);//decryption
	QueryPerformanceCounter(&End);
	Time = (double)(End.QuadPart - Start.QuadPart) / Frequency.QuadPart;
	printf("DES__ciphertext : %llX\n", ciphertext);
	printf("DES_decrypttext : %llX\n", decrypttext);
	printf("DES make [key, enc, dec] time : %lf (sec)\n", Time);

	printf("----------------3DES----------------\n");
	printf("3DES___plaintext : %llX\n", plaintext);
	QueryPerformanceFrequency(&Frequency);
	QueryPerformanceCounter(&Start);
	make_key(k1, key1);
	make_key(k2, key2);//make key2
	make_enc(plaintext, &ciphertext, key1);
	make_dec(ciphertext, &dctemp, key2);
	make_enc(dctemp, &ciphertext, key1);
	make_dec(ciphertext, &decrypttext, key1);
	make_enc(decrypttext, &dctemp, key2);
	make_dec(dctemp, &decrypttext, key1);
	QueryPerformanceCounter(&End);
	Time = (double)(End.QuadPart - Start.QuadPart) / Frequency.QuadPart;
	printf("3DES__ciphertext : %llX\n", ciphertext);
	printf("3DES_decrypttext : %llX\n", decrypttext);
	printf("3DES make [key, enc, dec] time : %lf (sec)\n", Time);

	printf("-----3DES-key-change-2^16-times-----\n");
	printf("3DES___plaintext : %llX\n", plaintext);
	long long kk1 = 0xEEFF23408293AA15;
	long long kk2 = 0xAABB09182736CCDD;
	QueryPerformanceFrequency(&Frequency);
	QueryPerformanceCounter(&Start);
	for (int i = 0; i < 65536; ++i) {//2^16
		make_key(kk1, key1);
		make_key(kk2, key2);
		make_enc(plaintext, &ciphertext, key1);
		make_dec(ciphertext, &dctemp, key2);
		make_enc(dctemp, &ciphertext, key1);
		make_dec(ciphertext, &decrypttext, key1);
		make_enc(decrypttext, &dctemp, key2);
		make_dec(dctemp, &decrypttext, key1);
		--kk1;
		--kk2;
	}
	QueryPerformanceCounter(&End);
	Time = (double)(End.QuadPart - Start.QuadPart) / Frequency.QuadPart;
	printf("3DES__ciphertext : %llX\n", ciphertext);
	printf("3DES_decrypttext : %llX\n", decrypttext);
	printf("3DES change [key, enc, dec] time : %lf (sec)\n", Time);
	printf("------------------------------------\n");
	return 0;
}

void make_enc(long long in, long long *out, long long *key) {//encryption function
	long long ip = 0, frc = 0, ip_1 = 0;
	long left = 0, right = 0, f = 0, fxor = 0;
	
	Pbox(in, &ip, IP, 64, 64);
	Split(ip, &left, &right, 64);
	for (int i = 0; i < 16; ++i) {
		F(right, &f, key[i]);
		fxor = f ^ left;
		if (i < 15) {
			left = right;
			right = fxor;
		}
	}
	Combine(fxor, right, &frc, 64);
	Pbox(frc, &ip_1, IP_1, 64, 64);

	*out = ip_1;
}

void make_dec(long long in, long long *out, long long *key) {//decryption function
	long long ip = 0, frc = 0, ip_1 = 0;
	long left = 0, right = 0, f = 0, fxor = 0;

	Pbox(in, &ip, IP, 64, 64);
	Split(ip, &left, &right, 64);
	for (int i = 15; i >= 0; --i) {
		F(right, &f, key[i]);
		fxor = f ^ left;
		if (i > 0) {
			left = right;
			right = fxor;
		}
	}
	Combine(fxor, right, &frc, 64);
	Pbox(frc, &ip_1, IP_1, 64, 64);
	
	*out = ip_1;
}

void F(long in, long *out, long long key) {//F function
	long long ep = 0, sr = 0;
	long s = 0;

	Pbox(in, &ep, EP, 32, 48);
	ep ^= key;
	Sbox(ep, &s);
	Pbox(s, &sr, P, 32, 32);
	
	*out = (long)sr;
}

void Sbox(long long in, long *out) {//sbox function
	char div[8] = { 0, };
	char a, h, y;
	int count = 1;

	for (int i = 7; i >= 0; --i) {
		div[i] = in & 0x3F;//00111111
		in >>= 6;
	}
	for (int i = 0; i < 8; ++i) {
		a = div[i] & 0x01;
		div[i] >>= 1;
		y = div[i] & 0x0F;
		div[i] >>= 4;
		div[i] <<= 1;
		h = div[i] + a;
		div[i] = SBOX[i][h][y];
	}
	for (int i = 0; i < 8; ++i) {
		for (int j = 3; j >= 0; --j) {
			if ((div[i] >> j) & 1) {
				*out ^= 1;
			}
			if (count < 32) {
				*out <<= 1;
				++count;
			}
		}
	}
}

void make_key(long long in, long long *out) {//make key function
	long long key = 0, LRcb = 0, f_key_r = 0;
	long left = 0, right = 0, left_r = 0, right_r = 0;

	Pbox(in, &key, ParityBitDrop, 64, 56);
	Split(key, &left, &right, 56);
	for (int i = 1; i <= 16; ++i) {
		if (i == 1 || i == 2 || i == 9 || i == 16) {
			Shift(left, &left_r, 1);
			Shift(right, &right_r, 1);
		}
		else {
			Shift(left, &left_r, 2);
			Shift(right, &right_r, 2);
		}
		Combine(left_r, right_r, &LRcb, 56);
		Pbox(LRcb, &f_key_r, CompressionPbox, 56, 48);
		out[i - 1] = f_key_r;
		left = left_r;
		right = right_r;
		left_r = right_r = LRcb = f_key_r = 0;
	}
}

void Combine(long in1, long in2, long long *out, int c) {//combine function
	int count = 1;

	for (int i = c / 2 - 1; i >= 0; --i) {
		if (((in1 >> i) & 1)) {
			*out ^= 1;
		}
		*out <<= 1;
		++count;
	}
	for (int i = c / 2 - 1; i >= 0; --i) {
		if (((in2 >> i) & 1)) {
			*out ^= 1;
		}
		if (count < c) {
			*out <<= 1LL;
			++count;
		}
	}
}

void Shift(long in, long *out, int c) {//shift function
	long x = in <<= c;
	long y = x & 0x0FFFFFFF;
	long z = x >> 0x1C;//28
	
	*out = y + z;
}

void Split(long long in, long *left, long *right, int c) {//split function
	int j = c / 2;
	
	for (int i = j - 1; i >= 0; --i) {
		if (((in >> i) & 1)) {
			*right ^= 1;
		}
		if (((in >> (i + j)) & 1)) {
			*left ^= 1;
		}
		if (i > 0) {
			*right <<= 1;
			*left <<= 1;
		}
	}
}

void Pbox(long long in, long long *out, unsigned char *box, int a, int c) {// pbox function
	int count = c - 1;
	
	for (int i = 0; i < c; ++i) {
		if (in & (1LL << (a - box[i]))) {
			*out ^= 1;
		}
		if (i < count) {
			*out <<= 1LL;
		}
	}
}
