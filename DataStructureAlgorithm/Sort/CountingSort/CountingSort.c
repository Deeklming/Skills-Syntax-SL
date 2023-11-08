#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdbool.h>
#define true 1
#define false 0
#define arrlen 23

void CountingSort(int ar[], int len, bool opt);
int max(int ar[], int l);
void arrprint(char* s, int ar[], int n);

int main() {
	int arr[arrlen] = { 9,3,7,5,8,1,4,7,2,6,9,8,7,0,1,2,3,6,7,1,2,7,12 };
	arrprint("before sort :    ", arr, arrlen);

	CountingSort(arr, arrlen, true);
	arrprint("\nascending sort:  ", arr, arrlen);
	
	CountingSort(arr, arrlen, false);
	arrprint("\ndescending sort: ", arr, arrlen);
	return 0;
}

void CountingSort(int ar[], int len, bool opt) {//true면 오름차순, false면 내림차순
	if (len < 2) return;
	int mx = max(ar, len) + 1;
	int* f = malloc(sizeof(int) * mx);
	memset(f, 0, sizeof(int) * mx);
	int* b = malloc(sizeof(int) * len);
	memset(b, 0, sizeof(int) * len);
	if (opt) {
		for (int i = 0; i < len; ++i) f[ar[i]]++;
		for (int i = 1; i < mx; ++i) f[i] += f[i - 1];
		for (int i = len - 1; i >= 0; --i) b[--f[ar[i]]] = ar[i];
		for (int i = 0; i < len; ++i) ar[i] = b[i];
	}
	else {
		for (int i = 0; i < len; ++i) f[ar[i]]++;
		for (int i = mx - 1; i > 0; --i) f[i - 1] += f[i];
		for (int i = len - 1; i >= 0; --i) b[--f[ar[i]]] = ar[i];
		for (int i = 0; i < len; ++i) ar[i] = b[i];
	}
	free(f);
	free(b);
}

int max(int ar[], int l) {
	int tmp = ar[0];
	if (l < 2) return tmp;
	for (int i = 1; i < l; ++i) {
		if (ar[i] > tmp) tmp = ar[i];
	}
	return tmp;
}

void arrprint(char* s, int ar[], int n) {
	printf("%s", s);
	for (int i = 0; i < n; i++) {
		printf("%d ", ar[i]);
	}
}