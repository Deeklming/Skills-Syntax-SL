//compiler: clang 10(msvc), x64, cpu speed: 3.60GHz ~ 4.20GHz
#include <stdio.h>
#include <Windows.h>//시간측정용
#define ui32 unsigned int
#define range 254

int PrimeNumber(ui32 in1, ui32 out1[]);//in1의 입력값이 작을수록 빠름
int SieveOfEratosthenes(ui32 in1, ui32 out1[]);//in1의 입력값이 클수록 빠름

int main(){
    LARGE_INTEGER f, start, end;
    ui32 pn[range] = {0,};
    ui32 pn1[range] = {0,};

    QueryPerformanceFrequency(&f);
    QueryPerformanceCounter(&start);
    int a = PrimeNumber(1600, pn);//1600까지 소수
    QueryPerformanceCounter(&end);
    if(a){printf("PrimeNumber fail.\n"); return -1;}
    printf("PrimeNumber\n");
    for(int i=0; i<range; ++i){printf("%d ", pn[i]);}
    __int64 e = end.QuadPart-start.QuadPart;
    printf("\ntime: %lf\n", (double)e/(double)f.QuadPart);
    
    QueryPerformanceFrequency(&f);
    QueryPerformanceCounter(&start);
    a = SieveOfEratosthenes(1600, pn1);
    QueryPerformanceCounter(&end);
    if(a){printf("PrimeNumber fail.\n"); return -1;}
    printf("\nSieveOfEratosthenes\n");
    for(int i=0; i<range; ++i){printf("%d ", pn1[i]);}
    e = end.QuadPart-start.QuadPart;
    printf("\ntime: %lf\n", (double)e/(double)f.QuadPart);
    return 0;
}

int PrimeNumber(ui32 in1, ui32 out1[]){//소수 구하기, 실패하면 -1, 성공하면 0 반환
    if(in1>100001 || in1<2) {printf("error in1>10000 or in1<2. "); return -1;}
    int p = 0;
    out1[p++]=2;
    if(in1==2) return 0;
    for(int i=3; i<=in1; i+=2){
        _Bool check = 0;
        for(int j=0; out1[j]*out1[j]<=i; j++){
            if(i%out1[j]==0){check = 1; break;}
        }
        if(!check) out1[p++] = i;
    }
    return 0;
}

int SieveOfEratosthenes(ui32 in1, ui32 out1[]){//에라토스테네스의 체
    if(in1>100001 || in1<2) {printf("error in1>10000 or in1<2. "); return -1;}
    int p = 0;
    out1[p++]=2;
    if(in1==2) return 0;
    _Bool temp[100001] = {0,};
    temp[0] = 1; temp[1] = 1;
    for(int i=4; i<=in1; i+=2) temp[i] = 1;
    for(int i=3; i<=in1; i+=2){
        if(!temp[i]){
            for(int j=i*2; j<=in1; j+=i) temp[j] = 1;
            out1[p++]=i;
        }
    }
    return 0;
}
