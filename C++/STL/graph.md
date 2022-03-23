# graph

graph(그래프)에는 undirected graph(무방향 그래프)와 directed graph(방향 그래프) 두 종류가 있다   
무방향 그래프는 edge(에지)가 양방향이고 방향 그래프는 한 방향이다   
방향 그래프에서 양방향을 표현하려면 에지가 2개가 되어야 한다   
에지는 방향뿐만 아니라 거리와 같은 추가적인 데이터를 가질 수 있다   

## graph - adjacency matrix
```c++
#include <iostream>
#include <vector>

using namespace std;

enum class pos:int{
    SEOUL,
    BUSAN,
    DAEGU,
    GWANGJU,
    JEJU,
    SEJONG
};

ostream& operator<<(ostream& os, const pos p){
    switch(p){
    case pos::BUSAN:
        os<<"busan";
        return os;
    case pos::SEOUL:
        os<<"seoul";
        return os;
    case pos::JEJU:
        os<<"jeju";
        return os;
    case pos::DAEGU:
        os<<"daegu";
        return os;
    case pos::GWANGJU:
        os<<"gwangju";
        return os;
    case pos::SEJONG:
        os<<"sejong";
        return os;
    default:
        return os;
    }
}

struct graph{
    vector<vector<int>> data;
    graph(int n){
        data.reserve(n);
        vector<int> row(n);
        fill(row.begin(), row.end(), -1);

        for(int i=0; i<n; i++){
            data.push_back(row);
        }
    }
    void addEdge(const pos p1, const pos p2, int d){
        cout<<"add Edge: "<<p1<<"-"<<p2<<"="<<d<<endl;
        auto n1 = static_cast<int>(p1);
        auto n2 = static_cast<int>(p2);
        data[n1][n2] = d;
        data[n2][n1] = d;
    }
    void removeEdge(const pos p1, const pos p2){
        cout<<"delete Edge: "<<p1<<"-"<<p2<<endl;
        auto n1 = static_cast<int>(p1);
        auto n2 = static_cast<int>(p2);
        data[n1][n2] = -1;
        data[n2][n1] = -1;
    }
};

int main(){
    graph g(6);
    g.addEdge(pos::SEJONG, pos::SEOUL, 500);
    g.addEdge(pos::SEJONG, pos::BUSAN, 3000);
    g.addEdge(pos::SEJONG, pos::DAEGU, 1000);
    g.addEdge(pos::BUSAN, pos::SEOUL, 3500);
    g.addEdge(pos::BUSAN, pos::DAEGU, 2000);
    g.addEdge(pos::BUSAN, pos::JEJU, 1500);
    g.addEdge(pos::BUSAN, pos::GWANGJU, 2500);
    g.addEdge(pos::JEJU, pos::SEOUL, 4000);
    g.addEdge(pos::JEJU, pos::DAEGU, 3000);
    g.addEdge(pos::DAEGU, pos::GWANGJU, 2500);
    g.addEdge(pos::GWANGJU, pos::SEOUL, 3000);
    g.removeEdge(pos::SEOUL, pos::GWANGJU);
}
```
adjacency matrix(인접 행렬)을 이용하여 각 지역의 거리를 그래프로 표현한 소스이다   
인접 행렬은 메모리가 노드^2만큼 들기 때문에 adjacency list(인접 리스트)로 그래프를 표현하는게 메모리 낭비에 덜하다   
