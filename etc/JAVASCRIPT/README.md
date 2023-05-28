# JAVASCRIPT

## 기본형태
```html
<!DOCTYPE html>
<html lang="ko">
<head>
    <meta charset="UTF-8">
    <title>Document</title>
    <script>
        document.write('자바스크립트 head에 위치<br>');
    </script>
</head>
<body>
    <p> 본문 작성 </p>
    <script>
        document.writeln('자바스크립트 body에 위치');
    </script>
</body>
</html>
```
html이 로딩 될 때 자바스크립트를 가장 먼저 실행시킬꺼면 head태그 안에 작성하고 body에서 자바스크립트를 실행시키고 싶으면 body태그 안 가장 마지막에 작성해야 사용자가 느낄 때 페이지 로딩 속도를 높일 수 있다   

## 자바스크립트 파일로 로딩
```html
<script src="js_file_location.js"></script>
```
script태그 안에 src를 이용하여 자바스크립트 파일을 호출한다   

## 렌더링
렌더링은 html, css, js 등 개발자가 개발한 문서가 브라우저에 출력되는 과정을 말하고 브라우저마다 각자의 렌더링 엔진이 있다   

## 주석
```javascript
//<script src="js_file_location.js"></script>
/*
...
*/
```
주석에서 //은 한줄 주석이고 /* */은 여러줄 주석이다   
vscode단축키: ctrl + /(윈도우), cmd + /(맥)   여러줄일 경우 블록지정하여 사용한다   

## 표기법
자바스크립트에서 변수명과 함수명은 camelCase, 클래스명과 생성자명은 PascalCase를 사용한다   
