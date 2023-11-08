#include <iostream>
#include <vector>
using namespace std;

const int UNKNOWN=-1;
const int MAX_SIZE=20;
vector<int> cache(MAX_SIZE, UNKNOWN);

int Fibonacci1(int n);//memoization
int Fibonacci2(int n);//tabulation

int main(){
    cout<<"memoization: "<<Fibonacci1(9)<<endl;
    for(int i=0; i<10; i++){
        cout<<cache[i]<<" ";
    }

    cout<<"\ntabulation: "<<Fibonacci2(9)<<endl;
    cout<<endl;
}

int Fibonacci1(int n){//memoization
    if(n<2) return n;
    if(cache[n] != UNKNOWN) return cache[n];//중복 작업 제거
    int result = Fibonacci1(n-1) + Fibonacci1(n-2);
    cache[n]=result;
    return result;
}

int Fibonacci2(int n){//tabulation
    vector<int> TT(n+1, 0);
    TT[1]=1;
    for(int i=2; i<=n; i++){
        TT[i]=TT[i-1]+TT[i-2];
    }
    return TT[n];
}
