# Flask
Flask는 파이썬으로 작성된 마이크로 웹 프레임워크이고, Werkzeug 툴킷과 Jinja2 템플릿 엔진에 기반을 둔다.

## 설치
```bash
pip install flask flask-sqlalchemy flask-migrate flask-login flask-wtf python-dotenv email-validator
```

## 인증서 만들기
```bash
openssl req -newkey rsa:4096 -x509 -sha256 -days 365 -nodes -keyout key.pem -out cert.pem
```
## 환경 파일
### .flaskenv
```
FLASK_APP=flask.py
FLASK_DEBUG=1 # 1이면 on, 0이면 off
```
플라스크 전용 환경 파일

### .env
```
SECRET_KEY=
FLASK_APP=
FLASK_DEBUG=1
MS_TRANSLATOR_KEY=
MAIL_SERVER=localhost
MAIL_PORT=8025
SQLALCHEMY_DATABASE_URL=mysql+pymysql://<id>:<password>@localhost:3306/<db-name>
```
배포용 환경 파일

## cli 옵션
프로젝트의 root 위치에서 실행해야 한다.  
`flask run` : 기본 실행
`flask run --host=0.0.0.0 --port=5000` : ip와 port를 설정해서 실행
`flask run --debug` : 디버그 모드로 실행 (파일 저장시 auto reloading)
`flask shell` : 현재 플라스크 환경을 가져와 파이썬 쉘을 실행
`flask db init` : db 초기 구성
`flask db migrate -m "tagname"` : Model 변경사항을 적용
`flask db upgrade` : migrate 한 것을 DBMS에 적용
`flask db downgrade` : 이전 migrate로 복귀

## gunicorn 옵션
```bash
gunicorn -b 0.0.0.0:80 -w 2 flaskfile:app
```

## flask code
### json
jsonify 이용
```python
from flask import jsonify, request

@app.route('/', methods=['GET'])
def index():
    req = request.get_json() #request에서 json을 디코딩해서 dict으로 만듬
    res = {"key": "value ok"}
    return jsonify(res) #dict 타입을 json으로 인코딩 해서 반환
```

### g
flask의 전역 데이터를 사용할 수 있는 공간
```python
from flask import g
g.search_form = SearchForm() #g(global)의 공간에 search_form변수를 할당해 SearchForm()을 참조
```

### request.args.get
```python
from flask import request
request.args.get('page', 1, type=int) #.get(http get의 내용, 내용이 없으면 이것, 타입 선택)
```
