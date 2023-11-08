#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	struct Node* next;
	char* data;
}node;

node* CreateHeader();//헤더만들기
node* InsertNode(node* pos, char* d);//노드삽입
void PrintList(node* H);//전체노드출력
node* FindMovePos(node* H, node* pos, char* d);//헤당위치로pos이동
node* LastMovePos(node* pos);//마지막위치로pos이동
node* DeleteNode(node* H, node* pos, char* d);//노드지우기
void ClearList(node* H);//노드전체지우기

int main() {
	node* header = CreateHeader();
	node* pos = header;
	pos = InsertNode(pos, "A");
	pos = InsertNode(pos, "B");
	pos = InsertNode(pos, "C");
	pos = FindMovePos(header, pos, "B");
	pos = InsertNode(pos, "D");
	pos = InsertNode(pos, "E");
	PrintList(header);
	pos = DeleteNode(header, pos, "D");
	pos = DeleteNode(header, pos, "B");
	PrintList(header);
	pos = LastMovePos(pos);
	pos = InsertNode(pos, "F");
	PrintList(header);
	ClearList(header);
	return 0;
}

node* CreateHeader() {
	node* newnode = malloc(sizeof(node));
	newnode->next = NULL;
	newnode->data = NULL;
	printf("make simple linked list header\n");
	return newnode;
}

node* InsertNode(node* pos, char* d) {
	node* newnode = malloc(sizeof(node));
	if (pos->next == NULL) {
		pos->next = newnode;
		newnode->data = d;
		newnode->next = NULL;
	}
	else {
		newnode->data = d;
		newnode->next = pos->next;
		pos->next = newnode;
	}
	printf("insert node %s\n", d);
	return newnode;
}

void PrintList(node* H) {
	node* p = H;
	printf("header");
	while (p->next != NULL) {
		p = p->next;
		printf("->%s", p->data);
	}
	printf("\n");
}

node* FindMovePos(node* H, node* pos, char* d) {
	node* p = H;
	while (p->next != NULL) {
		p = p->next;
		if (p->data == d) {
			printf("pos move success\n");
			return p;
		}
	}
	printf("\"%s\" : no find data\n", d);
	return pos;
}

node* LastMovePos(node* pos) {
	node* p = pos;
	while (p->next != NULL) {
		p = p->next;
	}
	printf("last pos move success\n");
	return p;
}

node* DeleteNode(node* H, node* pos, char* d) {
	node* n = H->next;
	while (n != NULL) {
		if (n->data == d) {
			H->next = n->next;
			if (pos->data == d) {
				pos = H;
			}
			free(n);
			printf("delete data %s\n", d);
			return pos;
		}
		else {
			H = n;
			n = H->next;
		}
	}
	printf("\"%s\" : no find data\n", d);
	return pos;
}

void ClearList(node* H) {
	node* p = H;
	printf("clear(null is header) : ");
	while (p->next != NULL) {
		p = p->next;
		printf("%s->", H->data);
		free(H);
		H = p;
	}
	printf("%s\n", p->data);
	free(p);
	printf("simple linked list clear!\n");
}
