# vector

```c++
#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<int> vec1;//vector 선언
    vector<int> vec2 = {1,2,3};//vector 선언과 동시에 크기 3으로 초기화
    vector<int> vec3(5);//크기 5인 vector 선언
    vector<int> vec4(10, 6);//크기 10인 vector선언 후 모든 원소를 6으로 초기화
    
    vec2.push_back(4);//맨 뒤에 4추가, 데이터를 임시로 생성 후 복사 또는 이동
    vec2.insert(vec2.begin(), 5);//맨 앞에 5추가
    vec2.insert(find(vec2.begin(), vec2.end(), 2), 6);//2앞에 6추가
    vec2.emplace_back(7);//맨 뒤에 7추가, 새 원소 위치에 바로 생성해서 빠름
    vec2.emplace(vec2.begin(), 8);//맨 앞에 8추가, 빠름
    
    vec2.pop_back();//맨 뒤 원소 삭제, 빠름
    vec2.erase(vec2.begin());//맨 앞 원소 제거, 느림
    vec2.erase(vec2.begin()+1, vec2.begin()+4);//해당 범위의 원소 제거, 느림
    
    vec2.shrink_to_fit();//vector의 크기에 맞게 용량(capacity) 크기를 맞춤
    vec2.reserve(10);//capacity크기를 10으로 맞춤
    vec2.clear();//모든 원소 제거

    for(auto i: vec4){
        cout<<i<<" ";
    }
    cout<<endl;
}
```
vector는 가변 크기 배열이다   
