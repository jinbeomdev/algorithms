#include <iostream>

bool jollyJumpers(int arr[], int size)  {
	int setSize = size - 1;
	int *set = new int[setSize]; //집합

	//집합 배열 초기화 하기
	for (int i = 0; i < setSize; i++) {
		set[i] = 0;
	}

	//두 수의 차를 집합에 저장하기
	for (int i = 0; i < setSize; i++) {
		set[i] = abs(arr[i] - arr[i + 1]);
	}

	//집합이 되기 위해서는 각 원소들은 유일해야 한다.
	//그러므로 중복이 되는 원소는 제거한다.
	//여기서 조건은 집합의 원소들은 0보다 큰 수이다.
	//만약에 중복이 되는 원소가 있을 경우에는 0으로 초기화 한다.
	for (int i = 0; i < setSize; i++) {
		for (int j = 0; j < setSize; j++) {
			if (set[i] == set[j] && i != j)
				set[i] = 0;
		}
	}

	//jolly Jumpers의 조건을 만족하는 확인 하기 위해서 집합을 정렬한다.
	//정렬하는 알고리즘으로는 선택 정렬을 사용한다.
	for (int j = 1; j < setSize; j++) {
		int key = set[j];
		int i = j - 1;
		
		while (i >= 0 && key > set[i]) {
			set[i + 1] = set[i];
			i--;
		}

		set[i + 1] = key;
	}

	//이제 정렬된 집합이므로 n-1부터 1까지의 값이 집합에 순서대로 있으면 jolly하다.
	int n = setSize;
	for (int i = 0; i < setSize; i++) {
		if (!(set[i] == n--))
			return false;
	}

	return true;
}

int main() {
	int arr[] = { 1,4,2,-1,6 };
	int size = 5;
	
	bool jolly = jollyJumpers(arr, size);

	if (jolly) {
		std::cout << "졸리";
	}
	else {
		std::cout << "안졸리";
	}
}