# container adaptor

container adaptor는 바닥부터 만들어진 컨테이너들로부터 필요한 기능만으로 재작성하여 만든 래퍼(wrapper)들이다   
컨테이너 어댑터에는 stack, queue, priority_queue가 있다   
컨테이너 어댑터를 생성할 때 기본 컨테이너말고 다른 특정 컨테이너가 더 효율적일 수 있어서 변경가능하다   
컨테이너 어댑터에서는 반복자를 지원하지 않는다   

## stack
```c++
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main(){
    stack<int, vector<int>> stk_v;//vector를 이용한 stack 생성
    stack<int> stk;//기본인 deque를 이용한 stack 생성
    stk.push(1);//원소 추가
    stk.push(2);
    stk.push(3);
    cout<<"stk size: "<<stk.size()<<endl;//size()로 크기 구함
    stk.pop();//원소 삭제
    cout<<"stk top: "<<stk.top()<<endl;//top()로 마지막 원소 구함
    stk.emplace(3);//원소 추가, 빠름
    cout<<boolalpha<<"Is stk empty? "<<stk.empty()<<endl;//empty()로 비어있으면 true, 아니면 false를 반환
    cout<<endl;
}
```
stack은 deque로 만들어진 wrapper이고 LIFO(last in first out) 특징을 제공한다   
stack의 push()함수는 deque의 push_back()함수로 구현되고 pop()함수도 pop_back()함수로 구현된다   

## queue
```c++
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(){
    queue<int, vector<int>> q_v;//vector를 이용한 queue 생성
    queue<int> q;//deque를 이용한 queue 생성
    q.push(1);//맨 뒤 원소 추가
    q.push(2);
    q.push(3);
    cout<<"q size: "<<q.size()<<endl;//size()로 크기 구함
    q.pop();//맨 앞 원소 삭제
    q.emplace(4);//맨 뒤 원소 추가, 빠름
    cout<<"q front: "<<q.front()<<endl;//front()로 맨 앞 원소 구함
    cout<<"q back: "<<q.back()<<endl;//back()로 맨 뒤 원소 구함
    cout<<boolalpha<<"Is q empty? "<<q.empty()<<endl;//empty()로 비어있으면 true, 아니면 false를 반환
}
```
queue는 deque로 만들어진 wrapper이고 FIFO(first in first out) 특징을 제공한다   
queue의 push()함수는 deque의 push_back()함수로 구현되고 pop()함수는 pop_front()함수로 구현된다   

## priority_queue
```c++
#include <iostream>
#include <queue>

using namespace std;

struct cmpare{
    bool operator()(int x, int y){ return x>y; }//x>y는 최소, x<y는 최대
};

int main(){
    priority_queue<int> pq1;
    pq1.push(1);//원소 추가
    pq1.push(2);
    pq1.push(3);
    pq1.pop();//top 위치 원소 삭제
    cout<<"pq1 top: "<<pq1.top()<<endl;//top() top위치 원소 구함
    pq1.emplace(9);//원소 추가, 빠름
    pq1.emplace(3);
    cout<<"pq1 size: "<<pq1.size()<<endl;//size()로 크기 구함
    cout<<boolalpha<<"Is pq1 empty? "<<pq1.empty()<<endl;//empty()로 비어있으면 true, 아니면 false를 반환
    cout<<"pq1 top: "<<pq1.top()<<endl;

    priority_queue<int, vector<int>, greater<int>> pq2;//최소 원소 top 우선순위 큐1
    pq2.push(1);
    pq2.push(2);
    pq2.push(3);
    cout<<"pq2 top: "<<pq2.top()<<endl;

    priority_queue<int, vector<int>, cmpare> pq3;//최소 원소 top 우선순위 큐2
    pq3.push(11);
    pq3.push(22);
    pq3.push(33);
    cout<<"pq3 top: "<<pq3.top()<<endl;
}
```
priority_queue(우선순위 큐)는 heap(힙)이라는 자료구조로 사용된다   
heap은 컨테이너들 중 가장 작거나 가장 큰 원소에 빠르게 접근할 때 사용한다   
priority_queue는 vector로 만들어진 wrapper이다   
priority_queue에서 원소 제거는 최소 또는 최대 원소에 대해서만 가능하다    
priority_queue에서 최소 또는 최대 둘다 선택할 수 없으며 컨테이너 비교자에 의해 결정된다   
비교자는 std::less를 사용한다   
heap은 기본적으로 최대 원소가 맨 위(top)에 나타나는 최대 힙으로 생성되며 최소 원소가 맨 위에 나타내려면 heapify알고리즘을 구현해야 한다   
