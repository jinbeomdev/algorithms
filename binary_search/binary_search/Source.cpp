#include <stdio.h>

bool BinarySearch(int A[], int size, int key) {
	int low = 0;
	int high = size - 1;
	int mid;
	while (low <= high) {
		mid = (low + high) / 2;

		if (A[mid] < key) {
			low = mid + 1;
		} else if (A[mid] > key) {
			high = mid - 1;
		} else {
			return true;
		}
	}
	return false;
}

int main() {
	int A[] = { 1, 2, 3, 4, 5, 6 };
	printf("%d\n", BinarySearch(A, 6, 1));
	printf("%d\n", BinarySearch(A, 6, 2));
	printf("%d\n", BinarySearch(A, 6, 3));
	printf("%d\n", BinarySearch(A, 6, 4));
	printf("%d\n", BinarySearch(A, 6, 5));
	printf("%d\n", BinarySearch(A, 6, 6));
	printf("%d\n", BinarySearch(A, 6, 7));
}