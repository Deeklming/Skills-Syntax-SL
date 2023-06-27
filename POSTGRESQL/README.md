# POSTGRESQL
## Links
[POSTGRESQL Homepage](https://www.postgresql.org/)
[PostgreSQL 위키](https://ko.wikipedia.org/wiki/PostgreSQL)

## DBMS Version
PostgreSQL 14.8+

## Basic Port
5432

## PostgreSQL Feature
1. 최대한 SQL 표준 지원
2. 다양한 데이터 유형 지원
3. 빅데이터 처리에 유용

## PostgreSQL Commands
### access
```
접속 : psql -U postgres -d userName
접속 + 비밀번호 : PGPASSWORD=password psql -U postgres -d userName
원격 접속 : psql -h 127.0.0.1 -U postgres -d userName
원격 접속 + 비밀번호 : PGPASSWORD=password psql -h 127.0.0.1 -U postgres -d userName
```
### commands
```
psql -? : 옵션 목록 및 도움말을 확인
\l or \list + : 데이터베이스 목록, +를 붙여 자세한 내용 확인 가능
\d or \dt + : 테이블, 인덱스, 시퀀스, 뷰 목록, +를 붙여 자세한 내용 확인 가능
\d [table] : 해당 테이블의 정보 (컬럼 목록)
\di : 인덱스 목록
\ds : 모든 시퀀스 정보
\df : 모든 함수 정보
\dv : 모든 뷰 테이블 정보
\dg or \du : 등록된 사용자 권한 정보 목록
\dn : 스키마 목록
\dS : 시스템 테이블 목록
\c or \connect + [database] : 다른 데이터베이스에 접속
\c [database] [user] : 다른 데이터베이스에 지정한 사용자로 접속
\h : 간단한 구성의 SQL 사용법 확인
\e : psql.edit 파일을 열어 query를 수정하고 실행가능하게 함
\q : psql 종료
```
