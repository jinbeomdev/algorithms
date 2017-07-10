#include <iostream>
using namespace std;

void bubbleSort(int list[], int size) {
	int last = size - 1;
	int current;
	int walker;
	int temp;
	bool sorted;

	for (current = 0, sorted = false; current <= last && !sorted; current++) {
		for (walker = last, sorted = true; walker > current; walker--) {
			if (list[walker] < list[walker - 1]) {
				//교환이 일어나면, 소트되지 않은 것임
				sorted = false;
				temp = list[walker];
				list[walker] = list[walker - 1];
				list[walker - 1] = temp;
			}
		}
	}
}

int main() {
	int list[] = { 9,8,7,4,5,6,1,2,3 };

	for (int i = 0; i < 9; i++) {
		cout << list[i] << " ";
	} cout << endl;

	bubbleSort(list, 9);

	for (int i = 0; i < 9; i++) {
		cout << list[i] << " ";
	} cout << endl;
}