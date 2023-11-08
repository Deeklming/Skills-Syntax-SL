//Binary Search Tree
/* basic
    이진 탐색 트리는 이진 트리를 탐색용 자료구조로 사용하기 위해 원소의 크기에 따라 노드의 위치를 정의한 것
    탐색이란 자료들 속에서 필요한 자료를 찾는 것을 말하고 항상 루트 노드에서 시작 함
    탐색하려면 찾을 자료를 식별할 수 있는 유일한 값이 필요한데 그것을 Key(키)라고 함
*/
/* Binary Search Tree Definition
    모든 원소는 서로 다른 유일한 키를 가짐
    왼쪽 서브 트리에 있는 키는 그 루트의 키보다 작음
    오른쪽 서브 트리에 있는 키는 그 루트의 키보다 큼
    양쪽 서브 트리도 이진 탐색 트리임
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct BinarySearchTree{
    int key;
    struct BinarySearchTree* left;
    struct BinarySearchTree* right;
} bsTree;

void PreorderPrint(bsTree* root){//전위 순회 출력
    if(root){
        printf("%d ", root->key);
        PreorderPrint(root->left);
        PreorderPrint(root->right);
    }else return;
}

void InorderPrint(bsTree* root){//전위 순회 출력
    if(root){
        InorderPrint(root->left);
        printf("%d ", root->key);
        InorderPrint(root->right);
    }else return;
}

void PostorderPrint(bsTree* root){//전위 순회 출력
    if(root){
        PostorderPrint(root->left);
        PostorderPrint(root->right);
        printf("%d ", root->key);
    }else return;
}

bsTree* InsertBSTNode(bsTree* p, int k){//create or insert
    bsTree* newnode;
    if(p==NULL){
        newnode = (bsTree*)malloc(sizeof(bsTree));
        newnode->key = k;
        newnode->left = NULL;
        newnode->right = NULL;
        return newnode;
    }
    else if(k<p->key) p->left = InsertBSTNode(p->left, k);
    else if(k>p->key) p->right = InsertBSTNode(p->right, k);
    else printf("same key in here.\n");
    return p;
}

bsTree* searchBSTNode(bsTree* root, int k){
    bsTree* p = root;
    while(p != NULL){
        if(k<p->key) p = p->left;
        else if(k==p->key) return p;
        else p = p->right;
    }
    printf("[searchBSTNode] Not found bsTree node!\n");
    return p;
}

void deleteBSTNode(bsTree* root, int k){
    bsTree *parent = NULL, *p = root, *child, *tmp, *tmp_parent;
    while((p!=NULL) && (p->key != k)){
        parent = p;
        if(k<p->key) p = p->left;
        else p = p->right;
    }

    if(p == NULL){//삭제할 노드 없는 경우
        printf("[deleteBSTNode] Not found bsTree node!\n");
        return;
    }

    if((p->left==NULL) && (p->right==NULL)){//자식 노드가 없는 경우
        if(parent!=NULL){
            if(parent->left==p) parent->left = NULL;
            else parent->right = NULL;
        }else root = NULL;
    }
    else if((p->left==NULL) || (p->right==NULL)){//자식 노드가 한개 인 경우
        if(p->left!=NULL) child = p->left;
        else child = p->right;
        if(parent!=NULL){
            if(parent->left==p) parent->left = child;
            else parent->right = child;
        }else root = child;
    }
    else{//자식 노드가 두개 인 경우
        tmp_parent = p;
        tmp = p->left;
        while(tmp->right!=NULL){//왼쪽 서브 트리에서 후계자 찾기
            tmp_parent = tmp;
            tmp = tmp->right;
        }
        if(tmp_parent->left==tmp) tmp_parent->left = tmp->left;
        else tmp_parent->right = tmp->left;
        p->key = tmp->key;
        p = tmp;
    }
    free(p);
}

int main(){
    bsTree *root = NULL, *foundedNode = NULL;
    int key[10] = {9,6,4,2,13,14,1,10,5,17};

    root = InsertBSTNode(root, 7);
    for (int i=0; i<10; i++){
        InsertBSTNode(root, key[i]);
    }
    
    printf("[PreorderPrint]:  ");
    PreorderPrint(root);
    printf("\n[InorderPrint]:   ");
    InorderPrint(root);
    printf("\n[PostorderPrint]: ");
    PostorderPrint(root);

    printf("\nfound! %d\n", searchBSTNode(root, 1)->key);

    for(int i=9; i>=0; i--){
        deleteBSTNode(root, key[i]);
    }
    deleteBSTNode(root, 7);
    printf("clear!\n");

    return 0;
}