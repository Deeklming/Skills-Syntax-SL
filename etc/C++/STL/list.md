# list

```c++
#include <iostream>
#include <list>

using namespace std;

int main(){
    list<int> l1 = {1,2,3};
    l1.push_back(4);//마지막에 원소 추가
    l1.emplace_back(5);//빠름, 마지막에 원소 추가
    l1.insert(next(l1.begin()), 0);//시작위치의 다음위치에 0추가
    l1.insert(prev(l1.end()), 0);//마지막위치의 이전위치에 0추가
    l1.push_front(-1);//시작위치에 -1추가
    l1.insert(l1.end(), 6);//마지막위치에 8추가
    l1.pop_back();//마지막위치 원소 삭제
    l1.erase(l1.begin());//반복자 위치의 원소 삭제
    for(auto i: l1) cout<<i<<' ';
    cout<<endl;
    
    l1.remove(0);//0과 같은 모든 원소 삭제
    l1.reverse();//역순
    for(auto i: l1) cout<<i<<' ';
    cout<<endl;

    l1.remove_if([](const int &check){//람다식으로 홀수 삭제
        return check%2==1;
    });
    for(auto i: l1) cout<<i<<' ';
    cout<<endl;

    l1.emplace_front(0);////빠름, 시작위치에 0추가
    l1.emplace_front(2);
    l1.emplace_front(4);
    l1.sort();//오름차순으로 정렬
    l1.unique();//중복 삭제
    for(auto i: l1) cout<<i<<' ';
    cout<<"| size: "<<l1.size()<<endl;//size로 크기 구함
}
```
list는 이중 연결 리스트 구조라 양방향 반복자를 사용한다   
forward_list보다 list가 메모리와 연산을 조금 더 사용한다   
list와 forward_list는 반복자 무효화가 일어나지 않는다   
