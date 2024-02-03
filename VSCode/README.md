# VSCode {: .text-center}
Visual Studio Code

## 목차
[template 자동 적용](#template-자동-적용)

---

## Links
[Visual Studio Code Homepage](https://code.visualstudio.com/)
[Visual Studio Code Keyboard Shortcuts for Windows](https://code.visualstudio.com/shortcuts/keyboard-shortcuts-windows.pdf)
[Visual Studio Code Keyboard Shortcuts for macOS](https://code.visualstudio.com/shortcuts/keyboard-shortcuts-macos.pdf)


## Keyboard Shortcuts
- 모든 단축키 : `Ctrl + K + S`
- Settings : `Ctrl + ,` (오른쪽 상단에 Settings.json file open으로 좀 더 다양한 커스터마이징 가능)
- Sidebar : `Ctrl + B`
- Terminal : `Ctrl(Control) + Shift + `` (백틱, 틸트, 템플릿리터럴)
- Command palette : `Ctrl + Shift + P, F1`
- 동시 선택 : `Ctrl + D` (2번 입력, `Ctrl + Shift + D`와 같은 역할)
- 동시 수정 / 커서 확장 : `Ctrl` + `Alt` + `방향키(상, 하)`, `Alt + Click`, `Alt + Shift + Drag`, `Alt + Shift + i`
- Quick Open : `Ctrl + P`
- 문장의 양 끝 : `Home` / `End`
- 코드의 양 끝 : `Ctrl + Home` / `Ctrl + End`
- 복사 / 붙여넣기 : `Ctrl + C` / `Ctrl + V` / `Alt + 방향키(위, 아래)`
- 단어 복사 : `Ctrl + Shift + 방향키(위, 아래)`
- 주석 : `Ctrl + /`
- 들여쓰기 / 내어쓰기 : `Ctrl + [` / `Ctrl + ]`, `tab`, `shift + tab`
- 한 줄 삭제 : `Shift + Del`
- 파일 생성 : `Ctrl + N`

## Code Snipets
`Ctrl` + `P`로 명령 팔레트를 열고 `>snippet` 이라고 입력 후 원하는 언어를 선택
### html.json example
```json
{
	"Print to console": {
		"prefix": "htmlko",
		"body": [
			"<!DOCTYPE html>",
			"<html lang=\"ko\">",
			"<head>",
			"    <meta charset=\"UTF-8\">",
			"    <meta http-equiv=\"X-UA-Compatible\" content=\"IE=edge\">",
			"    <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">",
			"    <title>$1</title>",
			"</head>",
			"<body>",
			"	$2",
			"</body>",
			"</html>"
		],
		"description": "한국어 페이지용 html 템플릿"
	}
}
```
### python.json example
```json
{
	"Print to console": {
		"prefix": "def",
		"body": [
			"def solution($1):",
			"    return $2"
		],
		"description": "function 제작"
	}
}
```

## Definition Preview Hover
마우스를 함수에 오버하면 툴팁처럼 힌트를 줌
- 윈도우에서는 Ctrl + k i (컨트롤을 누른 상태에서 k랑 i를 이어서 누르기)
- 맥에서는 커맨드 + k i (커맨드를 누른 상태에서 k랑 i를 이어서 누르기)

## Extensions
- prettier : 자동 정렬
- Material Icon : 아이콘 꾸미기
- Material Theme : 테마 꾸미기
- Visual Studio IntelliCode : 자동완성
- auto rename tag : 태그 닫기 자동 수정
- font awesome auto-complete : 폰트 어섬 아이콘을 실시간으로 미리 보여줌
- html css support : css에서 자동 확인해서 자동완성
- pylance : python 인텔리젼스
- flake8 : python 표준 코딩 가이드 PEP8 검사기
- indent-rainbow : 들여쓰기마다 색 다르게
- htmltagwrap : html text를 wraping 하는 기능, 원하는 택스트 선택 후 Alt + W  -> 기본 p 태그로 감쌈
- auto close tag : 자동으로 태그 닫음
- Trailing Spaces : 불필요한 공백을 강조 및 삭제
- eslint : airbnb에서 정의한 자바스크립트 규칙
- print : 코드를 프린터로 출력
- Gitmoji : git 이모지

## template 자동 적용
1. Extensionsd에 Better Jinja 설치
2. ctrl + shift + p 를 누른 후 Open Workspace Settings (JSON)을 클릭 후 적용
```json
"settings": {
    "files.associations": {
        "*.html": "jinja-html"
    }
}
```

---
