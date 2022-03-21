# heap

heap은 시간 복잡도의 조건을 만족하기 위해 complete binary tree(완전 이진 트리)를 사용해야 한다   
완전 이진 트리는 배열로 저장할 수 있어 메모리에 효율적이다   
완전 이진 트리의 배열에서 부모 노드가 i번째 위치한다면 그 자식 노드는 ix2+1(왼쪽), ix2+2(오른쪽)의 연산으로 찾을 수 있고 자식 노드가 i번째 위치한다면 그 자식 노드의 부모 노드는 (i-1)/2의 연산으로 찾을 수 있다   
heap은 부모 노드가 항상 크다라는 불변성을 가지고 있고 응용하면 부모 노드가 항상 작다라는 것을 표현 할 수 있다   

## heap 활용 - 중앙값 구하기
```c++
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct median{
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    void insert(int data){
        if(maxHeap.size()==0){
            maxHeap.push(data);
            return;
        }
        if(maxHeap.size()==minHeap.size()){
            if(data<=get()) maxHeap.push(data);
            else minHeap.push(data);
            return;
        }
        if(maxHeap.size()<minHeap.size()){
            if(data>get()){
                maxHeap.push(minHeap.top());
                minHeap.pop();
                minHeap.push(data);
            }else{
                maxHeap.push(data);
            }
            return;
        }
        if(data<get()){
            minHeap.push(maxHeap.top());
            maxHeap.pop();
            maxHeap.push(data);
        }else{
            minHeap.push(data);
        }
    }
    double get(){
        if(maxHeap.size()==minHeap.size()) return (maxHeap.top()+minHeap.top())/2.0;
        if(maxHeap.size()<minHeap.size()) return minHeap.top();
        return maxHeap.top();
    }
};

int main(){
    median mid;
    mid.insert(1);
    cout<<"middle value: "<<mid.get()<<endl;
    mid.insert(5);
    cout<<"middle value: "<<mid.get()<<endl;
    mid.insert(3);
    cout<<"middle value: "<<mid.get()<<endl;
    mid.insert(10);
    cout<<"middle value: "<<mid.get()<<endl;
    mid.insert(20);
    cout<<"middle value: "<<mid.get()<<endl;
}
```
머신러닝이나 데이터 분석에서 사용할만한 median(중앙값) 구하는 소스이다   
중앙값은 데이터를 정렬하여 가운데 위치한 값이고 만약 데이터의 개수가 짝수라면 가운데 두 데이터의 산술 평균은 구해서 반환한다   

