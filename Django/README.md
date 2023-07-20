# Django
Python Open Source Web Framework

## Links
[Django Homepage](https://www.djangoproject.com/)
[Django Documentation ko 4.2](https://docs.djangoproject.com/ko/4.2/)
[Django gitignore](https://github.com/jpadilla/django-project-template/blob/master/.gitignore)

## Django Feature
- **MTV 패턴**: Model-Template-View 패턴을 가지고 있어서 기능들을 분리하여 개발할 수 있음
- **ORM(Object-Relational Mapping)**: 데이터베이스와의 상호작용을 자동화하여 개발자가 SQL 쿼리를 작성할 필요없이 데이터를 편리하게 다룰 수 있음
- **Admin 페이지**: 기본적인(CRUD, Create-Read-Update-Delete) 기능이 갖춰진 관리자 페이지를 자동으로 생성함
- **보안**: 취약점 테스트를 통해 안정성이 검증된 보안 기능을 제공함

## MTV Pattern
1. **Model**: 데이터베이스와 상호작용을 하는 컴포넌트
2. **Template**: 사용자에게 보여지는 HTML, CSS, JS 등
3. **View**: HTTP 요청 처리 및 Model과 Template 연결

## Django Preparation
1. 새로운 폴더 생성후 이동
2. python -m venv venvName : 가상환경 생성
3. venvName의 Scripts에서 activate로 가상환경 실행, deactivate로 빠져나올 수 있음
4. python -m pip install django : 장고 설치
5. django-admin startproject projectName . : 프로젝트 생성, .은 현재 폴더
6. 환경변수 설정하면 편함
- Windows bat
```bat
@echo off
cd 프로젝트 폴더 경로
가상환경의 activate 경로
```
- Windows powershell
```powershell
Set-Location 프로젝트 폴더 경로
가상환경의 activate 경로
```
7. 프로젝트 생성 후 기본 폴더 구조
```
새로운 폴더/
    projectName/
        __init__.py
        asgi.py
        settings.py
        urls.py
        wsgi.py
    manage.py
```
8. 프로젝트 기본 실행
```
python manage.py migrate : 현 장고 프로젝트에 설정 및 구조로 적용(이동)
python manage.py runserver (port or ip:port) : 서버 실행, ()안에 직접 적용 가능
```

## Django Commands
### django-admin
```
프로젝트 생성 : django-admin startproject [project name] (위치)
```
### manage.py
```
앱 생성 : python manage.py startapp [app name]
models 변경사항 적용 : python manage.py makemigrations (app name)
models 수정 후 데이터 매핑 : python manage.py migrate (app name) (migration name)
admin 생성 : python manage.py createsuperuser
서버 실행 : python manage.py runserver (port | ip:port) (&)
migration 적용 내역 보기 : python manage.py showmigrations (app name)
백업 : python manage.py dumpdata
로드 : python manage.py loaddata
table 삭제 : python manage.py flush
```
& : 백그라운드에서 실행
### manage.py
```
pip freeze > requirements.txt  // requirements.txt 생성 명령어
pip install -r requirements.txt // install 명령어
```
현재 pip에 설치된 환경 공유

## Basic Django Development Order
`function design` -> `Models` -> `URLs` -> `Views`
