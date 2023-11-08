#include <stdio.h>
#include <stdlib.h>

const int stackmaxsize = 3;

typedef struct Node {
	int currentsize;
	struct Node* up;
	struct Node* down;
	char data;
}stack;

stack* CreateStack(char d);//최초스택만들기
stack* PushStackNode(stack* P, char d);//노드스택삽입
stack* PopStackNode(stack* P, char* out);//노드팝
void PrintStack(stack* P);//전체스택노드출력
char NowTopData(stack* P);//top위치데이터출력반환
stack* ClearStack(stack* P);//스택전체지우기

int main() {
	char outdata = 0;
	stack* p = CreateStack('A');
	p = PushStackNode(p, 'B');
	PrintStack(p);
	p = PopStackNode(p, &outdata);
	p = PopStackNode(p, &outdata);
	p = PushStackNode(p, 'C');
	p = PushStackNode(p, 'D');
	p = PushStackNode(p, 'E');
	p = PushStackNode(p, 'F');
	printf("return top data: %c\n", NowTopData(p));
	PrintStack(p);
	p = PopStackNode(p, &outdata);
	p = PopStackNode(p, &outdata);
	p = PopStackNode(p, &outdata);
	p = PopStackNode(p, &outdata);
	p = PushStackNode(p, 'G');
	p = PushStackNode(p, 'H');
	p = ClearStack(p);
	return 0;
}

stack* CreateStack(char d) {
	stack* newnode = malloc(sizeof(stack));
	newnode->currentsize = 1;
	newnode->up = NULL;
	newnode->down = NULL;
	newnode->data = d;
	printf("make stack: %c\n", d);
	return newnode;
}

stack* PushStackNode(stack* P, char d) {
	stack* newnode = malloc(sizeof(stack));
	if (P == NULL) newnode->currentsize = 1;
	else if (P->currentsize >= stackmaxsize) {
		free(newnode);
		printf("Overflow Stack!\n");
		return P;
	}
	else {
		newnode->currentsize = P->currentsize + 1;
		P->up = newnode;
	}
	newnode->up = NULL;
	newnode->down = P;
	newnode->data = d;
	printf("push: %c\n", d);
	return newnode;
}

stack* PopStackNode(stack* P, char *out) {
	if (P == NULL) {
		printf("Underflow Stack!\n");
		*out = -1;
		return P;
	}
	else if (P->currentsize <= 1) {
		*out = P->data;
		free(P);
		P = NULL;
		printf("last=> ");//botton
	}
	else {
		*out = P->data;
		P = P->down;
		free(P->up);
		P->up = NULL;
	}
	printf("pop: %c\n", *out);
	return P;
}

void PrintStack(stack* P) {
	if (P->down == NULL) {
		printf("stack: %c", P->data); return;
	}
	else PrintStack(P->down);
	printf("->%c", P->data);
	if (P->up == NULL) printf("\n");
}

char NowTopData(stack* P) {
	printf("top: %c\n", P->data); return P->data;
}

stack* ClearStack(stack* P) {
	if (P == NULL) {
		printf("Empty Stack!\n"); return P;
	}
	stack* tmp = P->down;
	printf("(Clear): ");
	while (P->down != NULL) {
		printf("%c->", P->data);
		free(P);
		P = tmp;
		tmp = tmp->down;
	}
	printf("%c\n", P->data);
	free(P);
	return NULL;
}