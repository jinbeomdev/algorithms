//https://www.acmicpc.net/problem/11722

/*
����
���� A�� �־����� ��, ���� �� �����ϴ� �κ� ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

���� ���, ���� A = {10, 30, 10, 20, 20, 10} �� ��쿡 ���� �� �����ϴ� �κ� ������ A = {10, 30, 10, 20, 20, 10}  �̰�, ���̴� 3�̴�.

�Է�
ù° �ٿ� ���� A�� ũ�� N (1 �� N �� 1,000)�� �־�����.

��° �ٿ��� ���� A�� �̷�� �ִ� Ai�� �־�����. (1 �� Ai �� 1,000)

���
ù° �ٿ� ���� A�� ���� �� �����ϴ� �κ� ������ ���̸� ����Ѵ�.

���� �Է�  ����
6
10 30 10 20 20 10
���� ���  ����
3
*/
#include <iostream>
#include <cstring>

using namespace std;

int main() {
	int result = 0;
	int N;
	int arr[1000];
	int dp[1000];
	cin >> N;

	memset(dp, 0, sizeof(dp));
	
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < N; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (arr[j] > arr[i]) {
				if (dp[j] + 1 > dp[i]) {
					dp[i] = dp[j] + 1;
				}
			}
		}
	}

	for (int i = 0; i < N; i++) {
		if (result < dp[i]) {
			result = dp[i];
		}
	}

	cout << result;
	system("pause");
}