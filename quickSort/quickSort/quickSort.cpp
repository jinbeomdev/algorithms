#include <iostream>

//Knuth�� ������ ��Ƽ���� ũ�⿡���� insert sort�� ����ϱ⸦ ����.
//������ ��Ƽ���� ũ�⸦ �����ϴ� ���� ������ ����� ��
//���⼭�� �ù����� 4�� �ϱ�� ������, �� å������ 16�� �ϱ�� �ߴ�.
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
	//�߰��� ���� ������� singleton algorithm�� ���
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
	//�߰����� ��� ����. left�� ��ȯ
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
			//�����ʿ� ���ؾ� �� Ű�� ã�´�
			while (sortData[sortLeft] < pivot)
				sortLeft++;
			//�����ʿ� ���ؾ� �� Ű�� ã�´�
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
		//���� ������ �غ�
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