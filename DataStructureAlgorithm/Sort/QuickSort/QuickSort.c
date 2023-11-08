#include <stdio.h>
#include <stdbool.h>
#define true 1
#define false 0
#define arrlen 20

void QuickSort(int ar[], int left, int right, bool opt);
void swap(int a[], int b, int c);
void arrprint(char* s, int ar[], int n);

int main() {
	int arr[arrlen] = { 9,3,7,5,8,1,4,7,2,6,9,8,7,0,1,2,3,6,7,1 };
	arrprint("before sort :    ", arr, arrlen);

	QuickSort(arr, 0, arrlen - 1, true);
	arrprint("\nascending sort:  ", arr, arrlen);

	QuickSort(arr, 0, arrlen - 1, false);
	arrprint("\ndescending sort: ", arr, arrlen);
	return 0;
}

void QuickSort(int ar[], int left, int right, bool opt) {//true면 오름차순, false면 내림차순
	int l = left;
	int r = right;
	int x = (l + r) / 2;
	int m = ar[x];

	if (opt) {
		if (ar[l] > ar[r]) swap(ar, l, r);
		if (ar[l] > m) swap(ar, l, x);

		do {
			while (ar[l] < m) ++l;
			while (ar[r] > m) --r;
			if (l <= r) swap(ar, l++, r--);
		} while (l <= r);

		if (left < r) QuickSort(ar, left, r, opt);
		if (l < right) QuickSort(ar, l, right, opt);
	}
	else {
		if (ar[l] < ar[r]) swap(ar, l, r);
		if (ar[l] < m) swap(ar, l, x);

		do {
			while (ar[l] > m) ++l;
			while (ar[r] < m) --r;
			if (l <= r) swap(ar, l++, r--);
		} while (l <= r);

		if (left > r) QuickSort(ar, left, r, opt);
		if (l > right) QuickSort(ar, l, right, opt);
	}
}

void swap(int a[], int b, int c) {
	int tmp = a[b];
	a[b] = a[c];
	a[c] = tmp;
}

void arrprint(char* s, int ar[], int n) {
	printf("%s", s);
	for (int i = 0; i < n; i++) {
		printf("%d ", ar[i]);
	}
}