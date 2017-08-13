#include <iostream>

bool jollyJumpers(int arr[], int size)  {
	int setSize = size - 1;
	int *set = new int[setSize]; //����

	//���� �迭 �ʱ�ȭ �ϱ�
	for (int i = 0; i < setSize; i++) {
		set[i] = 0;
	}

	//�� ���� ���� ���տ� �����ϱ�
	for (int i = 0; i < setSize; i++) {
		set[i] = abs(arr[i] - arr[i + 1]);
	}

	//������ �Ǳ� ���ؼ��� �� ���ҵ��� �����ؾ� �Ѵ�.
	//�׷��Ƿ� �ߺ��� �Ǵ� ���Ҵ� �����Ѵ�.
	//���⼭ ������ ������ ���ҵ��� 0���� ū ���̴�.
	//���࿡ �ߺ��� �Ǵ� ���Ұ� ���� ��쿡�� 0���� �ʱ�ȭ �Ѵ�.
	for (int i = 0; i < setSize; i++) {
		for (int j = 0; j < setSize; j++) {
			if (set[i] == set[j] && i != j)
				set[i] = 0;
		}
	}

	//jolly Jumpers�� ������ �����ϴ� Ȯ�� �ϱ� ���ؼ� ������ �����Ѵ�.
	//�����ϴ� �˰������δ� ���� ������ ����Ѵ�.
	for (int j = 1; j < setSize; j++) {
		int key = set[j];
		int i = j - 1;
		
		while (i >= 0 && key > set[i]) {
			set[i + 1] = set[i];
			i--;
		}

		set[i + 1] = key;
	}

	//���� ���ĵ� �����̹Ƿ� n-1���� 1������ ���� ���տ� ������� ������ jolly�ϴ�.
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
		std::cout << "����";
	}
	else {
		std::cout << "������";
	}
}