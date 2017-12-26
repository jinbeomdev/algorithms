//https://www.acmicpc.net/problem/1427

/*
����
�迭�� �����ϴ� ���� ����. ���ڰ� �־�����, �� ������ �� �ڸ����� ������������ �����غ���.

�Է�
ù° �ٿ� �����ϰ����ϴ� �� N�� �־�����. N�� 1,000,000,000���� �۰ų� ����.

���
��° �ٿ� ������ �ڸ����� ������������ ������ ���� ����Ѵ�.

���� �Է�  ����
2143
���� ���  ����
4321
*/
#include <iostream>
#include <cstring> //memset

using namespace std;

const int _max = 10;

int main() {
	int N;
	int num[10];

	memset(num, 0, sizeof(num));

	cin >> N;

	int size;
	for (size = 0; size < _max; size++) {
		if (N == 0) {
			break;
		}
		num[size] = N % 10;
		N /= 10;
	}

	int highest;
	int hold_data;
	for (int current = 0; current < size; current++) {
		highest = current;
		for (int walker = current + 1; walker < size; walker++) {
			if (num[walker] > num[highest]) {
				highest = walker;
			}
		}
		hold_data = num[highest];
		num[highest] = num[current];
		num[current] = hold_data;
	}

	for (int j = 0; j < size; j++) {
		cout << num[j];
	}
}