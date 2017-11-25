/*
https://www.acmicpc.net/problem/1697

문제
수빈이는 동생과 숨바꼭질을 하고 있다. 수빈이는 현재 점 N(0 ≤ N ≤ 100,000)에 있고, 동생은 점 K(0 ≤ K ≤ 100,000)에 있다. 수빈이는 걷거나 순간이동을 할 수 있다. 만약, 수빈이의 위치가 X일 때 걷는다면 1초 후에 X-1 또는 X+1로 이동하게 된다. 순간이동을 하는 경우에는 1초 후에 2*X의 위치로 이동하게 된다.

수빈이와 동생의 위치가 주어졌을 때, 수빈이가 동생을 찾을 수 있는 가장 빠른 시간이 몇 초 후인지 구하는 프로그램을 작성하시오.

입력
첫 번째 줄에 수빈이가 있는 위치 N과 동생이 있는 위치 K가 주어진다.

출력
수빈이가 동생을 찾는 가장 빠른 시간을 출력한다.

예제 입력  복사
5 17
예제 출력  복사
4
힌트
수빈이가 5-10-9-18-17 순으로 가면 4초만에 동생을 찾을 수 있다.
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