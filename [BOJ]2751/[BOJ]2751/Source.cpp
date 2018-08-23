#include <cstdio>

int arr[1000000];

void insertionSort(int size) {
	int current;
	int hold;
	int walker;

	for (current = 1; current < size; current++) {
		hold = arr[current];
		walker = current - 1;

		while (walker >= 0 && arr[walker] > hold) {
			arr[walker + 1] = arr[walker];
			walker--;
		}
		arr[walker + 1] = hold;
	}
}

void quickSort(int left, int right) {
	int pivot;
	int hold;
	int sort_left;
	int sort_right;

	pivot = arr[left];
	sort_left = left + 1;
	sort_right = right;

	while (sort_left <= sort_right) {
		while (sort_left <= sort_right && arr[sort_left] < pivot) {
			sort_left++;
		}

		while (sort_left <= sort_right && arr[sort_right] >= pivot) {
			sort_right--;
		}
		
		if (sort_left < sort_right) {
			hold = arr[sort_left];
			arr[sort_left] = arr[sort_right];
			arr[sort_right] = hold;
			sort_left++;
			sort_right--;
		}
	}

	arr[left] = arr[sort_left - 1];
	arr[sort_left - 1] = pivot;
	if (left < sort_right) {
		quickSort(left, sort_right - 1);
	}

	if (sort_left < right) {
		quickSort(sort_left, right);
	}
}

int main() {
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	//insertionSort(N);
	quickSort(0, N - 1);

	for (int i = 0; i < N; i++) {
		printf("%d\n", arr[i]);
	}
}