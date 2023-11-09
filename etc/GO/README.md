# GO
## Links
[GO Homepage](https://go.dev/)

## Basic Form
```go
package main

import (
    "fmt"
)

func main(){
    fmt.Println("go!")
}
```

## Language Version
Go 1.18+

## Compiler
go(llvm)

## CLI Compile and Run
```
go run gofile.go : go 빌드 후 자동 실행 후 빌드 파일 자동 삭제
go build gofile.go : go 빌드
go build -ldflags "-s -w" gofile.go : golang release build
```
build 옵션은 컴파일 후 정적 링크 실행 파일(외부 라이브러리 없이 하나의 파일)로 생성함

## Language Feature
Go 언어의 패러다임은 절차형, 동시성, 분산을 지원하고 가비지 컬렉션을 지원하며 강타입임   
Go 언어는 전처리기를 사용하지 않고 기본적으로 static linking(정적 링크)를 사용하기에 동일한 OS끼리 바이너리를 넘기기 쉬움
### import
Go 언어는 실제 사용하는 패키지만 import 할 수 있고 사용하지 않는 패키지는 앞에 _를 사용하여 제외시킬 수 있음
### underscore (언더스코어)
```go
a, _ := 1, 2
```
_ 는 blank identifier(빈 식별자)라고 부르며 값을 무시할 때 사용됨
### bracket (중괄호)
```
표현식 { <- {는 표현식 옆 위치 필수
...
}
```
Go 언어에서 중괄호는 컴파일러가 자동으로 ;(세미콜론)을 삽입하기 때문에 엄격한 방식을 채택했음
### comments (주석)
```go
//go := 0
/*
...
*/
```
//: 한줄 주석   
/* */: 여러줄 주석
### 표기법
패키지명: all lower   
변수와 함수명: camelCase   
상수명: SCREAMING_SNAKE_CASE   
클래스명: PascalCase   
파일명: snake_case
