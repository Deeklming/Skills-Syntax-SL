# NODEJS
nodejs는 v8엔진으로 만들어진 자바스크립트용 런타임이다   

## 기본형태
```javascript
console.log("node");
```

## 버전확인
```
node -v
```

## 특징
nodejs는 기본적으로 비동기적 처리를 한다   
nodejs는 Single Thread(싱글 스레드)를 사용하고 Event Loop(이벤트 루프)를 사용한다   
이벤트 루프는 새로운 이벤트가 없는지 계속 검사하고 있고 새로운 이벤트가 생기면 작업 스레드에게 그 이벤트를 맡기고 다시 새로운 이벤트가 없는지 검사한다   

## 주석
```javascript
//<script src="nodejs_file_location.js"></script>
/*
...
*/
```
주석에서 //은 한줄 주석이고 /* */은 여러줄 주석이다   
vscode단축키: ctrl + /(윈도우), cmd + /(맥)   여러줄일 경우 블록지정하여 사용한다   

## 표기법
자바스크립트에서 변수명과 함수명은 camelCase, 클래스명과 생성자명은 PascalCase를 사용한다   
