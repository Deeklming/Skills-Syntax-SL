//Balanced Binary Search Tree
/* basic
    이진 탐색 트리가 한쪽으로 치우치지 않고 균형을 맞추어 탐색 성능(최소 높이일 경우 log2n)을 높이기 위해 사용
    균형 이진 탐색 트리에 왼쪽과 오른쪽 서브 트리의 높이에 대한 균형의 조건을 추가한 것
*/
/* Adelson-Velskii, Landis Tree(AVL Tree) - 대표적 균형 이진 탐색 트리
    hL(height of Left subtree), hR(height of Right subtree), BF(Balance Factor)
    BF(노드의 균형 인수)는 hL(왼쪽 서브 트리의 높이)와 hR(오른쪽 서브 트리의 높이)의 차를 통해 구함
    각 노드의 균형 인수로 -1, 0, 1 값만 가지게 하여 균형을 계속 유지시킴
    왼쪽 서브 트리 < 부모 노드 < 오른쪽 서브 트리의 크기를 가짐
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX(a, b) ((a>b)? a:b)

typedef struct AVLTree{
    int key;
    struct AVLTree* left;
    struct AVLTree* right;
} avl;

avl* LLrotate(avl *parent){//왼쪽 서브 트리 형태에 문제 생길 경우 사용
    avl *child = parent->left;
    parent->left = child->right;
    child->right = parent;
    return child;
}

avl* RRrotate(avl *parent){//오른쪽 서브 트리 형태에 문제 생길 경우 사용
    avl *child = parent->right;
    parent->right = child->left;
    child->left = parent;
    return child;
}

avl* LRrotate(avl *parent){//왼쪽 자식 노드와 그 자식 노드의 오른쪽 자식 노드 형태에 문제 생길 경우 사용
    avl *child = parent->left;
    parent->left = RRrotate(child);
    return LLrotate(parent);
}

avl* RLrotate(avl *parent){//오른쪽 자식 노드와 그 자식 노드의 왼쪽 자식 노드 형태에 문제 생길 경우 사용
    avl *child = parent->right;
    parent->right = LLrotate(child);
    return RRrotate(parent);
}

int getHeight(avl *p){//서브 트리의 높이
    int h = 0;
    if(p!=NULL) h = MAX(getHeight(p->left), getHeight(p->right)) + 1;
    return h;
}

int getBF(avl *p){//BF(균형 인수) 반환
    if(p==NULL) return 0;
    return getHeight(p->left) - getHeight(p->right);
}

avl* rebalance(avl **p){//BF 검사 후 불균형이 있으면 회전 연산 호출
    int bf = getBF(*p);
    if(bf>1){
        if(getBF((*p)->left) > 0) *p = LLrotate(*p);
        else *p = LRrotate(*p);
    }
    else if(bf<-1){
        if(getBF((*p)->right) < 0) *p = RRrotate(*p);
        else *p = RLrotate(*p);
    }
    return *p;
}

avl* insertAVLNode(avl **root, int k){//BST처럼 삽입 후 rebalance() 호출
    if(*root==NULL){
        *root = (avl*)malloc(sizeof(avl));
        (*root)->key = k;
        (*root)->left = NULL;
        (*root)->right = NULL;
    }
    else if(k<(*root)->key){
        (*root)->left = insertAVLNode(&((*root)->left), k);
        *root = rebalance(root);
    }
    else if(k>(*root)->key){
        (*root)->right = insertAVLNode(&((*root)->right), k);
        *root = rebalance(root);
    }
    else{
        printf("same key in here.\n");
        return NULL;
    }
    return *root;
}

avl* searchAVLTree(avl* root, int k){
    avl *p = root;
    int count = 0;
    while(p!=NULL){
        ++count;
        if(k<p->key) p = p->left;
        else if(k==p->key){
            printf("found! %d, count: %d\n", k, count);
            return p;
        }
        else p = p->right;
    }
    ++count;
    printf("not found! %d, count: %d\n", k, count);
    return p;
}

void deleteNode(avl* root, int k){
    avl *parent = NULL, *p = root, *child, *tmp, *tmp_parent;
    while((p!=NULL) && (p->key != k)){
        parent = p;
        if(k<p->key) p = p->left;
        else p = p->right;
    }

    if(p == NULL){//삭제할 노드 없는 경우
        printf("[deleteAVLNode] Not found avl node!\n");
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

void PreorderPrint(avl* root){//전위 순회 출력
    if(root){
        printf("%d ", root->key);
        PreorderPrint(root->left);
        PreorderPrint(root->right);
    }else return;
}

void InorderPrint(avl* root){//전위 순회 출력
    if(root){
        InorderPrint(root->left);
        printf("%d ", root->key);
        InorderPrint(root->right);
    }else return;
}

void PostorderPrint(avl* root){//전위 순회 출력
    if(root){
        PostorderPrint(root->left);
        PostorderPrint(root->right);
        printf("%d ", root->key);
    }else return;
}

int main(){
    avl* avl_root = NULL;
    int key[9] = {60,70,90,80,75,73,72,78,57};
    
    avl_root = insertAVLNode(&avl_root, 50);//make avl tree
    for(int i=0; i<9; ++i) insertAVLNode(&avl_root, key[i]);

    printf("[PreorderPrint]:  ");
    PreorderPrint(avl_root);
    printf("\n[InorderPrint]:   ");
    InorderPrint(avl_root);
    printf("\n[PostorderPrint]: ");
    PostorderPrint(avl_root);
    printf("\n");

    searchAVLTree(avl_root, 78);
    searchAVLTree(avl_root, 77);

    for(int i=8; i>=0; i--){
        deleteNode(avl_root, key[i]);
    }
    deleteNode(avl_root, 50);
    printf("clear!\n");

    return 0;
}