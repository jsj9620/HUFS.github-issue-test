#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<iostream>

//체스 퀸 배치 문제
//퀸이 움직일 수 있는 자리에는 배치하면 안됨

using namespace std;

int n = 5, A[10][10];

void print() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			printf("%3d", A[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void q(int w, int h) {
	int i;
	for (i = 1; i < h; i++) {
		if (A[i][w] != 0)return;
	}

	for (i = 1;; i++) {
		if (h - i <= 0 || w - i <= 0)break;
		if (A[h - i][w - i] != 0)return;
	}

	for (i = 1;; i++) {
		if (h - 1 <= 0 || w + i > n)break;
		if (A[h - i][w + i] != 0)return;
	}

	A[h][w] = 1;

	if (h == n) {
		print();
		A[h][w] = 0;
		return;
	}

	for (i = 1; i <= n; i++) {
		q(i, h + 1);
	}
	A[h][w] = 0;

}
int main()
{
	freopen("output.txt", "w", stdout);
	q(0, 0);
	return 0;
}