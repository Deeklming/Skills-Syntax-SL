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
혼합으로 사용 가능
#### Check Lists
```md
- [x] complete A
- [ ] incomplete B
```
x로 완료 표시

### Backslash Escapes (역슬레쉬, 특수문자표시)
```md
\*
\#
\-
```
특수문자를 표현하고 싶을 때 표시될 문자 앞에 \를 넣으면 됨

### Links, Anchor (링크)
#### 외부 링크
```md
[링크 이름](image_url "추가 텍스트")
www.google.com
주소 <www.google.com>
<abc@gmail.com>
```
외부 링크: [텍스트](image_url "추가 텍스트")
이메일: <abc@gmail.com>
#### 내부 링크
```md
[1. Headers (제목)](#Headers-(제목))
```
내부 링크: [내용](#이동할 곳)   
영어는 모두 소문자로 작성하고 괄호 안의 링크를 쓸 때 띄어쓰기는 -로 연결

### Image (사진)
```md
![텍스트추가](/image.png)
![텍스트추가](image_url)
![텍스트추가](/image.png "커서의 텍스트")
![텍스트추가](image_url "커서의 텍스트")
[![텍스트추가](image_url)](link_url)
<img src="image_url" width="50" height="50" />
<a href="#">
  <img src="image_url" width="50px" alt="alt text">
</a>
```
링크 같은 문법 앞에 !가 있음   
인라인 이미지: ![alt text](/image.png)   
링크 이미지: ![alt text](image_url)   
이미지를 링크로 사용: [![alt text](image_url)](link_url)   
이미지의 사이즈를 변경하려면: img 태그 이용

### Code Block (코드 블럭)
```md
(basic) ```
  내용
(basic) ```

(language) ```python
  print("py")
(language) ```
```
인라인 코드는 텍스트를 앞뒤로 `(backtick) 3번으로 감싸면 됨

### Table (표)
```md
헤더1|헤더2|헤더3|헤더4
---|---|---|---
셀1|셀2|셀3|셀4
셀5|셀6|셀7|셀8
셀9|셀10|셀11|셀12

헤더1|헤더2|헤더3
:---|:---:|---:
Left|Center|Right
1|2|3
4|5|6
7|8|9
```
헤더와 셀을 구분할 때 3개 이상의 -(hyphen/dash) 기호가 필요   
헤더 셀을 구분하면서 :(Colons) 기호로 셀(열/칸) 안에 내용을 정렬   
가장 좌측과 가장 우측에 있는 |(vertical bar) 기호는 생략 가능
