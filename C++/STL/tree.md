# tree

tree는 비선형 계층적 자료구조이다   

## binary tree
```c++
#include <iostream>
#include <queue>

using namespace std;

struct node{
    string data;
    node* first;
    node* second;
};

struct org_tree{
    node* root;//루트 노드

    static org_tree create_org_tree(const string& pos){//루트 노드 생성
        org_tree tree;
        tree.root=new node{pos, NULL, NULL};
        return tree;
    }

    static node* find(node* root, const string& value){//노드 찾기
        if(root==NULL) return NULL;
        if(root->data==value) return root;
        auto firstFound = org_tree::find(root->first, value);
        if(firstFound!=NULL) return firstFound;
        return org_tree::find(root->second, value);
    }

    bool addSubordinate(const string& manager, const string& subordinate){//노드 추가
        auto managerNode=org_tree::find(root, manager);
        if(!managerNode){
            cout<<"("<<manager<<") is no found"<<endl;
            return false;
        }
        if(managerNode->first && managerNode->second){
            cout<<"("<<subordinate<<") can't input "<<"under ("<<manager<<")"<<endl;
            return false;
        }
        if(!managerNode->first) managerNode->first=new node{subordinate, NULL, NULL};
        else managerNode->second=new node{subordinate, NULL, NULL};
        cout<<"("<<subordinate<<") can input "<<"under ("<<manager<<")"<<endl;
        return true;
    }

    static void preOrder(node* start){//전위 순회
        if(!start) return;
        cout<<start->data<<", ";
        preOrder(start->first);
        preOrder(start->second);
    }

    static void inOrder(node* start){//중위 순회
        if(!start) return;
        preOrder(start->first);
        cout<<start->data<<", ";
        preOrder(start->second);
    }

    static void postOrder(node* start){//후위 순회
        if(!start) return;
        preOrder(start->first);
        preOrder(start->second);
        cout<<start->data<<", ";
    }

    static void levelOrder(node* start){//레벨 순서 순회
        if(!start) return;
        queue<node*> q;
        q.push(start);
        while(!q.empty()){
            int size=q.size();
            for(int i=0; i<size; i++){
                auto current=q.front();
                q.pop();
                cout<<current->data<<", ";
                if(current->first) q.push(current->first);
                if(current->second) q.push(current->second);
            }
            cout<<endl;
        }
    }
};

int main(){
    auto t = org_tree::create_org_tree("CEO");

    t.addSubordinate("CEO", "Second CEO");
    t.addSubordinate("Second CEO", "IT chief");
    t.addSubordinate("Second CEO", "Marketing chief");
    t.addSubordinate("IT chief", "Security team leader");
    t.addSubordinate("IT chief", "App develop team leader");
    t.addSubordinate("Marketing chief", "Warehouse team leader");
    t.addSubordinate("Marketing chief", "Promotion team leader");
    t.addSubordinate("Second CEO", "Head of finance");

    cout<<"preOrder-> ";
    org_tree::preOrder(t.root);
    cout<<"\ninOrder-> ";
    org_tree::inOrder(t.root);
    cout<<"\npostOrder-> ";
    org_tree::postOrder(t.root);
    cout<<"\nlevelOrder->\n";
    org_tree::levelOrder(t.root);
}
```
 기본적인 binary tree(이진 트리)의 형태라서 효용성이 낮다   

## binary search tree
```c++
#include <iostream>

using namespace std;

struct node{
    int data;
    node* left;
    node* right;
};

struct bst{
    node* root=nullptr;

private:
    node* find_impl(node* current, int value){//찾기
        if(!current){
            cout<<endl;
            return NULL;
        }
        if(current->data==value){
            cout<<value<<" find"<<endl;
            return current;
        }
        if(value<current->data){
            cout<<current->data<<" move left-> ";
            return find_impl(current->left, value);
        }
        cout<<current->data<<" move right-> ";
        return find_impl(current->right, value);
    }

    void insert_impl(node* current, int value){//삽입
        if(value<current->data){
            if(!current->left) current->left=new node{value, NULL, NULL};
            else insert_impl(current->left, value);
        }else{
            if(!current->right) current->right=new node{value, NULL, NULL};
            else insert_impl(current->right, value);
        }
    }

    void inorder_impl(node* start){//중위 순회
        if(!start) return;
        inorder_impl(start->left);
        cout<<start->data<<" ";
        inorder_impl(start->right);
    }

    node* delete_impl(node* start, int value){//삭제
        if(!start) return NULL;
        if(value<start->data) start->left=delete_impl(start->left, value);
        else if(value>start->data) start->right=delete_impl(start->right, value);
        else{
            if(!start->left){//자식 노드가 없거나 왼쪽 자식 노드만 없는 경우
                auto tmp=start->right;
                delete start;
                return tmp;
            }
            if(!start->right){//오른쪽 자식 노드만 없는 경우
                auto tmp=start->left;
                delete start;
                return tmp;
            }
            auto sucNode=successor(start);//자식 노드 둘다 있는 경우
            start->data=sucNode->data;
            start->right=delete_impl(start->right, sucNode->data);
        }
        return start;
    }

public:
    node* find(int value){
        return find_impl(root, value);
    }

    void insert(int value){
        if(!root) root=new node{value, NULL, NULL};
        else insert_impl(root, value);
    }

    void inorder(){
        inorder_impl(root);
    }

    node* successor(node* start){//후손 노드 찾기
        auto current=start->right;
        while(current && current->left) current=current->left;
        return current;
    }

    void deleteValue(int value){
        root=delete_impl(root, value);
    }
};

int main(){
    bst tree;
    tree.insert(13);
    tree.insert(19);
    tree.insert(26);
    tree.insert(6);
    tree.insert(12);
    tree.insert(16);
    tree.insert(38);
    tree.insert(3);
    tree.insert(2);

    cout<<"inorder-> ";
    tree.inorder();
    cout<<endl;
    tree.deleteValue(13);
    cout<<"inorder-> ";
    tree.inorder();
    cout<<endl;

    if(tree.find(13)) cout<<"13 is in tree"<<endl;
    else cout<<"13 isn't in tree"<<endl;
}
```
binary search tree(이진 검색 트리, BST)는 많이 사용되는 이진 트리 형태이다   
BST는 왼쪽 자식 노드 < 부모 노드 < 오른쪽 자식 노드의 데이터 크기로 항상 정렬되어서 결국 오름차순으로 자동 정렬된다   
BST는 편향(한쪽으로만 생성되는) 이진 트리가 될 수 있다   

## balanced tree
balanced tree(균형 트리)는 height말고도 AVL, Red-Black tree 등 다양한 균형 이진 트리가 있다   
height-balanced BST는 트리의 높이를 최적화 시켜주는 균형 이진 트리이다   
AVL은 BST의 속성을 유지하면서 균형을 잡기위해 회전을 수행하는 것이다   

## N-ary tree
```c++
#include <iostream>
#include <vector>

using namespace std;

struct nTree{
    int data;
    vector<nTree*> children;
};

int main(){
    cout<<"N-ary tree"<<endl;
}
```
N-ary tree(N-항 트리)는 N개의 자식 노드를 가질 수 있다   
N개의 자식 노드는 vector를 이용하면 좋다   
N-ary tree는 컴퓨터 파일 시스템 구조, 컴파일러의 Abstract Syntax Tree(추상 구문 트리, AST), 회사의 조직도 등에 사용한다   
