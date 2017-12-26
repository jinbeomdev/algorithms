//https://www.acmicpc.net/problem/1427

/*
문제
배열을 정렬하는 것은 쉽다. 숫자가 주어지면, 그 숫자의 각 자리수를 내림차순으로 정렬해보자.

입력
첫째 줄에 정렬하고자하는 수 N이 주어진다. N은 1,000,000,000보다 작거나 같다.

출력
둘째 줄에 숫자의 자리수를 내림차순으로 정렬한 수를 출력한다.

예제 입력  복사
2143
예제 출력  복사
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