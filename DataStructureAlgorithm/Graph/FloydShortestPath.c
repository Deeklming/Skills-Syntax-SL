//Graph
/* basic
    그래프는 선형 자료구조나 트리 자료구조로 표현 할 수 없고 각 원소 사이 연결되어 있는 다:다 관계를 표현하는 자료구조임
    그래프는 G[Graph]=(V[Vertex,정점], E[Edge,간선])로 정의함
    그래프에는 Undirected Graph(무방향 그래프), Directed Graph(방향 그래프), Complete Graph(완전 그래프), Subgraph(부분 그래프), Weight Graph(가중치 그래프) 등이 있음
    Simple Path(단순 경로)에 정점에서 시작과 끝이 같은 경로를 Cycle(사이클)이라 하고 방향 그래프이면서 사이클이 없는 그래프를 DAG(Directed Acyclic Graph)라고 함
    모든 정점이 연결되어 있으면 Connected Graph(연결 그래프)라 하고 정점이 연결되어 있지 않은 부분이 있으면 Disconnected Graph(단절 그래프)라 함
    Tree(트리)는 사이클이 없는 연결 그래프임
*/
/* Shortest Path
    최단 경로는 신장 트리가 아닌 가중치 그래프에서 두 정점을 연결하는 경로 중 가중치의 합이 최소 경로임
    그래프의 가중치는 Weight Adjacent Matrix(가중치 인접 행렬)에 저장함
    두 정점 사이에 간선이 없으면 0이 아닌 무한대의 값이 저장되어 있다고 가정하고 자기 자신과 이어진 간선을 허용하지 않으니 행렬의 대각선값을 0으로 함
    최단 경로 알고리즘에는 Dijkstra Shortest Path Algorithm과 Floyd Shortest Path Algorithm이 있음
*/
/* Floyd Shortest Path Algorithm
    플로이드 최단 경로 알고리즘은 모든 정점 사이의 최단 경로를 구하는 알고리즘임
*/
#include <stdio.h>
#include <limits.h>
#define MAX_VERTEX 5
#define INF 10000

int weightMatrix[MAX_VERTEX][MAX_VERTEX]={//가중치 인접 행렬
    {0,10,5,INF,INF},
    {INF,0,2,1,INF},
    {INF,3,0,9,2},
    {INF,INF,INF,0,4},
    {7,INF,INF,6,0},
};
int A[MAX_VERTEX][MAX_VERTEX];//k-최단 경로 배열

void printStep(int step){
    printf("A%d: ", step);
    for(int i=0; i<MAX_VERTEX; i++){
        printf("\t");
        for(int j=0; j<MAX_VERTEX; j++){
            if(A[i][j]==INF) printf("%3c", '*');
            else printf("%3d", A[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void FloydShortestPath(int n){
    for(int v=0; v<n; v++){//초기화
        for(int w=0; w<n; w++){
            A[v][w] = weightMatrix[v][w];
        }
    }

    int step = -1;
    printStep(step);

    for(int k=0; k<n; k++){
        for(int v=0; v<n; v++){
            for(int w=0; w<n; w++){
                if(A[v][k]+A[k][w] < A[v][w]){
                    A[v][w] = A[v][k]+A[k][w];
                }
            }
        }
        printStep(++step);
    }
}

int main(){
    printf("Weight Adjacent Matrix\n");
    for(int i=0; i<MAX_VERTEX; i++){
        for(int j=0; j<MAX_VERTEX; j++){
            if(weightMatrix[i][j]==INF) printf("%3c", '*');
            else printf("%3d", weightMatrix[i][j]);
        }
        printf("\n");
    }

    printf("\nFloyd Shortest Path Algorithm\n");
    FloydShortestPath(MAX_VERTEX);
    return 0;
}