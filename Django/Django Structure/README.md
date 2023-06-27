# Django Structure
Django Project File Structure

## 프로젝트 구조
```
Django Project
│  manage.py
│  
├─app1
│  │  admin.py
│  │  apps.py
│  │  models.py
│  │  tests.py
│  │  views.py
│  │  __init__.py
│  │
│  └─migrations
│          __init__.py
│
├─app2
│  │  admin.py
│  │  apps.py
│  │  models.py
│  │  tests.py
│  │  views.py
│  │  __init__.py
│  │
│  └─migrations
│          __init__.py
│
├─django_project
│  │  asgi.py
│  │  settings.py
│  │  urls.py
│  │  wsgi.py
│  └─ __init__.py
│
├─media
├─static
└─templates
```
### django_project
`django_project` 폴더는 django로 만들어진 애플리케이션의 기본적인 세팅을 담당하는 파일들로 이루어져 있음
- `settings.py`: 데이터베이스 정보, 설치된 앱, 미들웨어 등 프로젝트의 기본적인 설정 정보를 포함하는 파일
- `urls.py`: 프로젝트의 URL 패턴을 포함하고 요청과 응답을 처리하는 View와 대응됨
- `wsgi.py`: 웹 서버에 배포하기 위해 사용하는 파일로 애플리케이션을 실행하기 위한 WSGI 호환 인터페이스를 제공함
- `init.py`: 이 파일이 존재하는 디렉토리가 패키지로 처리되어야 함을 나타내는 파일
### manage.py
`manage.py` 파일은 프로젝트를 관리할 때 사용하는 커맨드 라인 인터페이스로써 이 파일을 이용해 데이터베이스 마이그레이션, 애플리케이션 서버 실행 등 다양한 작업을 수행할 수 있음   
파일은 프로젝트 폴더의 root 디렉토리에 위치