//https://www.acmicpc.net/problem/11055

/*
����
���� A�� �־����� ��, �� ������ ���� �κ� ���� �߿��� ���� ���� ū ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

���� ���, ���� A = {1, 100, 2, 50, 60, 3, 5, 6, 7, 8} �� ��쿡 ���� ���� ū ���� �κ� ������ A = {1, 100, 2, 50, 60, 3, 5, 6, 7, 8} �̰�, ���� 113�̴�.

�Է�
ù° �ٿ� ���� A�� ũ�� N (1 �� N �� 1,000)�� �־�����.

��° �ٿ��� ���� A�� �̷�� �ִ� Ai�� �־�����. (1 �� Ai �� 1,000)

���
ù° �ٿ� ���� A�� ���� ���� ū ���� �κ� ������ ���� ����Ѵ�.

���� �Է�  ����
10
1 100 2 50 60 3 5 6 7 8
���� ���  ����
113
*/
#include <iostream>
#include <cstring>

using namespace std;

int main() {
	int arr[1000];
	int dp[1000];
	int N;

	memset(arr, 0, sizeof(arr));

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < N; i++) {
		dp[i] = arr[i];
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i]) {
				if (dp[j] + arr[i] > dp[i]) {
					dp[i] = dp[j] + arr[i];
				}
			}
		}
	}

	int answer = 0;
	for (int i = 0; i < N; i++) {
		if (answer < dp[i]) {
			answer = dp[i];
		}
	}

	cout << answer;
}