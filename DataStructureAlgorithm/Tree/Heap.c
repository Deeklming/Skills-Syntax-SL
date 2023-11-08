//Heap
/* basic
    히프는 키값이 가장 큰 것 또는 가장 작은 것을 찾기 위한 자료구조임
    Max Heap(최대 히프)는 부모 노드 키값 >= 자식 노드 키값의 관계를 가지는 완전 이진 트리임
    Min Heap(최소 히프)는 부모 노드 키값 <= 자식 노드 키값의 관계를 가지는 완전 이진 트리임
    Heap는 어디서든지 부모 노드를 쉽게 찾아야 하기 때문에 순차 자료구조를 사용하는게 좋음
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX_HEAP 100

typedef struct{
    int heap[MAX_HEAP];
    int size;
} heap;

heap* createHeap(){
    heap* h = (heap*)malloc(sizeof(heap));
    h->size = 0;
    return h;
}

void insertHeap(heap* h, int it){//Max Heap
    h->size += 1;
    int i = h->size;
    while((i!=1) && (it>h->heap[i/2])){
        h->heap[i] = h->heap[i/2];
        i/=2;
    }
    h->heap[i] = it;
}

int deleteHeap(heap* h){//항상 root부터 지움, Max Heap
    int parent=1, child=2, it, tmp;
    it = h->heap[1];
    tmp = h->heap[h->size-1];
    while(child<=h->size){
        if((child<h->size) && (h->heap[child]<h->heap[child+1])) ++child;
        if(tmp>=h->heap[child]) break;
        else{
            h->heap[parent] = h->heap[child];
            parent = child;
            child = child*2;
        }
    }
    h->heap[parent] = tmp;
    return it;
}

void prHeap(heap* h){
    printf("Heap: ");
    for(int i=1; i<=h->size; ++i) printf("%d ", h->heap[i]);
    printf("\n");
}

int main(){
    int n, it;
    int data[5] = {10,45,19,11,96};
    heap* h = createHeap();
    for(int i=0; i<5; ++i){
        insertHeap(h, data[i]);
    }
    
    prHeap(h);

    for(int i=1; i<=h->size; ++i){
        it = deleteHeap(h);
        printf("delete: %d\n", it);
    }

    free(h);
    return 0;
}