#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	struct Node* pre;
	struct Node* next;
	char* data;
}dcnode;

dcnode* CreateDoubleCircleList(char* d);//최초리스트만들기
dcnode* InsertDoubleCircleNode(dcnode* P, char* d, _Bool opt);//노드삽입, opt가 참이면 오른쪽 거짓이면 왼쪽
void PrintDoubleCircleList(dcnode* P, _Bool opt);//전체노드출력
dcnode* FindMovePos(dcnode* P, char* d, _Bool opt);//해당위치로Point 이동
char* NowPosData(dcnode* P);//현재위치 데이터 출력반환
dcnode* DeleteDoubleCircleNode(dcnode* P, char* d, _Bool opt);//해당노드지우기
void ClearDoubleCircleList(dcnode* P);//리스트지우기

int main() {
	char* chackData = "A";
	dcnode* h = CreateDoubleCircleList("A");
	h = InsertDoubleCircleNode(h, "B", 1);
	h = InsertDoubleCircleNode(h, "C", 1);
	h = FindMovePos(h, "A", 0);
	PrintDoubleCircleList(h, 1);
	if (chackData == NowPosData(h)) printf("%s - OK\n", h->data);
	else printf("%s - NO\n", h->data);
	h = InsertDoubleCircleNode(h, "E", 0);
	h = InsertDoubleCircleNode(h, "D", 0);
	h = FindMovePos(h, "E", 1);
	PrintDoubleCircleList(h, 0);
	h = DeleteDoubleCircleNode(h, "C", 0);
	h = DeleteDoubleCircleNode(h, "E", 1);
	ClearDoubleCircleList(h);
	return 0;
}

dcnode* CreateDoubleCircleList(char* d) {
	dcnode* newnode = malloc(sizeof(dcnode));
	newnode->data = d;
	newnode->next = newnode;
	newnode->pre = newnode;
	printf("make double circle linked list\nfirst node data: %s\n", d);
	return newnode;
}

dcnode* InsertDoubleCircleNode(dcnode* P, char* d, _Bool opt) {
	dcnode* newnode = malloc(sizeof(dcnode));
	newnode->data = d;
	if (opt) {
		newnode->pre = P;
		newnode->next = P->next;
		P->next->pre = newnode;
		P->next = newnode;
		printf("right insert node: %s\n", d);
	}
	else {
		newnode->next = P;
		newnode->pre = P->pre;
		P->pre->next = newnode;
		P->pre = newnode;
		printf("left insert node: %s\n", d);
	}
	return newnode;
}

void PrintDoubleCircleList(dcnode* P, _Bool opt) {
	dcnode* o = P;
	if (opt) {
		do {
			printf("%s->", o->data);
			o = o->next;
		} while (o != P);
	}
	else {
		do {
			printf("%s->", o->data);
			o = o->pre;
		} while (o != P);
	}
	printf("||\n");
}

dcnode* FindMovePos(dcnode* P, char* d, _Bool opt) {
	dcnode* o = P;
	if (opt) {
		do {
			if (o->data == d) {
				printf("find: %s\n", d);
				return o;
			}
			o = o->next;
		} while (o != P);
	}
	else {
		do {
			if (o->data == d) {
				printf("find: %s\n", d);
				return o;
			}
			o = o->pre;
		} while (o != P);
	}
	printf("no find data: %s\n", d);
	return P;
}

char* NowPosData(dcnode* P) {
	printf("Here \"%s\"\n", P->data);
	return P->data;
}

dcnode* DeleteDoubleCircleNode(dcnode* P, char* d, _Bool opt) {
	dcnode* o = P;
	_Bool fi = 0;
	if (opt) {
		do {
			if (o->data == d) {
				fi = 1;	break;
			}
			o = o->next;
		} while (o != P);
	}
	else {
		do {
			if (o->data == d) {
				fi = 1; break;
			}
			o = o->pre;
		} while (o != P);
	}
	if (fi) {
		printf("delete: %s\n", d);
		o->next->pre = o->pre;
		o->pre->next = o->next;
		if (o == P) P = o->pre;
		free(o);
	}
	else printf("no find data: %s\n", d);
	return P;
}

void ClearDoubleCircleList(dcnode* P) {
	dcnode* n = P->next; dcnode* r = P->pre;
	printf("clear: ");
	while (P != r){
		printf("%s->", P->data);
		free(P);
		P = n;
		n = n->next;
	}
	printf("%s\n", P->data);
	free(P);
}