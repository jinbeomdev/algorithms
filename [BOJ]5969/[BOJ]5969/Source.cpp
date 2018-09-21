#include <stdio.h>
#include <stdlib.h>

const int MAX = 1000000;
int A[MAX];

void Merge(int A[], int left, int mid, int right) {
	int p = 0, q = 0, k = left;

	int left_size = mid - left + 1;
	int right_size = right - mid;
	
	int *left_arr = (int*)calloc(left_size, sizeof(int));
	int *right_arr = (int*)calloc(right_size, sizeof(int));

	while (p != left_size && q != right_size) {
		left_arr[p] = A[left + p];
		right_arr[q] = A[mid + 1 + q];
		p++;
		q++;
	}

	while (p != left_size) {
		left_arr[p] = A[left + p];
		p++;
	}

	while (q != right_size) {
		right_arr[q] = A[mid + 1 + q];
		q++;
	}

	p = 0;
	q = 0;

	while (p != left_size && q != right_size) {
		if (left_arr[p] > right_arr[q]) {
			A[k] = right_arr[q];
			q++;
		} else {
			A[k] = left_arr[p];
			p++;
		}
		k++;
	}

	while (p != left_size) {
		A[k] = left_arr[p];
		p++;
		k++;
	}

	while (q != right_size) {
		A[k] = right_arr[q];
		q++;
		k++;
	}

	free(left_arr);
	free(right_arr);
}


void MergeSort(int A[], int left, int right) {
	if (left < right) {
		int mid = (left + right) / 2;

		MergeSort(A, left, mid);
		MergeSort(A, mid + 1, right);
		Merge(A, left, mid, right);
	}
}

int main() {
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}

	MergeSort(A, 0, N - 1);

	for (int i = 0; i < N; i++) {
		printf("%d\n", A[i]);
	}
}