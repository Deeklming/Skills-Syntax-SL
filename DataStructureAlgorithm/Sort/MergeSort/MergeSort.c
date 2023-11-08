#include <stdio.h>
#include <stdbool.h>
#define true 1
#define false 0
#define arrlen 21

void MergeSort(int ar[], int left, int right, bool opt);
void merge(int ar[], int left, int mid, int right, bool opt);
void arrprint(char* s, int ar[], int n);

int tmp[arrlen] = { 0, };

int main() {
	int arr[arrlen] = { 9,3,7,5,8,1,4,7,2,6,9,8,7,0,1,2,3,6,7,1,2 };
	arrprint("before sort :    ", arr, arrlen);

	MergeSort(arr, 0, arrlen - 1, true);
	arrprint("\nascending sort:  ", arr, arrlen);

	MergeSort(arr, 0, arrlen - 1, false);
	arrprint("\ndescending sort: ", arr, arrlen);
	return 0;
}

void MergeSort(int ar[], int left, int right, bool opt) {//true면 오름차순, false면 내림차순
	int middle = (right + left) / 2;
	if (left < right) {
		MergeSort(ar, left, middle, opt);
		MergeSort(ar, middle + 1, right, opt);
		merge(ar, left, middle, right, opt);
	}
}

void merge(int ar[], int left, int mid, int right, bool opt) {
	int i, j = 0, k = left, p = 0;
	if (opt) {
		for (i = left; i <= mid; ++i) tmp[p++] = ar[i];
		while (i <= right && j < p)
			ar[k++] = (tmp[j] <= ar[i]) ? tmp[j++] : ar[i++];
		while (j < p) ar[k++] = tmp[j++];
	}
	else {
		for (i = left; i <= mid; ++i) tmp[p++] = ar[i];
		while (i <= right && j < p)
			ar[k++] = (tmp[j] >= ar[i]) ? tmp[j++] : ar[i++];
		while (j < p) ar[k++] = tmp[j++];
	}
}

void arrprint(char* s, int ar[], int n) {
	printf("%s", s);
	for (int i = 0; i < n; i++) {
		printf("%d ", ar[i]);
	}
}