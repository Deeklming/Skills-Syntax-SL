# JSON
JSON(javascript Object Notation)은 데이터를 저장하거나 전송할 때 많이 사용되는 경량의 데이터 교환 형식을 의미함

## 특징
1. 자바스크립트 객체 표기법을 따름
2. 독립적이라 다른 것에 종속되지 않음
3. XML보다 빠르고 BSON(binary JSON)의 바이너리 형태도 존재
4. 계층적인 데이터 구조를 가짐
5. 주석 없음

## 형태
```json
{
    "First" : "AA",
    "Second" : [
        { "B" : "b" , "BB" : 987 },
        { "C" : 123 }
    ],
    "Third" : true,
    "Fourth" : null
}
```
key-value 형식의 데이터

## 표기법
- key값이나 문자열은 항상 ""로 표기
- 객체, 배열 등의 표기를 사용할 수 있음
- JSON형식에서는 null, number, string, array, object, boolean을 사용할 수 있음
- 원하는 만큼 중첩시켜서 사용가능
