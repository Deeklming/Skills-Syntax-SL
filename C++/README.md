# C++
[C++ 위키백과](https://ko.wikipedia.org/wiki/C%2B%2B)

## 기본 형태
```c++
#include <iostream>

int main(int argc, char* argv[]){
    std::cout<<"c++"<<std::endl;
}
```

## 언어 버전
c++17, c++20(최신)

## 컴파일러
clang 12+

## CLI 컴파일 후 실행
### Windows
```
clang++ cppfile.cpp -o filename.exe
./filename.exe
```
### Linux
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
//: 한줄 주석   
/* */: 여러줄 주석

## 표기법
변수명: 소문자
함수명: camelCase
상수명: 모두 대문자에 SNAKE_CASE
클래스명: PascalCase
