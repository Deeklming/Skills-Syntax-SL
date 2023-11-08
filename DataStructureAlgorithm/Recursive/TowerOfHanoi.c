#include <stdio.h>

char out[3] = { 'A','B','C' };

void hanoi(int a, int x, int y) {
	if (a > 1) hanoi(a - 1, x, 6 - x - y);
	printf("disk[%d] move %c -> %c\n", a, out[x - 1], out[y - 1]);
	if (a > 1) hanoi(a - 1, 6 - x - y, y);
}

int main() {
	int in = 3;
	printf("Tower of Hanoi: %d\n", in);
	hanoi(in, 1, 3);
	return 0;
}