#include <stdio.h>
#include <stdlib.h>

void copy(register const int A[], int dest[], const int size) {
	register int *p = dest;
	for (int i = 0; i < size; i++) {
		*(p + i) = *(A + i);
	}
}

void swap(int& A, int& B) {
	int temp;
	temp = A;
	A = B;
	B = temp;
}

void Print(int A[], int size) {
	for (int i = 0; i < size; i++) {
		printf("%d ", A[i]);
	}
	puts("");
}

int* BubbleSort(const int A[], const int size) {
	int* ret = (int*)malloc(sizeof(int) * size);

	copy(A, ret, size);

	for (int i = 0; i < size -  1; i++) {
		for (int j = size - 1; j > i; j--) {
			if (ret[j] < ret[j - 1]) {
				swap(ret[j], ret[j - 1]);
			}
		}
	}

	return ret;
}

int* InsertionSort(const int A[], const int size) {
	int* ret = (int*)malloc(sizeof(int) * size);

	copy(A, ret, size);

	for (int i = 1; i < size; i++) {
		int hold = ret[i];
		int walker = i - 1;
		while (walker >= 0 && ret[walker] > hold) {
			ret[walker + 1] = ret[walker];
			walker--;
		}
		ret[walker + 1] = hold;
	}

	return ret;
}

int* SelectionSort(const int A[], const int size) {
	int* ret = (int*)malloc(sizeof(int) * size);

	copy(A, ret, size);

	for (int i = 0; i < size - 1; i++) {
		int smallest = i;
		for (int j = smallest + 1; j < size; j++) {
			if (ret[smallest] > ret[j]) {
				smallest = j;
			}
		}
		swap(ret[i], ret[smallest]);
	}

	return ret;
}

int* ShellSort(const int A[], const int size) {
	int* ret = (int*)malloc(sizeof(int) * size);

	copy(A, ret, size);

	return ret;
}

void _merge(int A[], int left, int mid, int right) {
	int i = 0, j = 0, k = left;
	int leftSize = mid - left + 1;
	int rightSize = right - mid;

	int *leftArr = (int*)malloc(sizeof(int) * leftSize + 1);
	int *rightArr = (int*)malloc(sizeof(int) * rightSize + 1);

	while (i < leftSize) {
		leftArr[i++] = A[left + i];
	}

	while (j < rightSize) {
		rightArr[j++] = A[mid + 1 + j];
	}

	i = 0;
	j = 0;
	leftArr[leftSize] = (int)1e9;
	rightArr[rightSize] = (int)1e9;

	while (k <= right) {
		if (leftArr[i] < rightArr[j]) {
			A[k] = leftArr[i];
			i++;
		} else {
			A[k] = rightArr[j];
			j++;
		}
		k++;
	}
}
void _mergeSort(int A[], int left, int right) {
	if (left < right) {
		int mid = (left + right) / 2;
		_mergeSort(A, left, mid);
		_mergeSort(A, mid + 1, right);
		_merge(A, left, mid, right);
	}

}

int* MergeSort(const int A[], const int size) {
	int* ret = (int*)malloc(sizeof(int) * size);

	copy(A, ret, size);

	_mergeSort(ret, 0, size - 1);

	return ret;
}

void _qsort(int A[], int left, int right) {
	int hold;
	int pivot;
	int sortLeft;
	int sortRight;

	pivot = A[left];
	sortLeft = left + 1;
	sortRight = right;

	while (sortLeft <= sortRight) {
		while (sortLeft <= sortRight && A[sortLeft] < pivot) {
			sortLeft++;
		}

		while (sortLeft <= sortRight && A[sortRight] >= pivot) {
			sortRight--;
		}

		if (sortLeft <= sortRight) {
			hold = A[sortLeft];
			A[sortLeft] = A[sortRight];
			A[sortRight] = hold;
			sortLeft++;
			sortRight--;
		}
	}

	A[left] = A[sortLeft - 1];
	A[sortLeft - 1] = pivot;

	if (left < sortRight) {
		_qsort(A, left, sortRight);
	}

	if (sortLeft < right) {
		_qsort(A, sortLeft, right);
	}
}

int* QuickSort(const int A[], const int size) {
	int* ret = (int*)malloc(sizeof(int) * size);

	copy(A, ret, size);

	_qsort(ret, 0, size - 1);

	return ret;
}

void _heapify(int A[], int size, int root) {
	int largest = root;
	int left = 2 * root + 1;
	int right = 2 * root + 2;

	if (left < size && A[left] > A[largest]) {
		largest = left;
	}

	if (right < size && A[right] > A[largest]) {
		largest = right;
	}

	if (largest != root) {
		swap(A[largest], A[root]);

		_heapify(A, size, largest);
	}
}

int* HeapSort(const int A[], const int size) {
	int* ret = (int*)malloc(sizeof(int) * size);

	copy(A, ret, size);

	for (int i = size / 2 - 1; i >= 0; i--) {
		_heapify(ret, size, i);
	}

	for (int i = size - 1; i >= 0; i--) {
		swap(ret[0], ret[i]);

		_heapify(ret, i, 0);
	}

	return ret;
}

int main() {
	int A[] = { -1, 1, -2, 2, -3, 3, -4, 4, 0 };
	int size = 9;

	int *ret;
	ret = BubbleSort(A, size);
	Print(ret, size);

	ret = SelectionSort(A, size);
	Print(ret, size);
	
	ret = InsertionSort(A, size);
	Print(ret, size);

	ret = QuickSort(A, size);
	Print(ret, size);

	ret = MergeSort(A, size);
	Print(ret, size);

	ret = HeapSort(A, size);
	Print(ret, size);
}