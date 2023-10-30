# GraphQL

GraphQL은 데이터 질의어이다

## 특징

1. 독립적이라 다른 것에 종속되지 않음
2. REST API의 문제점인 Overfetching과 Underfetching을 해결함
3. 필요한 정보만 가져오기 때문에 성능 향상과 경제적인 효과를 가짐

## 형태

```graphql
    type User{
        id: ID
        username: String
    }
    type Message{
        id: ID
        text: String
        author: User
    }
    type Query {
        allTweets:[Message]
        msg(id: ID!): Message
    }
    type Mutation{
        postMessage(text: String!, userId: ID!): Message!
        deleteMessage(id: ID!): Boolean!
    }
```

## 표기법

- type과 {}를 사용함

## 정보

- type Query는 rest api의 get에 해당하고 type Mutation은 rest api의 post, put, delete에 해당 함
- 기본적으로 nullable이고 !를 붙이면 non-nullable(required)이 됨
