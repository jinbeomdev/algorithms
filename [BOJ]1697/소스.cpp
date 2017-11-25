/*
https://www.acmicpc.net/problem/1697

����
�����̴� ������ ���ٲ����� �ϰ� �ִ�. �����̴� ���� �� N(0 �� N �� 100,000)�� �ְ�, ������ �� K(0 �� K �� 100,000)�� �ִ�. �����̴� �Ȱų� �����̵��� �� �� �ִ�. ����, �������� ��ġ�� X�� �� �ȴ´ٸ� 1�� �Ŀ� X-1 �Ǵ� X+1�� �̵��ϰ� �ȴ�. �����̵��� �ϴ� ��쿡�� 1�� �Ŀ� 2*X�� ��ġ�� �̵��ϰ� �ȴ�.

�����̿� ������ ��ġ�� �־����� ��, �����̰� ������ ã�� �� �ִ� ���� ���� �ð��� �� �� ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù ��° �ٿ� �����̰� �ִ� ��ġ N�� ������ �ִ� ��ġ K�� �־�����.

���
�����̰� ������ ã�� ���� ���� �ð��� ����Ѵ�.

���� �Է�  ����
5 17
���� ���  ����
4
��Ʈ
�����̰� 5-10-9-18-17 ������ ���� 4�ʸ��� ������ ã�� �� �ִ�.
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int get_next_postion(int num, int subin_postion) {
	switch (num)
	{
	case 0:
		return subin_postion + 1;
		break;
	case 1:
		return subin_postion - 1;
		break;
	case 2:
		return subin_postion * 2;
		break;
	default:
		break;
	}
}

int main() {
	int N, K;
	vector<bool> visited = vector<bool>(100001, false);
	int best_time = 1e10;
	queue<pair<int, int>> q;
	
	cin >> N >> K;

	q.push({ N, 0 });

	while (!q.empty()) {
		int subin_postion = q.front().first;
		int current_time = q.front().second;
		q.pop();

		if (subin_postion == K && best_time > current_time) {
			best_time = current_time;
			break;
		}

		for (int i = 0; i < 3; i++) {
			int next_postion = get_next_postion(i, subin_postion);

			if (next_postion < 0 || next_postion > 100000) {
				continue;
			}

			int next_time = current_time + 1;

			if (visited[next_postion] == false) {
				q.push({ next_postion, next_time });
				visited[next_postion] = true;
			}
		}
	}

	cout << best_time;
}