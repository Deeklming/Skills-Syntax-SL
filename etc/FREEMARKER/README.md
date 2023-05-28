# freemarker
## 중요
- 절대 사용하지 말 것
- Never Use

### assign - 변수할당
```
    <#assign name="string">    
    <#assign codeBlock>
        this code block assigned
    </#assign>
```

### local - 지역전용변수할당, macro 디렉티브와 function 디렉티브의 안쪽에서만 사용할 수 있다는 제한
```
    <#local name=value>
    <#local name1=value1 name2=value2 ... nameN=valueN>
    <#local name>
        capture this
    </#local>
```

### attempt, recover - #attempt와 /#attempt사이는 try-catch문과 비슷, 오류가나면 attempt구문은 롤백되고 recover이 실행 됨
```
    <#attempt>
        attempt...
    <#recover>
        recover...
    </#attempt>
```

### compress - 처음과 끝의 화이트스페이스를 제거하고 2개이상의 연속된 화이트스페이스를 하나로 줄임
```
    <#compress>
    ...
    </#compress>
```

### flush - java.io.Writer 인스턴스같은 것을 강제버퍼비움
```
    <#flush>
```

### ftl - 프리마커 템플릿 파일의 제일 첫 부분에서 사용되는 디렉티브로 템플릿 파일에 대한 정보를 프리마커 엔진에 알려주는 역할
### 특정 파라미터(para1, para2, ...)의 값(value1, value2, ...)을 설정하는 디렉티브임
### 파라미터로는 'encoding', 'strip_whitespace', 'strip_text' 등이 사용될 수 있고, 값으로는 'ISO-8859-5' 같은게 사용될 수 있음
```
    <#ftl para1=value1 para2=value2 ... >
```

### function, return - 함수작성
```
    <#function name para1 para2 ... para_N>
        ...
    <#return return_value>
        ...
    </#function>
```

### global - 전역변수할당
```
    <#global name=value>
    <#global name1=value1 name2=value2 ... nameN=valueN>
    <#global name>
        capture...
    </#global>
```

### if, elseif, else - 조건문
```
    <#if condition1>
    ...
    <#elseif condition2>
    ...
    <#elseif condition3>
    ...
    <#else>
    ...
    </#if>
```

### import - 다른 템플릿 불러옴
```
    <#import "/tmp/test.ftl" as my>  -  my라는 네임스페이스를 만듬
    <@my.macro x="abc"/>
```

### include - 다른 템플릿 불러옴, import와 다르게 같은 네임스페이스로 불러들임
```
    <#include path>
    <#include path options>
```

### list, else, items, sep, break, continue - 반복문
```
    <#list sequence as item>  -  기본적인 반복문, sequence가 반복객체, item이 각 해당 변수
        ${item}  -  변수사용
    </#list>

    <#list hash as key, value>  -  hashmap값 반복
        list block here
    </#list>

    <#list sequence as item>  -  sequence에 해당하는 데이터 모델이 비어있는 경우엔 else 디렉티브의 템플릿 블럭이 실행
        Part repeated for each item
    <#else>
        Part executed when there are 0 items
    </#list>

    <#list users as user>  -  컬렉션 데이터 출력할때 , 같은 구분자를 쓰고 싶을때 사용
        ${user}<#sep>, </#sep>
    </#list>

    <#break>  -  break문
    <#continue>  -  continue문
```

### macro, nested, return - 매크로
```
    <#macro name param1 param2 ... paramN>  -  메크로변수 생성
        <#nested loopvar1, loopvar2, ..., loopvarN>  -   #macro와 /#macro 사이에 있는 템플릿 조각을 실행하는데 사용, loop변수 포함가능
        <#return>  -  매크로 종료
    </#macro>
    
    ex)
        <#macro foo>
        <#list 1..5 as i>
            <#nested i, i * 2, i/2>
        </#list>
        </#macro>

        <@foo ; first, second, thrid>
        i = ${first}
        i * 2 = ${second}
        i / 2 = ${third}
        </@foo> 
            매크로의 정의에 있는 loop 변수는 3개로 각각 i, i * 2, i / 2다.
            이 들은 사용자 정의 디렉티브에서 사용될 때, 각각 first, second, thrid라는 변수에 할당되어서 사용된다.
```

### autoesc - XML이나 HTML 같은 문서를 출력할 때, 이스케이핑 해야하는 문자들('<', '>' 등)을 사용할때 쓰임
```
    <#autoesc>
    </#autoesc>
    ${expression?esc}  -  변수 하나에 적용
```

### noautoesc - 오토 이스케이핑 기능을 사용하지 않는 구역을 만듬
```
    <#noautoesc>
    </#noautoesc>
    ${expression?no_esc}
```

### noparse - 프리마커 언어로 해석하지 않는 구역을 만듬
```
    <#noparse>
    </#noparse>
```

### nt - No-Trim의 약자. 이 디렉티브가 있는 라인은 공백 문자를 Stripping을 하지 않음

### outputformat - 출력 포맷 설정을 변경
```
    <#outputformat formatName>  -  formatname으로는 "HTML", "XML" 등이 사용될 수 있음
    </#outputformat>
```

### setting - 이후 프로세싱에 영향을 미칠 설정 값들을 변경
```
    <#setting name=value>
```

### stop - 템플릿의 프로세싱을 종료
```
    <#stop>
    <#stop reason>  -  에러메시지를 줄 수음
```

### switch, case, default, break - java의 switch문과 비슷
```
    <#switch value>
    <#case refValue1>
    ...
    <#break>
    <#case refValue2>
    ...
    <#break>
    ...
    <#case refValueN>
    ...
    <#break>
    <#default>
    ...
    </#switch>
```

### t, lt, rt - Trim
```
    <#t>  -  양쪽 공백문자 제거
    <#lt>  -  왼쪽 공백문자 제거
    <#rt>  -  오른쪽 공백문자 제거
```

### 사용자 정의 디렉티브(User-defined directive) - 매크로에서 설명한 내용과 동일, 시스템 디렉티브와 다르게 골뱅이(@) 문자로 시작함

### visit, recurse, fallback - 재귀적인 방법으로 트리를 순회하며 데이터를 처리하고 싶을 때 사용하는 디렉티브, 실제로는 XML 데이터를 다룰 때 많이 사용
```
    <#visit node using namespace> or <#visit node>  -  <#visit node>를 호출하면 node?node_name 에 해당하는 매크로를 찾아서 실행
                                                        만약 node_name에 해당하는 매크로가 없으면, @node_type 이름을 갖는 매크로를 찾아서 실행함
                                                        만약 이것도 없으면 템플릿 프로세싱은 에러를 내면서 종료

    <#recurse node using namespace> or <#recurse node> or <#recurse using namespace> or <#recurse>  -  
            <#recurse node using namespace>는 <#list node?children as child><#visit child using namespace></#list>와 동일한 동작임

    <#fallback>  -  visit 디렉티브에 의해서 사용자 정의 디렉티브가 찾아지다가
                    fallback 디렉티브를 만나면, 다른 네임스페이스에서 node?node_name에 해당하는 매크로를 찾아보도록 프리마커 엔진에게 알려줌
                    같은 이름의 매크로를 오버라이드해서 사용하는 경우 적당한 처리를 위해서 사용할 수 있음
```
