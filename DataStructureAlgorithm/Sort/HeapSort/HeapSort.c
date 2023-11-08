#include <stdio.h>
#include <stdbool.h>
#define true 1
#define false 0
#define arrlen 22

void HeapSort(int ar[], int len, bool opt);
void heap(int ar[], int left, int right, bool opt);
void swap(int ar[], int a, int b);
void arrprint(char* s, int ar[], int n);

int main() {
	int arr[arrlen] = { 9,3,7,5,8,1,4,7,2,6,9,8,7,0,1,2,3,6,7,1,2,7 };
	arrprint("before sort :    ", arr, arrlen);

	HeapSort(arr, arrlen, false);
	arrprint("\ndescending sort: ", arr, arrlen);
	
	HeapSort(arr,arrlen, true);
	arrprint("\nascending sort:  ", arr, arrlen);
	return 0;
}

void HeapSort(int ar[], int len, bool opt) {//true면 오름차순, false면 내림차순
	for (int i = (len - 1) / 2; i >= 0; i--)
		heap(ar, i, len - 1, opt);
	for (int i = len - 1; i > 0; i--) {
		swap(ar, 0, i);
		heap(ar, 0, i - 1, opt);
	}
}

void heap(int ar[], int left, int right, bool opt) {
	int tmp = ar[left];
	int child, parent;
	if (opt) {
		for (parent = left; parent < (right + 1) / 2; parent = child) {
			int l = parent * 2 + 1;
			int r = l + 1;
			child = (r <= right && ar[r] > ar[l]) ? r : l;
			if (tmp >= ar[child]) break;
			ar[parent] = ar[child];
		}
		ar[parent] = tmp;
	}
	else {
		for (parent = left; parent < (right + 1) / 2; parent = child) {
			int l = parent * 2 + 1;
			int r = l + 1;
			child = (r <= right && ar[r] < ar[l]) ? r : l;
			if (tmp <= ar[child]) break;
			ar[parent] = ar[child];
		}
		ar[parent] = tmp;
	}
}

void swap(int ar[], int a, int b){
	int tmp = ar[a];
	ar[a] = ar[b];
	ar[b] = tmp;
}

void arrprint(char* s, int ar[], int n) {
	printf("%s", s);
	for (int i = 0; i < n; i++) {
		printf("%d ", ar[i]);
	}
}