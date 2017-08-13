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

int main() {
	int arr[] = { 5, 2, 4, 6, 1, 3 };
	for (int i = 0; i < 6; i++) {
		cout << arr[i];
	}
	cout << endl;
	insertion_sort(arr, 6);
	for (int i = 0; i < 6; i++) {
		cout << arr[i];
	}
}