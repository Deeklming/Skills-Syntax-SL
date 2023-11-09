# C++
## Links
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
clang 12+(llvm), msvc v143+(compile), gcc 10+(compile)

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

## Language Feature
C++은 C언어와의 호환성을 가진 객체 지향 언어이지만 최근의 C++은 거의 새로운 언어임
### comments (주석)
```c++
// int cpp = 0;
/*
...
*/
```
//: 한줄 주석   
/* */: 여러줄 주석
### 표기법
변수명: lower   
함수명: camelCase   
상수명: SCREAMING_SNAKE_CASE   
클래스명: PascalCase
