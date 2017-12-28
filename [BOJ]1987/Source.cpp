//https://www.acmicpc.net/problem/1987

/*
����
���� Rĭ, ���� Cĭ���� �� ǥ ����� ���尡 �ִ�. ������ �� ĭ���� �빮�� ���ĺ��� �ϳ��� ���� �ְ�, ���� ��� ĭ (1�� 1��) ���� ���� ���� �ִ�.

���� �����¿�� ������ �� ĭ ���� �� ĭ���� �̵��� �� �ִµ�, ���� �̵��� ĭ�� ���� �ִ� ���ĺ��� ���ݱ��� ������ ��� ĭ�� ���� �ִ� ���ĺ����� �޶�� �Ѵ�. ��, ���� ���ĺ��� ���� ĭ�� �� �� ���� �� ����.

���� ��ܿ��� �����ؼ�, ���� �ִ��� �� ĭ�� ���� �� �ִ����� ���ϴ� ���α׷��� �ۼ��Ͻÿ�. ���� ������ ĭ�� ���� ����� ĭ�� ���Եȴ�.

�Է�
ù° �ٿ� R�� C�� ��ĭ�� ���̿� �ΰ� �־�����. (1<=R,C<=20) ��° �ٺ��� R���� �ٿ� ���ļ� ���忡 ���� �ִ� C���� �빮�� ���ĺ����� ��ĭ ���� �־�����.

���
ù° �ٿ� ���� ���� �� �ִ� �ִ��� ĭ ���� ����Ѵ�.

���� �Է�  ����
2 4
CAAB
ADCB
���� ���  ����
3
*/
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

#define alpha_size 'Z' - 'A' + 1	

int answer = 0;
char space[20][20];
bool alpha[alpha_size];
int R, C;

int iter_x[] = { 1, 0, -1, 0 };
int iter_y[] = { 0, 1, 0, -1 };

void dfs(int y, int x, int cnt_movement) {
	if (answer < cnt_movement) {
		answer = cnt_movement;
	}

	for (int i = 0; i < 4; i++) {
		int next_y = y + iter_y[i];
		int next_x = x + iter_x[i];

		if (next_y >= 0 && next_y < R &&
			next_x >= 0 && next_x < C) {
 			if (!alpha['Z' - space[next_y][next_x]]) {
				alpha['Z' - space[next_y][next_x]] = true;
				dfs(next_y, next_x, cnt_movement + 1);
				alpha['Z' - space[next_y][next_x]] = false;
			}
		}
	}
}

int main() {
	memset(alpha, false, sizeof(alpha));

	cin >> R >> C;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> space[i][j];
		}
	}

	alpha['Z' - space[0][0]] = true;
	dfs(0, 0, 1);

	cout << answer;
	system("pause");
}