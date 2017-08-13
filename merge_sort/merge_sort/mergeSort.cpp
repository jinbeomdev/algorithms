#include <iostream>

void merge(int A[], int p, int q, int r) {
	int i = 0, j = 0, k = p;
	int n1 = q - r + 1; //새로운 배열(왼쪽)의 크기
	int n2 = r - q + 1; //새로운 배열(오른쪽)의 크기
	int *L = new int[n1 + 1], *R = new int[n2 + 1];

	while (i < n1) {
		L[i++] = A[p + i];
	}
	
	while (j < n2) {
		R[j++] = A[q + j + 1];
	}

	i = 0;
	j = 0;

	L[n1] = INT_MAX;
	R[n2] = INT_MAX;

	while (k <= r) {
		if (L[i] < R[j]) {
			A[k] = L[i];
			i++;
		}
		else {
			A[k] = R[j];
			j++;
		}
	}
}

void merge_sort(int A[], int q, int r) {
	if (q < r) {
		int p = 1 + (q + r) / 2;
		merge_sort(A, q, p);
		merge_sort(A, p + 1, r);
		merge(A, p, q, r);
	}
}

int main() {
	int A[] = { 5, 2, 4, 7, 1, 3, 2, 6 };
	merge_sort(A, 0, 7);

	for (int i = 0; i < 8; i++) {
		std::cout << A[i];
	}
}