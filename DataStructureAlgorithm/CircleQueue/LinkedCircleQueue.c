#include <stdio.h>
#include <stdlib.h>

int queueringbuffer = 0;
int queuecurrentsize = 0;

typedef struct Node {
	struct Node* left;
	struct Node* right;
	char data;
}queue;

queue* CreateCircleQueue(int max, char d);//최초큐만들기
queue* EnQueue(queue* F, queue* R, char d);//노드큐삽입, r에 반환
queue* DeQueue(queue* F, queue* R, char *d);//노드큐데이터꺼내기, f에 반환
void PrintCircleQueue(queue* F, queue* R);//전체큐노드출력
char NowPeek(queue* FR);//현제front또는rear데이터출력반환
int IndexOf(queue* F, queue* R, char d);//해당데이터위치출력반환
queue* ClearCircleQueue(queue* F, queue* R);//큐전체지우기

int main() {
	queue* f = CreateCircleQueue(4, 'A');
	queue* r = f;
	char outdata = 0;
	r = EnQueue(f, r, 'B');
	r = EnQueue(f, r, 'C');
	PrintCircleQueue(f, r);
	IndexOf(f, r, 'B');
	f = DeQueue(f, r, &outdata);
	printf("out1: %c\n", outdata);
	f = DeQueue(f, r, &outdata);
	printf("out2: %c\n", outdata);
	PrintCircleQueue(f, r);
	NowPeek(f);
	f = ClearCircleQueue(f, r);
	return 0;
}

queue* CreateCircleQueue(int max, char d) {
	queue* newnode = malloc(sizeof(queue));
	newnode->left = NULL;
	newnode->right = NULL;
	newnode->data = d;
	queueringbuffer = max;
	queuecurrentsize = 1;
	printf("make queue! first data: %c\n", d);
	return newnode;
}

queue* EnQueue(queue* F, queue* R, char d) {
	if (queuecurrentsize <= 0) {//DeQueue로 모든 데이터를 지우면 큐설정 새로해야함
		printf("you must do CreateCircleQueue()\n");
		return NULL;
	}
	queue* newnode = malloc(sizeof(queue));
	newnode->data = d;
	if (queuecurrentsize >= queueringbuffer) {//가장 오래된 데이터는 지워짐
		F = F->right;
		free(F->left);
		F->left = NULL;
	}
	else { queuecurrentsize += 1; }
	newnode->left = R;
	newnode->right = NULL;
	R->right = newnode;
	printf("enqueue: %c\n", d);
	return newnode;
}

queue* DeQueue(queue* F, queue* R, char* d) {
	char tmp = -1;
	if (queuecurrentsize <= 0)//DeQueue로 모든 데이터를 지우면 큐설정 새로해야함
		printf("empty queue! you must do CreateCircleQueue()\n");
	else if (queuecurrentsize == 1) {
		*d = F->data;
		free(F);
		F = NULL;
		R = NULL;
		queuecurrentsize -= 1;
		printf("last dequeue: %c\n", *d);
	}
	else {
		*d = F->data;
		F = F->right;
		free(F->left);
		F->left = NULL;
		queuecurrentsize -= 1;
		printf("dequeue: %c\n", *d);
	}
	return F;
}

void PrintCircleQueue(queue* F, queue* R) {
	queue* t = F;
	int count = 1;
	printf("queue buffer: ");
	while (count++ <= queuecurrentsize) {
		printf("%c ", t->data);
		t = t->right;
	}
	printf("\n");
}

char NowPeek(queue* FR) {
	if (queuecurrentsize <= 0) {
		printf("empty queue! no peek!\n");
		return 0;
	}
	printf("peek: %c\n", FR->data);
	return FR->data;
}

int IndexOf(queue* F, queue* R, char d) {
	if (queuecurrentsize <= 0) {
		printf("empty queue! you can't find index!\n");
		return -1;
	}
	queue* t = F;
	int count = 0;
	while (++count <= queuecurrentsize) {
		if (t->data == d) {
			printf("position of %c is %d\n", d, count);
			return count;
		}
		t = t->right;
	}
	printf("%c find fail!\n", d);
	return -1;
}

queue* ClearCircleQueue(queue* F, queue* R) {
	if (queuecurrentsize <= 0) {
		printf("empty queue! no clear!\n");
		return NULL;
	}
	queue* t = F;
	int count = 1;
	printf("clear queue: ");
	while (count++ < queuecurrentsize) {
		printf("%c ", t->data);
		t = t->right;
		free(t->left);
	}
	printf("%c\n", t->data);
	free(t);
	R = NULL;
	return NULL;
}