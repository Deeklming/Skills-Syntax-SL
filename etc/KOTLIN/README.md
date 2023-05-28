# KOTLIN

## Kotlin Preparation
1. kotlin command-line 페이지에서 설치
2. 환경변수 설정 후 kotlinc-jvm -version && kotlinc-native -version 확인
3. jvm의 경우 kotlinc-jvm Filename.kt -d Filename.jar && java -jar Filename.jar 컴파일 후 실행
4. kotlin [-classpath] Filename.jar [FilenameKt]로도 실행가능
5. native의 경우 kotlinc-native -o Filename.exe Filename.kt 컴파일

## 기본형태
### .kt
```kotlin
fun main() = println("kotlin pursues expressions.")
```
```kotlin
package com.example.test

import java.util.*

fun main(){
    var data1=1
    val data2=2
    println("kotlin")
}
```
### .kts
kotlin을 bash나 python같은 스크립트로 사용하고싶으면 확장자를 .kts로 만들어 사용하면 됨
```kotlin
fun errCalled(){
    println("called...")
    throw RuntimeException("oops")
}

try{
    errCalled()
}catch(e: Exception){
    val stackTrace = e.getStackTrace()
    println(stackTrace[0])
    println(stackTrace[1])
}

Thread.sleep(1000)
println("ok")
```
- kotlinc-jvm -script Filename.kts
- 경고를 오류처럼 강하게 제한을 거는 방법은 kotlinc-jvm -Werror -script Filename.kts

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
