# Settings
project/settings.py

## settings.py
프로젝트의 설정을 정의함
### 경로 상수
```python
BASE_DIR = PATH(__file__).resolve().parent.parent
```
`BASE_DIR` 상수는 프로젝트의 최상위 디렉토리를 의미해서 다른 경로들을 계산하는 데 유용함
### 보안 설정
```python
SECRET_KEY = os.environ.get('SECRET_KEY')
```
`SECRET_KEY`는 Django 프로젝트에서 중요한 보안 설정으로서 프로젝트에서 사용하는 모든 보안 기능에서 사용되며, 공개되면 보안상의 위험이 큼   
그래서 일반적으로 `SECRET_KEY`는 환경 변수로 설정하고 코드에서는 이 값을 가져와 사용함
