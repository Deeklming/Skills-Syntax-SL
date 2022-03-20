# GO

## 기본형태
```go
package rootfoldername;

func main(){
    println("go")
}
```

## 환경변수 설정
```
PATH = Go/bin
```

## CLI 컴파일 후 실행
- go 1.18 +
```
go run gofile.go - go 빌드 후 자동 실행
go build gofile.go - go 빌드
```

## 주석
```go
//g := 0;
/*
...
*/
```
주석에서 //은 한줄 주석이고 /* */은 여러줄 주석이다   
vscode단축키: ctrl + /(윈도우), cmd + /(맥)   여러줄일 경우 블록지정하여 사용한다

## 표기법
고에서 (변수명과 함수명은 camelCase, 상수명은 모두 대문자에 SNAKE_CASE, 클래스명은 PascalCase, 패키지명은 모두 소문자를 사용한다)
