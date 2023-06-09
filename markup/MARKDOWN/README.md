# MARKDOWN
마크다운(Markdown)은 일반 텍스트 기반의 경량 마크업 언어이자 웹 사이트, 문서, 메모, 기술 문서 등으로 사용됨

## 확장자명
.md, .markdown

## 특징
1. HTML삽입이 가능하지만 모든 문법을 대신 못함
2. 작성한 문서의 표현 방식은 CSS의 설정에 따라 달라짐
3. 지원하는 플랫폼이 많음

## 문법
### Headers (제목)
```md
# H1 1
## H2 2
### H3 3
#### H4 4
##### H5 5
###### H6 6
```
H1은 ===, H2는 ---로도 만들 수 있음

### Horizontal Rules (선)
```md
* * *
***
*****
- - -
----
```
각 문자를 3개 이상 작성하되 -을 사용할 경우 header로 인식할 수 있으니 전 라인은 비워둬야 함

### Emphasis (강조)
```md
_be italic_
**be bold**
~~be canceled~~
_**abc** ~~def~~_
```
italic(기울이기): * 또는 _로 감싼 텍스트   
bold(두껍게): ** 또는 __로 감싼 텍스트   
cancel line(취소선): ~~로 감싼 텍스트   
※ italic과 bold를 같이 사용할 수 있음

### Line Breaks (줄바꿈)
```md
<br>
   
```
띄워쓰기 3번으로 가능

### Blockquotes (인용)
```md  
> A
> > B
> > > C
```
\>는 최대 3번까지만 가능   
인용구 안에는 제목이나 리스트, 텍스트박스 등도 넣을 수 있음

### Lists (목록)
#### Unordered lists
```md
* A
  * B
    * C

+ A
  + B
    * C
      * D

- A
- B
- C
```
*, +, - 를 이용해서 순서가 없는 목록을 만들 수 있음
#### Ordered lists
```md
1. A
2. B
3. C
5. D
```
위에서 5.을 썻는데도 4.으로 표시됨
##### Ordered lists in Ordered lists
```md
1. A-1
    1. A-2
2. B
3. C-1
    1. C-2
    2. C-3
```
tab과 함꼐 숫자 1.부터 나열해야 적용됨
#### Mix lists
```md
1. A
   * B
   * C
      + D
2. E
   - F
   - G
      1. H
```
