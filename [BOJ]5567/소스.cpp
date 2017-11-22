/*
https://www.acmicpc.net/problem/5567

����
����̴� �ڽ��� ��ȥ�Ŀ� �б� ���� �� �ڽ��� ģ���� ģ���� ģ���� �ʴ��ϱ�� �ߴ�. ������� ����� ��� N���̰�, �� �л����� �й��� ��� 1���� N�����̴�. ������� �й��� 1�̴�.

����̴� ������� ģ�� ���踦 ��� ������ ����Ʈ�� ������ �ִ�. �� ����Ʈ�� �������� ��ȥ�Ŀ� �ʴ��� ����� ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� ������� ������ �� n (2 �� n �� 500)�� �־�����. ��° �ٿ��� ����Ʈ�� ���� m (1 �� m �� 10000)�� �־�����. ���� �ٺ��� m�� �ٿ��� ģ�� ���� ai bi�� �־�����. (1 �� ai < bi �� n) ai�� bi�� ģ����� ���̸�, bi�� ai�� ģ�������̴�.

���
ù° �ٿ� ������� ��ȥ�Ŀ� �ʴ��ϴ� ������ ���� ����Ѵ�.

���� �Է�  ����
6
5
1 2
1 3
3 4
2 3
4 5
���� ���  ����
3
*/

#include <iostream>
#include <cstring>
using namespace std;

int main() {
	int n, m;
	int friends[501][501];
	int invited_frineds[501];

	memset(friends, -1, sizeof(friends));
	memset(invited_frineds, -1, sizeof(invited_frineds));
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int friend_1, friend_2;

		cin >> friend_1 >> friend_2;

		friends[friend_1][friend_2] = 1;
		friends[friend_2][friend_1] = 1;
	}

	for (int i = 2; i <= n; i++) {
		if (friends[1][i] != 1) continue; //ģ���� �ƴ� ���

		int my_friend = i;

		invited_frineds[i] = 1;
		
		for (int j = 2; j <= n; j++) {
			if (friends[i][j] != 1) continue; //ģ���� ģ���� �ƴ� ���
			
			int my_friend_of_friend = j;

			invited_frineds[j] = 1;
		}
	}

	int num_invited_friends = 0;
	for (int i = 2; i <= n; i++) {
		if (invited_frineds[i] == 1) num_invited_friends++;
	}

	cout << num_invited_friends;
}