# KOTLIN

## 기본형태
```kotlin
package com.example.test

import java.util.*

fun main(){
    var data1=1
    val data2=2
    println("kotlin")
}
```
확장자명은 .kt 또는 .kts이다   

## 환경변수 설정
```
JAVA_HOME = jdk_folder_path
PATH = JAVA_HOME/bin - windows(%JAVA_HOME%), linux($JAVA_HOME, 끝에 /:$PATH 붙임)
CLASSPATH = JAVA_HOME/lib - windows(%JAVA_HOME%), linux($JAVA_HOME, 끝에 /:$CLASSPATH 붙임)
PATH = kotlin_folder/bin
```
자바8+ 버전이 미리 설치되어 있어야 한다   

## CLI 컴파일 후 실행
- openjdk8+
```
kotlinc kotlinfile.kt -o kotlinfile.exe
./kotlinfile.exe
```

## 주석
```kotlin
//int k = 0;
/*
...
*/
```
주석에서 //은 한줄 주석이고 /* */은 여러줄 주석이다   
vscode단축키: ctrl + /(윈도우), cmd + /(맥)   여러줄일 경우 블록지정하여 사용한다

## 표기법
코틀린에서 변수명과 함수명은 camelCase, 상수명은 모두 대문자에 SNAKE_CASE, 클래스명은 PascalCase, 패키지명은 모두 소문자, 안드로이드의 리소스는 snake_case를 사용한다
