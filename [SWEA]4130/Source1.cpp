#include <iostream>

using namespace std;

int main() {
	int arr[] = { 1,0,0,0,1 };
	
	//int temp = arr[4];

	//for (int i = 4; i > 0; i--) {
	//	arr[i] = arr[i - 1];
	//}
	//arr[0] = temp;

	//for (int i = 0; i < 5; i++) {
	//	cout << arr[i] << " ";
	//}

	int temp = arr[0];
	for (int i = 0; i < 5; i++) {
		arr[i] = arr[i + 1];
	}
	arr[4] = temp;

	for (int i = 0; i < 5; i++) {
		cout << arr[i] << " ";
	}

	system("pause");
}