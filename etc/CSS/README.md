# CSS
CSS(Cascading Style Sheets)는 웹 페이지의 전반적인 스타일을 작성해 저장해두는 파일을 의미함

## 특징
1. CSS 2.1 개발이 완료되고 CSSWG(CSS Working Group)는 더 이상 CSS의 버전을 3, 4와 같은 메이저 업데이트로 가져가지 않기로 결정함
2. 브라우저 제작사들마다 각각 브라우저가 제공하는 요소의 기본 스타일이 모두 다름

## 기본형태
```css
p {
    color: red;
}
#one{
    color: blue;    
}
.container {
    display: flex;
    flex-direction : row;
}
```

## 우선순위
1. 사용자 정의 스타일 (가장 높은 우선 순위) - 삭제 예정
2. 태그 안에서 작성되는 inline 스타일
3. head 태그 안의 스타일
4. 개발자가 작성하는 외부 스타일 (가장 낮은 우선 순위)

## 공백처리
```css
h1 {color: black;}
h1 {
    color: black;
}
h1 {
    color : black;}
h1 {
    border: solid 1px black;
}
h1 {
    border: 
        solid 
        1px 
        black;
}
h1 {
    border: 
        solid 
        1px 
        black
    ;
}
```

## 벤더프리픽스(Vendor-Prefix)
Vendor : 브라우저 제조사   
Prefix : 접두어
```css
-webkit-transition: all 4s ease; /* 웹킷 기반 */
-moz-transition: all 4s ease;
-ms-transition: all 4s ease;
-o-transition: all 4s ease; /* 레거시 오페라 */
transition: all 4s ease;
```
아직 비표준이거나 실험적인 CSS 속성을 특정 브라우저에서 실행할 수 있도록 CSS 속성 앞에 브라우저 제조사 만의 접두어(prefix)를 붙이는 문법   
**벤더 프리픽스는 점점 줄어들고 있음**

## 주석
```css
/* 한 줄, 여러 줄 모두 이렇게 사용합니다. */
```

## 표기법
- CSS에서 속성과 값의 짝을 선언(Declaration)이라고 부름
- 셀렉터 뒤에 {}(중괄호) 안에 있는 한 블록, 덩어리를 보통 선언 블록(Declaration block)이라고 부름
- 선언 블록 내부의 다른 선언과 ;(세미콜론)으로 구분

## 참고 및 학습
https://developer.mozilla.org/ko/docs/Web/CSS
