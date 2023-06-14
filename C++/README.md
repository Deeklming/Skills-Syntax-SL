# C++
[C++ 위키피디아](https://ko.wikipedia.org/wiki/C%2B%2B)

## Basic Form
```c++
#include <iostream>

int main(int argc, char* argv[]){
    std::cout<<"c++!"<<std::endl;
}
```

## Language Version
c++ 17+

## Compiler
clang 12+

## CLI Compile and Run
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

## Comments (주석)
```c++
// int cpp = 0;
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
