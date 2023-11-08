//Graph
/* basic
    그래프는 선형 자료구조나 트리 자료구조로 표현 할 수 없고 각 원소 사이 연결되어 있는 다:다 관계를 표현하는 자료구조임
    그래프는 G[Graph]=(V[Vertex,정점], E[Edge,간선])로 정의함
    그래프에는 Undirected Graph(무방향 그래프), Directed Graph(방향 그래프), Complete Graph(완전 그래프), Subgraph(부분 그래프), Weight Graph(가중치 그래프) 등이 있음
    Simple Path(단순 경로)에 정점에서 시작과 끝이 같은 경로를 Cycle(사이클)이라 하고 방향 그래프이면서 사이클이 없는 그래프를 DAG(Directed Acyclic Graph)라고 함
    모든 정점이 연결되어 있으면 Connected Graph(연결 그래프)라 하고 정점이 연결되어 있지 않은 부분이 있으면 Disconnected Graph(단절 그래프)라 함
    Tree(트리)는 사이클이 없는 연결 그래프임
*/
/* BFS(Breadth First Search)
    너비 우선 탐색은 가까운 정점을 먼저 방문하고 멀리 있는 정점을 나중에 방문하는 순회 방법(큐 사용)임
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTEX 10
#define false 0
#define true 1

typedef struct graphNode{//인접 리스트의 노드 구조
    int vertex;
    struct graphNode* link;
} gn;

typedef struct graphBFS{
    int n;//정점 개수
    gn* adj_h[MAX_VERTEX];//정점에 대한 인접 리스트의 헤드 노드 배열
    int visited[MAX_VERTEX];//정점 방문 표시
} bfs;

typedef struct queueNode{
    int data;
    struct queueNode* link;
} qn;

typedef struct{
    qn *front, *rear;
} lqn;

lqn* createLinkedQueue(){
    lqn *lq = (lqn*)malloc(sizeof(lqn));
    lq->front = NULL;
    lq->rear = NULL;
    return lq;
}

int isEmpty(lqn* lq){
    if(lq->front==NULL){
        printf("\nLinked Queue is empty!\n");
        return 1;
    }
    else return 0;
}

void enQueue(lqn* lq, int it){
    qn* newnode = (qn*)malloc(sizeof(qn));
    newnode->data = it;
    newnode->link = NULL;
    if(lq->front==NULL){
        lq->front = newnode;
        lq->rear = newnode;
    }
    else{
        lq->rear->link = newnode;
        lq->rear = newnode;
    }
}

int deQueue(lqn* lq){
    qn* old = lq->front;
    int item;
    if(isEmpty(lq)) return 0;
    else{
        item = old->data;
        lq->front = lq->front->link;
        if(lq->front==NULL) lq->rear = NULL;
        free(old);
        return item;
    }
}

void pr(bfs* g){//인접 리스트 출력
    gn* p;
    for(int i=0; i<g->n; i++){
        printf("%c list", i+65);
        p = g->adj_h[i];
        while(p){
            printf(" -> %c", p->vertex+65);
            p = p->link;
        }
        printf("\n");
    }
}

void createGraph(bfs* g){
    g->n = 0;
    for(int v=0; v<MAX_VERTEX; v++){
        g->visited[v] = false;
        g->adj_h[v] = NULL;
    }
}

void insertVertex(bfs* g, int v){//v는 정점
    if(((g->n)+1)>MAX_VERTEX){
        printf("over vertex count!\n");
        return;
    }
    g->n++;
}

void insertEdge(bfs* g, int u, int v){//(u, v)는 간선
    gn* node;
    if(u>=g->n || v>=g->n){
        printf("A vertex that is not in the graph!");
        return;
    }
    node = (gn*)malloc(sizeof(gn));
    node->vertex = v;
    node->link = g->adj_h[u];
    g->adj_h[u] = node;
}

void bfs_adjList(bfs* g, int v){//정점 v에 대한 너비 우선 탐색
    gn* w;
    lqn* q = createLinkedQueue();//큐 생성
    g->visited[v] = true;//시작 정점 v를 방문해서 true로 설정
    printf(" %c", v+65);
    enQueue(q, v);//현재 정점 v를 큐에 삽입
    
    while(!isEmpty(q)){
        v = deQueue(q);
        for(w=g->adj_h[v]; w; w=w->link){//인접 정점이 있는 동안 수행
            if(!g->visited[w->vertex]){//현재 정점 w를 방문하지 않은 경우
                g->visited[w->vertex] = true;
                printf(" %c", w->vertex+65);
                enQueue(q, w->vertex);
            }
        }
    }//큐가 공백이면 너비 우선 탐색 종료
}

int main(){
    bfs* G = (bfs*)malloc(sizeof(bfs));
    createGraph(G);
    for(int i=0; i<7; i++) insertVertex(G, i);

    int a[16] = {0,0,1,1,1,2,2,3,3,4,4,4,5,6,6,6};
    int b[16] = {2,1,4,3,0,4,0,6,1,6,2,1,6,5,4,3};
    for(int i=0; i<16; i++) insertEdge(G, a[i], b[i]);
    
    pr(G);

    printf("BFS:");
    bfs_adjList(G, 0);//0인 정점 A에서 너비 우선 탐색 시작
    return 0;
}