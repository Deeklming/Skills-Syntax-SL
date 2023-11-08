#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	struct Node* next;
	char* data;
}node;

node* CreateCircleNode(char* d);//헤더노드만들기
node* InsertCircleNode(node* H, char* d);//노드삽입
void PrintCircleList(node* H);//전체노드출력
node* FindMovePos(node* H, char* d);//헤당위치로 H이동
node* DeleteCircleNode(node* H, char* d);//노드지우기
void ClearCircleList(node* H);//노드전체지우기

int main() {
	node* header = CreateCircleNode("A");
	header = InsertCircleNode(header, "B");
	header = FindMovePos(header, "A");
	header = InsertCircleNode(header, "C");
	PrintCircleList(header);
	header = InsertCircleNode(header, "D");
	header = DeleteCircleNode(header, "A");
	header = FindMovePos(header, "D");
	header = InsertCircleNode(header, "E");
	PrintCircleList(header);
	header = FindMovePos(header, "B");
	ClearCircleList(header);
	return 0;
}

node* CreateCircleNode(char* d) {
	node* newnode = malloc(sizeof(node));
	newnode->next = newnode;
	newnode->data = d;
	printf("make simple circle linked list %s node!\n", d);
	return newnode;
}

node* InsertCircleNode(node* H, char* d) {
	node* newnode = malloc(sizeof(node));
	newnode->next = H->next;
	newnode->data = d;
	H->next = newnode;
	printf("insert node %s\n", d);
	return newnode;
}

void PrintCircleList(node* H) {
	node* p = H;
	printf("position: %s", p->data);
	while (p->next != H) {
		p = p->next;
		printf("->%s", p->data);
	}
	printf("\n");
}

node* FindMovePos(node* H, char* d) {
	node* p = H;
	do {
		if (p->data == d) {
			printf("pos move success\n");
			return p;
		}
		p = p->next;
	} while (p != H);
	printf("\"%s\" : no find data\n", d);
	return H;
}

node* DeleteCircleNode(node* H, char* d) {
	node* p = H; node* n = H;
	while (p->next != H) p = p->next;
	do {
		if (n->data == d) {
			p->next = n->next;
			printf("delete data: %s\n", n->data);
			free(n);
			return p;
		}
		p = p->next;
		n = n->next;
	} while (n != H);
	printf("\"%s\" : no find delete data\n", d);
	return H;
}

void ClearCircleList(node* H) {
	node* p = H;
	node* n = H->next;
	while (p->next != H) p = p->next;
	printf("clear: ");
	while (H != p) {
		printf("%s->", H->data);
		free(H);
		H = n;
		n = n->next;//마지막은 쓰레기값 가르키고 있음
	}
	printf("%s", H->data);
	free(H);
	printf("\nsimple circle linked list clear!\n");
}
