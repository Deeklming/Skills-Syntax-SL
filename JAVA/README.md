# JAVA

## 기본형태
```java
package rootfoldername;

public class filename{
    public static void main(String[] args) {
        System.out.println("java");        
    }
}
```
package 이름은 해당 프로젝트 이름으로 폴더명과 같아야 하고 main함수의 첫 시작 class 이름은 해당 파일명과 같아야 하며 main함수 있는 클래스가 다른 class보다 위에 있는 것이 좋다

## 환경변수 설정
```
JAVA_HOME = jdk_folder_path
PATH = JAVA_HOME/bin - windows(%JAVA_HOME%), linux($JAVA_HOME, 끝에 /:$PATH 붙임)
CLASSPATH = JAVA_HOME/lib - windows(%JAVA_HOME%), linux($JAVA_HOME, 끝에 /:$CLASSPATH 붙임)
```

## JVM이 CLASS파일을 실행시키는 방법
```
1. 같은 폴더에서 class파일을 찾아서 실행
2. 1에서 찾지 못했다면 package경로에 따라 class파일을 찾아서 실행
3. 1,2에서 찾지 못했다면 classpath에 지정된 폴더에서 찾아서 실행
```

## CLI 컴파일 후 실행
- openjdk11+ - class파일 없이 자동 실행
```
java javafile.java
```
- openjdk8 - class파일 생성 후 수동 실행
```
javac javafile.java
java javafile
```

## JAVA 컴파일 시 CLASSPATH 설정
```
java -classpath .;상대경로or절대경로 class파일명
```
먼저 .은 현재 폴더이고 ;으로 구분하여 경로를 추가한다   
실행 할 때 마다 classpath를 지정해주면 불편하니 환경변수에 "CLASSPATH=경로"을 등록해두면 자동 참조된다   
하지만 이 역시 규모가 커지면 불편하니 보통 패키지를 사용한다

## 주석
```java
//int j = 0;
/*
...
*/
```
주석에서 //은 한줄 주석이고 /* */은 여러줄 주석이다   
vscode단축키: ctrl + /(윈도우), cmd + /(맥)   여러줄일 경우 블록지정하여 사용한다

## 표기법
자바에서 변수명과 함수명은 camelCase, 상수명은 모두 대문자에 SNAKE_CASE, 클래스명은 PascalCase, 패키지명은 모두 소문자를 사용한다
