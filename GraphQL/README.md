# GraphQL

GraphQL은 데이터 질의어이다

## 특징

1. 독립적이라 다른 것에 종속되지 않음
2. REST API의 문제점인 Overfetching과 Underfetching을 해결함
3. 필요한 정보만 가져오기 때문에 성능 향상과 경제적인 효과를 가짐

## 형태

```graphql
type Query{
    a: Number!
}
```

## 표기법

- key값이나 문자열은 항상 ""로 표기
- 객체, 배열 등의 표기를 사용할 수 있음
- JSON형식에서는 null, number, string, array, object, boolean을 사용할 수 있음
- 원하는 만큼 중첩시켜서 사용가능
