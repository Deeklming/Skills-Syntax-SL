//Binary Tree (h: 높이, i: 선택한 노드, n: 총 노드 개수)
/*Binary Tree Node Count
    이진 트리의 최소 노드 개수: h+1
    이진 트리의 최대 노드 개수: 2^(h+1)-1
*/
/*Array Binary Tree Index
    이진 트리는 항상 1부터 시작해서 인덱스 0은 항상 비워 둠
    루트 노드: if(n>0) -> 1
    노드 i의 부모 노드: if(i>1) -> i/2
    노드 i의 왼쪽 자식 노드: if((i*2)<=n) -> i*2
    노드 i의 오른쪽 자식 노드: if((i*2+1)<=n) -> i*2+1
*/
#include <stdio.h>

#define n 16

void pr(int* tree, char* str, int count){
    printf("%s ", str);
    for(int i=0; i<count; i++){
        printf("%d ", tree[i]);
    }
    printf("\n");
}

int RootNodeIndex(int* tree, int count){
    for(int i=0; i<count; ++i){
        if(tree[i]!=0) return 1;
    }
    return 0;
}

int ParentNodeIndex(int value_index){
    if(value_index>1) return value_index/2;
    else return 0;
}

int ChildLeftNodeIndex(int value_index, int count){
    if(value_index*2 <= count) return value_index*2;
    else return 0;
}

int ChildRightNodeIndex(int value_index, int count){
    if(value_index*2+1 <= count) return value_index*2+1;
    else return 0;
}

void PreorderTraversal(int* tree, int index, int count){//전위 순회
    if(tree[index] == 0) return;
    printf("%d ", tree[index]);//데이터 처리
    PreorderTraversal(tree, ChildLeftNodeIndex(index, count), count);//왼쪽 자식 노드 방문
    PreorderTraversal(tree, ChildRightNodeIndex(index, count), count);//오른쪽 자식 노드 방문
}

void InorderTraversal(int* tree, int index, int count){//중위 순회
    if(tree[index] == 0) return;
    InorderTraversal(tree, ChildLeftNodeIndex(index, count), count);//왼쪽 자식 노드 방문
    printf("%d ", tree[index]);//데이터 처리
    InorderTraversal(tree, ChildRightNodeIndex(index, count), count);//오른쪽 자식 노드 방문
}

void PostorderTraversal(int* tree, int index, int count){//후위 순회
    if(tree[index] == 0) return;
    PostorderTraversal(tree, ChildLeftNodeIndex(index, count), count);//왼쪽 자식 노드 방문
    PostorderTraversal(tree, ChildRightNodeIndex(index, count), count);//오른쪽 자식 노드 방문
    printf("%d ", tree[index]);//데이터 처리
}

int main(){
    //h(level): 3
    int full_binary_tree[n] = {0,};//포화 이진 트리
    int complete_binary_tree[n] = {0,};//완전 이진 트리
    int skewed_binary_tree[n] = {0,};//편향 이진 트리
    for(int i=1; i<n; ++i) full_binary_tree[i] = i*10;//포화 이진 트리 값 설정
    for(int i=1; i<13; ++i) complete_binary_tree[i] = i*10;//완전 이진 트리 값 설정, 12개 사용
    for(int i=1; i<n; i*=2) skewed_binary_tree[i] = i*10;//편향 이진 트리 값 설정
    pr(full_binary_tree, "full_binary_tree: ", n);
    pr(complete_binary_tree, "complete_binary_tree: ", n);
    pr(skewed_binary_tree, "skewed_binary_tree: ", n);

    int index = 5;
    printf("\n");
    printf("full_binary_tree root value: %d\n", full_binary_tree[RootNodeIndex(full_binary_tree, n)]);
    printf("full_binary_tree index %d value: %d\n", index, full_binary_tree[index]);
    printf("full_binary_tree parent node: %d\n", full_binary_tree[ParentNodeIndex(index)]);
    printf("full_binary_tree child left node: %d\n", full_binary_tree[ChildLeftNodeIndex(index, n)]);
    printf("full_binary_tree child right node: %d\n", full_binary_tree[ChildRightNodeIndex(index, n)]);

    index = 6;
    printf("\n");
    printf("complete_binary_tree root value: %d\n", complete_binary_tree[RootNodeIndex(complete_binary_tree, n)]);
    printf("complete_binary_tree index %d value: %d\n", index, complete_binary_tree[index]);
    printf("complete_binary_tree parent node: %d\n", complete_binary_tree[ParentNodeIndex(index)]);
    printf("complete_binary_tree child left node: %d\n", complete_binary_tree[ChildLeftNodeIndex(index, n)]);
    printf("complete_binary_tree child right node: %d\n", complete_binary_tree[ChildRightNodeIndex(index, n)]);

    index = 4;
    printf("\n");
    printf("skewed_binary_tree root value: %d\n", skewed_binary_tree[RootNodeIndex(skewed_binary_tree, n)]);
    printf("skewed_binary_tree index %d value: %d\n", index, skewed_binary_tree[index]);
    printf("skewed_binary_tree parent node: %d\n", skewed_binary_tree[ParentNodeIndex(index)]);
    printf("skewed_binary_tree child left node: %d\n", skewed_binary_tree[ChildLeftNodeIndex(index, n)]);
    printf("skewed_binary_tree child right node: %d\n", skewed_binary_tree[ChildRightNodeIndex(index, n)]);

    printf("\nfull_binary_tree PreorderTraversal: ");
    PreorderTraversal(full_binary_tree, RootNodeIndex(full_binary_tree, n), n);
    printf("\nfull_binary_tree InorderTraversal: ");
    InorderTraversal(full_binary_tree, RootNodeIndex(full_binary_tree, n), n);
    printf("\nfull_binary_tree PostorderTraversal: ");
    PostorderTraversal(full_binary_tree, RootNodeIndex(full_binary_tree, n), n);

    printf("\n\ncomplete_binary_tree PreorderTraversal: ");
    PreorderTraversal(complete_binary_tree, RootNodeIndex(complete_binary_tree, n), n);
    printf("\ncomplete_binary_tree InorderTraversal: ");
    InorderTraversal(complete_binary_tree, RootNodeIndex(complete_binary_tree, n), n);
    printf("\ncomplete_binary_tree PostorderTraversal: ");
    PostorderTraversal(complete_binary_tree, RootNodeIndex(complete_binary_tree, n), n);

    printf("\n\nskewed_binary_tree PreorderTraversal: ");
    PreorderTraversal(skewed_binary_tree, RootNodeIndex(skewed_binary_tree, n), n);
    printf("\nskewed_binary_tree InorderTraversal: ");
    InorderTraversal(skewed_binary_tree, RootNodeIndex(skewed_binary_tree, n), n);
    printf("\nskewed_binary_tree PostorderTraversal: ");
    PostorderTraversal(skewed_binary_tree, RootNodeIndex(skewed_binary_tree, n), n);
    return 0;
}