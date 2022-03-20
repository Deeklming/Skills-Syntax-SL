# C++

## 기본형태
```c++
#include <iostream>

using namespace std;

int main(){
    cout<<"c++"<<endl;
}
```


## 환경변수 설정
```
PATH = C++/bin
```

## CLI 컴파일 후 실행
- clang 12 + - c++17, windows
```
clang++ cppfile.cpp -o filename.exe
./filename.exe
```
- g++ - c++17, linux
```
g++ cppfile.cpp -o filename
./filename
```

## 주석
```c++
//int cpp = 0;
/*
...
*/
```
주석에서 //은 한줄 주석이고 /* */은 여러줄 주석이다   
vscode단축키: ctrl + /(윈도우), cmd + /(맥)   여러줄일 경우 블록지정하여 사용한다

## 표기법
C++에서 변수명은 소문자 함수명은 camelCase, 상수명은 모두 대문자에 SNAKE_CASE, 클래스명은 PascalCase를 사용한다
