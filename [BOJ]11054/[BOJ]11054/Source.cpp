#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int N;
int arr[1000];
int cache[1000][2];

//start���� ������ ���� �� ������� ������ ����
//order�� 0�̸� ��������, 1�̸� ��������
int bitonic(int start, int order) {
	int& ret = cache[start][order];
	if (ret != -1) return ret;
	ret = 1; //�ּ��� ���̰� 1��.
	int max_value = 0;
	for (int i = start + 1; i < N; i++) {
		if (order == 0) {
			if (arr[i] > arr[start]) {
				max_value = max(max_value, bitonic(i, 0));
			} else if (arr[i] < arr[start]) {
				max_value = max(max_value, bitonic(i, 1));
			}
		} else {
			if (arr[i] < arr[start]) {
				max_value = max(max_value, bitonic(i, 1));
			}
		}
	}
	ret += max_value;
	return ret;
}

int main() {
	memset(arr, 1, sizeof(arr));
	memset(cache, -1, sizeof(cache));
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}
	int ret = 0;
	for (int i = 0; i < N; i++) {
		bitonic(i, 0);
		bitonic(i, 1);
	}

	for (int j = 0; j < 2; j++) {
		for (int i = 0; i < N; i++) {
			ret = max(ret, cache[i][j]);
		}
	}
	printf("%d", ret);
	return 0;
}