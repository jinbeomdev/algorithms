#include <iostream>

//Knuth는 최적의 파티션의 크기에서는 insert sort를 사용하기를 권장.
//최적의 파티션의 크기를 결정하는 일은 굉장히 어려운 일
//여기서는 시범으로 4를 하기로 했지만, 내 책에서는 16을 하기로 했다.
#define MIZ_SIZE 4

void quickInsertSort(int sortData[], int first, int last) {
	int current;
	int hold;
	int walker;

	for (current = first + 1; current <= last; current++) {
		hold = sortData[current];
		walker = current - 1;

		while (walker >= first && sortData[walker] > hold) {
			sortData[walker + 1] = sortData[walker];
			walker--;
		}
		sortData[walker + 1] = hold;
	}
}

void medianLeft(int sortData[], int left, int right) {
	//singleton algorithm
	//중간값 선택 방법으로 singleton algorithm을 사용
	int mid;
	int hold;

	mid = (left + right) / 2;
	if (sortData[left] > sortData[mid]) {
		hold = sortData[left];
		sortData[left] = sortData[mid];
		sortData[mid] = hold;
	}
	if (sortData[left] > sortData[right]) {
		hold = sortData[left];
		sortData[left] = sortData[right];
		sortData[right] = hold;
	}
	if (sortData[mid] > sortData[right]) {
		hold = sortData[mid];
		sortData[mid] = sortData[right];
		sortData[right] = hold;
	}
	//중간값이 가운데 있음. left와 교환
	hold = sortData[left];
	sortData[left] = sortData[mid];
	sortData[mid] = hold;
}

void quickSort(int sortData[], int left, int right) {
	int sortLeft;
	int sortRight;
	int pivot;
	int hold;

	if ((right - left) > MIZ_SIZE) {
		//quick sort;
		medianLeft(sortData, left, right);
		pivot = sortData[left];
		sortLeft = left + 1;
		sortRight = right;

		while (sortLeft <= sortRight) {
			//오른쪽에 속해야 할 키를 찾는다
			while (sortData[sortLeft] < pivot)
				sortLeft++;
			//오른쪽에 속해야 할 키를 찾는다
			while (sortData[sortRight] >= pivot)
				sortRight--;
			if (sortLeft <= sortRight) {
				hold = sortData[sortLeft];
				sortData[sortLeft] = sortData[sortRight];
				sortData[sortRight] = hold;
				sortLeft++;
				sortRight--;
			}
		}
		//다음 과정을 준비
		sortData[left] = sortData[sortLeft - 1];
		sortData[sortLeft - 1] = pivot;
		if (left < sortRight)
			quickSort(sortData, left, sortRight - 1);
		if (sortLeft < right)
			quickSort(sortData, sortLeft, right);
	}
	else
		//insertion sort
		quickInsertSort(sortData, left, right);
}

int main() {
	int size = 100;
	int *list = new int[size];
	for (int i = 0; i < 100; i++) {
		list[i] = rand() % 100;
		std::cout << list[i] << " ";
		if ((i + 1) % 40 == 0)
			std::cout << std::endl;
	} std::cout << std::endl << std::endl;

	quickSort(list, 0, 99);

	for (int i = 0; i < 100; i++) {
		std::cout << list[i] << " ";
		if ((i + 1) % 40 == 0)
			std::cout << std::endl;
	}
}