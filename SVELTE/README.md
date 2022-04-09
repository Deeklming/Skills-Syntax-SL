# SVELTE
svelte는 프런트엔드의 자바스크립트 프레임워크이다   
svelte는 Frameworks without the framework(프레임워크가 없는 프레임워크)이다   
즉, 프레임워크의 전용 문법을 최소화 한 것이다   

## 기본형태
```html
<script>
export let i;
</script>

<main>
<h2>markup {i}!</h2>
</main>

<style>
main{
    text-align: center;
}
h2{
    color: #123123;
    font-size: 10em;
}
</style>
```
script, main, style은 순서에 상관없이 배치가능하다   

## 특징
1. Write less code
2. No virtual DOM
3. Truly reactive
