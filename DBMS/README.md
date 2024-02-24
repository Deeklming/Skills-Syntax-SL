# DBMS

## PostgreSQL

## Redis

---

## RDB ERD example
[dbdiagram.io](https://dbdiagram.io/home)
```
Table users {
  id uuid [primary key]
  email varchar [not null, unique]
  nickname varchar [not null, unique]
  password char [not null]
  password_last json [not null, note: '{last pw:updated at}']
  image varchar [null]
  body text [null]
  follows json [not null]
  likes json [not null]
  hashtags json [PK, not null]
  updated_at timestamp [not null]
  created_at timestamp [not null]
  deleted_at timestamp [null]
  status bool [not null]
}

Table posts {
  id integer [primary key, increment]
  author varchar [PK]
  title varchar [not null]
  content text [not null]
  images json [null]
  view_cnt integer [not null]
  like_cnt integer [not null]
  hashtags json [PK, not null]
  updated_at timestamp [not null]
  created_at timestamp [not null]
  public bool [not null]
}

Table comments {
  id integer [primary key, increment]
  post_id integer [PK]
  author varchar [PK]
  comment_id integer [null]
  content text [not null]
  like_cnt integer [not null]
  created_at timestamp
  public bool
}

Table tags {
  id integer [primary key, increment]
  tag varchar [not null]
  note varchar [null]
}

Ref: users.nickname < posts.author
Ref: users.nickname < comments.author
Ref: posts.id < comments.post_id
Ref: comments.id < comments.comment_id
Ref: tags.tag < users.hashtags
Ref: tags.tag < posts.hashtags
```

## NoSQL Data Modeling example
```
Session
Login Fail Info (count, at)
```
