# RUST
## Links
[RUST Homepage](https://www.rust-lang.org/)
[crates.io (The Rust community’s crate registry)](https://crates.io/)

## Basic Form
```rust
fn main() {
    println!("rust!");
}
```

## Language Version
Rust 1.56+

## Compiler
rustc(llvm), cargo(build system and package manager)

## CLI Compile and Run
### rustc
#### Windows
```
rustc rustfile.rs
./rustfile.exe
```
#### Linux, macOS
```
rustc rustfile.rs
./rustfile
```
### cargo
```
cargo build : rust 빌드
cargo run : rust 빌드 후 자동 실행
cargo check : 실행 파일 생성하지 않고 rust 빌드
```
cargo는 해당 파일 위치로 가서 실행
 
## Language Feature
Rust는 안정적이고 매우 빠르며 효율적인 소프트웨어를 구축할 수 있음   
### Ownership (소유권)
GC(Garbage Collection) 없이 메모리를 관리하는 기법
### comments (주석)
```rust
//let rs = 0;
/*
...
*/
/**
...
*/
/*!
...
*/
/// ...
//! ...
```
//: 한줄 주석   
/\* \*/: 여러줄 주석   
/\*\* \*/: 외부 항목 대상 블록 문서화 주석   
/\*! \*/: 내부 항목 대상 블록 문서화 주석   
///: Rustdoc 외부 문서화(Outer Documentation) 주석, 마크다운 사용 가능, 코드 테스트 용도로 사용 가능   
//!: Rustdoc 내부 문서화(Inner Documentation) 주석, 주석에 달린 파일(주로 Crate)을 설명할 때 사용
### 표기법
지역변수, 함수, 메소드, 모듈명: snake_case   
매크로명: snake_case!   
타입, 트레잇, 열거형명: UpperCamelCase   
상수, 정적변수명: SCREAMING_SNAKE_CASE   
라이프타임명: 'short lower
