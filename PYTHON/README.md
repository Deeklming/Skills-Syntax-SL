# PYTHON
## Links
[PYTHON Homepage](https://www.python.org/)
[PyPI (The Python Package Index)](https://pypi.org/)

## 기본형태
```python
print("python!")
```

## Language Version
Python 3.11+

## Compiler
cpython(interpreter)

## CLI Compile and Run
### Windows
```
python pyfile.py
```
### Linux, macOS
```
python3 pyfile.py
```

## Language Feature
개발 속도가 빠른 인터프리터(스크립트) 언어이자 거의 모든 플랫폼에서 동작하는 언어임
### GIL (Global Intepreter Lock)
하나의 스레드에 모든 자원을 허락하고 나머지 스레드에 락을 걸어 다른 스레드가 실행되지 않도록 막아버리는 기능으로 멀티 코어 작업이 불가능함
### comments (주석)
```python
# py = 0;
"""
...
"""
```
\#: 한줄 주석   
""" """: 문서화 주석
### 표기법
변수와 함수명: camelCase   
상수명: SCREAMING_SNAKE_CASE   
클래스명: PascalCase   
패키지명: all lower
