#include <iostream>
using namespace std;

void selectionSort(int list[], int size) {
	int current;
	int smallest;
	int holdData;
	int walker;

	for (current = 0; current < size; current++) {
		smallest = current;
		for (walker = current + 1; walker < size; walker++) {
			if (list[walker] < list[smallest]) {
				smallest = walker;
			}
		}
		holdData = list[current];
		list[current] = list[smallest];
		list[smallest] = holdData;
	}
}

int main() {
	int list[] = { 9,8,7,4,5,6,3,2,1 };

	for (int i = 0; i < 9; i++) {
		cout << list[i];
	}cout << endl;

	selectionSort(list, 9);

	for (int i = 0; i < 9; i++) {
		cout << list[i];
	}cout << endl;
}