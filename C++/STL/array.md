# array

```c++
#include <iostream>
#include <array>//array객체 import

using namespace std;

template <size_t N>
void arrpr(const array<int, N>& ar);

int main(){
    //기본
    std::array<int, 5> arr1;//array객체 선언 방식
    arr1[0] = 5;//[]연산자 사용 가능
    cout<<arr1[0]<<endl;
    cout<<"arr1 size: "<<arr1.size()<<endl;//array 객체 크기 구하기
    array<int, 3> arr2 = {1,2,3};//array객체 초기화 선언 방식
    for(auto i: arr2) cout<<i<<endl;

    try{//[]연산자는 범위를 벗어나면 프로그램이 멈춰버린다
        cout<<arr2.at(6)<<endl;//at()함수로 참조하면 예외처리가 가능하다
    }catch(const out_of_range& ex){
        cerr<<ex.what()<<endl;
    }

    //함수인자
    arrpr(arr2);

    //반복자
    for(auto it=arr2.begin(); it!=arr2.end(); it++){//반복자 iterator 사용, begin()은 시작위치, end()는 끝위치+1
        auto ele = (*it);//반복자는 포인터로 값 참조
        cout<<ele<<" ";
    }
    cout<<endl;

    //원소접근
    array<int, 4> arr3 = {1,2,3,4};
    cout<<arr3.front()<<" ";//첫번째 원소 값 반환
    cout<<arr3.back()<<" ";//마지막 원소 값 반환
    cout<<*(arr3.data()+1)<<endl;//첫번째 위치 반환으로 포인터 연산할 때 사용
    
}

template <size_t N>//array 객체 동적 개수를 위해 template 사용
void arrpr(const array<int, N>& ar){
    for(auto e: ar) cout<<e<<" ";
    cout<<endl;
}
```
array 객체는 c스타일 배열의 향상된 클래스이다   
at() 함수는 []연산자보다 조금 느리지만 안전하게 처리할 수 있다   
iterator에 추가하여 const_iterator와 reverse_iterator가 있다   
const_iterator는 일반 반복자에 const 버전이고 reverse_iterator는 ++을 사용하면 역방향으로 이동한다   
array 객체는 서로 크기가 같은 array 객체끼리 관계 연산자를 사용 할 수 있다   

### array exercise
```c++
//동적 크기 배열, array 클래스 만들기
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

template <typename U>
class dynamic_array{
    U* data;//array 객체용
    size_t n;//array 크기

public:
    dynamic_array(int n){//생성자 작성
        this->n=n;
        data=new U[n];
    }
    dynamic_array(const dynamic_array<U>& other){//깊은 복사 생성자 작성
        n=other.n;
        data=new U[n];
        for(int i=0; i<n; i++){ data[i]=other[i]; }
    }

    U& operator[](int index){ return data[index]; }//[]연산자 작성
    const U& operator[](int index) const{ return data[index]; }//const []연산자 작성

    U& at(int index){//at함수 작성
        if(index<n){ return data[index]; }
        throw "Index out of range";
    }

    size_t size() const{ return n; }//크기 반환

    ~dynamic_array(){ delete[] data; }//소멸자로 메모리 릭 방지

    U* begin(){ return data; }//반복자 begin 생성
    const U* begin() const{ return data; }//const 반복자 begin 생성

    U* end(){ return data+n; }//반복자 end 생성
    const U* end() const{ return data+n; }//const 반복자 end 생성

    friend dynamic_array<U> operator+(const dynamic_array<U>& ar1, dynamic_array<U>& ar2){//+연산자로 두 배열을 합치는 함수 작성
        dynamic_array<U> result(ar1.size()+ar2.size());
        copy(ar1.begin(), ar1.end(), result.begin());//algorithm 헤더의 복사 기능
        copy(ar2.begin(), ar2.end(), result.begin()+ar1.size());
        return result;
    }

    string to_string(const string& sep=", "){//기본 구분자 ,를 넣은 데이터를 문자열로 반환하는 함수 작성
        if(n==0){ return ""; }
        ostringstream os;
        os<<data[0];
        for(int i=1; i<n; i++){ os<<sep<<data[i]; }
        return os.str();
    }
};

struct student{
    string name;
    int standard;
};
ostream& operator<<(ostream& os, const student& s){
    return (os<<"["<<s.name<<", "<<s.standard<<"]");
}

int main(){
    int nStudents;
    cout<<"student count: ";
    cin>>nStudents;

    dynamic_array<student> class1(nStudents);
    for(int i=0; i<nStudents; i++){
        string name;
        int standard;
        cout<<"("<<i+1<<") student name and age: ";
        cin>>name>>standard;
        class1[i]=student{name, standard};
    }

    try{
        class1.at(nStudents) = student{"Jenny", 9};//예외 발생
    }catch(...){
        cout<<"students error!"<<endl;
    }

    auto class2 = class1;//깊은 복사

    auto class3 = class1+class2;//두 배열 합침
    cout<<"class3: "<<class3.to_string()<<endl;
}
```
array 클래스를 직접 만들어보는 연습이다   
<br />
array의 단점 및 특징   
1. array의 크기는 상수로 결정되어서 프로그램 실행 중 변경 불가하다   
2. 크기가 고정되어 있어 추가로 원소를 추가하거나 삭제할 수 없다   
3. array는 항상 스택 메모리에 저장된다   
