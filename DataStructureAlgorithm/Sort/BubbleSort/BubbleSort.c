#include <stdio.h>
#include <stdbool.h>

void bubblesort(int* ar, int count, bool opt);
void bsswap(int* a, int* b);
#define arr_c 17

int main() {
	int arr[arr_c] = { 9,3,7,5,8,1,4,7,2,6,9,8,7,0,1,2,3 };
	printf("before	    sort: ");
	for (int i = 0; i < arr_c; ++i) printf("%d ", arr[i]);
	bubblesort(arr, arr_c, 1);
	printf("\nascending  order: ");
	for (int i = 0; i < arr_c; ++i) printf("%d ", arr[i]);
	bubblesort(arr, arr_c, 0);
	printf("\ndescending order: ");
	for (int i = 0; i < arr_c; ++i) printf("%d ", arr[i]);
	printf("\n");
	return 0;
}
//opt=1은 오름차순, 0은 내림차순, count는 배열크기
void bubblesort(int* ar, int count, bool opt) {
	int last = 0;
	for (int i = 0; i < count - 1;) {
		bool check = 1;
		for (int j = count - 1; j > i; --j) {
			if (opt? ar[j] < ar[j - 1] : ar[j] > ar[j - 1]) {
				bsswap(&ar[j], &ar[j - 1]);
				check = 0;
				last = j;
			}
		}
		i = last;
		if (check) break;
	}
}

void bsswap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
