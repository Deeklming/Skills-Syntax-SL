# forward_list

```c++
#include <iostream>
#include <forward_list>

using namespace std;

int main(){
    forward_list<int> fl = {1,2,3};//forward_list선언과 동시에 초기화
    
    fl.push_front(0);//맨 앞에 0추가, 임시 데이터를 생성
    auto p1 = fl.begin();
    fl.insert_after(p1, 4);//맨 앞 원소 뒤에 4추가, 특정 위치 추가
    fl.insert_after(p1, 5);//맨 앞 원소 뒤에 5추가
    fl.emplace_front(6);//맨 앞에 6추가, 임시 데이터를 생성하지 않아서 빠름
    fl.emplace_after(fl.begin(), 7);//맨 앞 원소 뒤에 7추가, 빠름
    
    fl.pop_front();//맨 앞 원소 삭제
    auto p2 = fl.begin();
    fl.erase_after(p2);//맨 앞의 다음 원소 삭제
    fl.erase_after(p2, fl.end());//맨 앞의 다음 원소부터 마지막 원소까지 삭제

    fl.emplace_front(6);
    fl.emplace_front(6);
    fl.emplace_front(5);//5 6 6 7
    fl.remove(6);//6과 같은 모든 요소 삭제
    for(auto i: fl){
        cout<<i<<" ";
    }
    cout<<endl;

    forward_list<int> efl = {1, -1, 98, 56, 87, 0, -5, 10};
    
    efl.sort();//오름차순 정렬
    efl.sort(greater<int>());//내림차순 정렬, std::greater<int>는 표준으로 제공되는 비교 함수 객체임
    efl.reverse();//원소들의 순서를 뒤집음

    efl.emplace_front(-1);
    efl.emplace_front(0);
    efl.emplace_front(1);
    efl.sort();
    efl.unique();//중복 제거, unique는 인접한 요소 중 같은 요소가 있으면 앞에만 남기고 제거해서 반드시 sort로 정렬 후 사용해야 함
    for(const auto &i: efl){
        cout<<i<<" ";
    }
    cout<<endl;
}
```
forward_list는 단순 연결 리스트로 성능 유지를 위해 전체 리스트 크기반환, 첫번째 원소 외에 나머지 원소에 직접 접근은 불가능 하다   
forward_list의 반복자는 array와 vector의 반복자와 다르다   

# forward_list remove_if exercise
```c++
#include <iostream>
#include <string>
#include <forward_list>

using namespace std;

struct people{
    string name;
    int age;
};

ostream &operator<<(ostream &os, const people &p){
    return (os<<"["<<p.name<<", "<<p.age<<"]");
}

int main(){
    forward_list<people> pfl = {
        {"Kim", 28}, {"Park", 17}, {"Lee", 24}, {"Jin", 19}
    };

    auto people_copy = pfl;//깊은 복사
    
    for(const auto &p: pfl){
        cout<<p<<" ";
    }
    cout<<endl;

    pfl.remove_if([](const people &p){//람다식을 이용해 bool값을 remove_if에 전달, true값인 age가 20미만인 사람 모두 삭제
        return (p.age<20);
    });
    for(const auto &p: pfl){
        cout<<p<<" ";
    }
    cout<<endl;

    people_copy.remove_if([](const people &p){//age가 28이 아닌 사람 모두 삭제
        return (p.age!=28);
    });
    for(const auto &p: people_copy){
        cout<<p<<" ";
    }
    cout<<endl;
}
```
