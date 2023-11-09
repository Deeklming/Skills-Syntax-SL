# deque

```c++
#include <iostream>
#include <deque>

using namespace std;

int main(){
    deque<int> deq={1,2,3};
    deq.push_front(0);//맨 앞에 0추가
    deq.push_back(4);//맨 뒤에 4추가
    deq.emplace_front(-1);//맨 앞에 -1추가, 빠름
    deq.emplace_back(5);//맨 뒤에 5추가, 빠름
    deq.emplace(deq.end(), 6);//마지막위치에 6추가, 빠름
    deq.insert(deq.begin()+3, -9);//시작위치에서 +3위치에 -9추가
    deq.pop_back();//맨 뒤 원소 삭제
    deq.pop_front();//맨 앞 원소 삭제
    deq.erase(deq.begin()+2);//시작위치에서 +2위치에 원소 -9삭제
    deq.erase(deq.begin()+3, deq.end());//시작위치에서 +3위치부터 마지막 위치까지 모두 삭제
    for(auto i: deq) cout<<i<<' ';
    cout<<endl;
}
```
deque는 양방향 큐(double-ended queue)의 약자이다   
capacity()함수는 지원하지 않는다   
deque는 빠르다   
