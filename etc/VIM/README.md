## Vim(vi)사용법
```
vi(m) [filename] 파일명으로 파일 열기
vi(m) (+)-[row number] [filename] 파일명으로 파일 열고 행번호로 커서이동
vi(m) (+)-/["string"] [filename] "문자열"의 처음발생 단어부터 열기
vi(m) -r [filename] 손상된 파일 회복
view [filename] 읽기 전용으로 열기
```

## command mode - esc 다른모드 사용후 명령모드로 이동
### 이동
```
h 좌
j 하
k 상
l 우
w 다음 단어의 끝부분으로 이동
e 다음 단어의 앞부분으로 이동
b 이전 단어의 첫글자로 이동
G 마지막 행으로 이동
ENTER 하
BACK SPACE 좌
SPACE BAR 우
^ 행의 처음으로 이동
$ 행의 끝으로 이동
H 화면의 맨 위로 이동
M 화면의 중간으로 이동
L 화면의 맨 아래로 이동
[number]G 숫자만큼 지정한 행으로 이동
CTL+i 한 화면 위로 이동
CTL+b 한 화면 아래로 이동
CTL+d 반 화면 위로 이동
CTL+u 반 화면 아래로 이동
CTL+e 한 줄씩 위로 이동
CTL+y 한 줄씩 아래로 이동
```

### 삭제 - 숫자는 갯수, 삭제된 내용은 버퍼에 저장되어 붙여넣기 가능
```
x 커서에 있는 글자 삭제
X 커서 앞에 있는 글자 삭제
[number]dw 커서포함 뒤에있는 단어 삭제
[number]db 커서 앞에있는 단어 삭제
[number]dd 행 삭제 ex) 2dd
```

### 복사 - 숫자는 갯수
```
[number]yw 커서포함 뒤에있는 단어 복사
[number]yb 커서 앞에있는 단어 복사
[number]yy 행 복사 ex) 3yy
```
### 붙여넣기
```
p 커서 뒤에 붙여넣기
P 커서 앞에 붙여넣기
```

### 찾기
```
/[string] 앞에서부터 문자열을 찾음
?[string] 뒤에서부터 문자열을 찾음
n 커서 뒤로검색
N 커서 앞으로 검색
```

### 되돌리기재실행
```
u 이전으로 되돌리기(Undo)
CTL+r 되돌리기한것을 재실행
```

## insert mode
```
i 현재위치한 커서부터 입력모드
a 현재에서 다음 위치한 커서부터 입력모드
```

## colon mode
### 저장종료이동
```
:q 종료
:q! 강제종료
:w 저장
:wq 저장후종료
:wq [filename] 파일이름으로 저장후 종료
:[number] 지정한 숫자행으로 이동
```

### 바꾸기
```
:%s/target/new 각 행의 처음나오는 target을 찾아 new로 변경
:%s/target/new/g 모든 행의 target을 찾아 new로 변경
:%s/target/new/gc 모든 행의 target을 찾아 new로 변경전에 물어봄
```

### 기타기능
```
:set number 행번호 출력, :set nu 같은기능
:set number 행번호 숨김, :set nonu 같은기능
:cd 현재 디렉토리 출력
```
