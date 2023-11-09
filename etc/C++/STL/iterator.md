# iterator

```c++
#include <iostream>
#include <forward_list>
#include <vector>

using namespace std;

int main(){
    vector<string> vec={"a","b","c","D","E"};
    auto it = vec.begin();//상수시간
    cout<<"start: "<<*it<<endl;
    it+=4;
    cout<<"end: "<<*it<<endl;
    advance(it, -2);//advance(반복자, 거리) 반복자를 거리만큼 증가시킴
    cout<<"middle: "<<*it<<endl;
    
    forward_list<string> fwd(vec.begin(), vec.end());
    auto it1=fwd.begin();
    advance(it1, 1);//선형 시간, forward_list는 순방향만 이동하기에 만약 -거리를 주면 에러
    //it1+=2; 에러, forward_list 반복자에는 += 기능이 없음
    cout<<"second: "<<*it1<<endl;

    vector<int> v1 = {1,2,3};
    for(auto it = v1.begin(); it != v1.end(); it=next(it)) cout<<*it<<' ';
    cout<<endl;//next(반복자)는 다음 위치를 반환함

    vector<int> v2 = {1,2,3};
    for(auto it = v2.end()-1; it != v2.begin()-1; it=prev(it)) cout<<*it<<' ';
    cout<<endl;//prev(반복자)는 이전 위치를 반환함
}

```
반복자는 상수시간을 사용한다   
반복자는 포인터를 기반으로 만들어졌기 때문에 vector::push_back()이나 vector::insert()처럼 원소가 추가되어 새로운 메모리에 재할당 될 때 기존의 반복자, 포인터, 참조는 모두 무효화되어 예측불가능한 동작이 발생할 수 있다   
