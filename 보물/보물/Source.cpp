#include <iostream>
using namespace std;

void insertion_sort(int *arr, int size) {
	//
	for (int j = 1; j < size; j++) {
		int key = arr[j];
		int i = j - 1;
		//���ĵ� �迭�� ������ ��ġ�� ã�´�.
		while (i >= 0 && arr[i] > key) {
			arr[i + 1] = arr[i];
			i = i - 1;
		}
		//����!
		arr[i + 1] = key;
	}
}

void insertion_sort2(int *arr, int size) {
	//
	for (int j = 1; j < size; j++) {
		int key = arr[j];
		int i = j - 1;
		//���ĵ� �迭�� ������ ��ġ�� ã�´�.
		while (i >= 0 && arr[i] < key) {
			arr[i + 1] = arr[i];
			i = i - 1;
		}
		//����!
		arr[i + 1] = key;
	}
}

int main() {
	int N;
	int *A, *B;

	cin >> N;
	A = new int[N];
	B = new int[N];

	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	for (int i = 0; i < N; i++) {
		cin >> B[i];
	}

	insertion_sort(A, N);
	insertion_sort2(B, N);

	int Answer = 0;
	for (int i = 0; i < N; i++) {
		Answer += (A[i] * B[i]);
	}

	cout << Answer;
}