#include <iostream>
#include <string>
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
	int A[3];
	string s;

	for (int i = 0; i < 3; i++) {
		cin >> A[i];
	}

	insertion_sort(A, 3);
	cin >> s;

	for (int i = 0; i < 3; i++) {
		cout << A[s[i] % 'A'] << " ";
	}
}