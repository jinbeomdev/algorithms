//https://www.acmicpc.net/problem/2096

/*
문제
N줄에 0 이상 9 이하의 숫자가 세 개씩 적혀 있다. 내려가기 게임을 하고 있는데, 이 게임은 첫 줄에서 시작해서 마지막 줄에서 끝나게 되는 놀이이다.

먼저 처음에 적혀 있는 세 개의 숫자 중에서 하나를 골라서 시작하게 된다. 그리고 다음 줄로 내려가는데, 다음 줄로 내려갈 때에는 다음과 같은 제약 조건이 있다. 바로 아래의 수로 넘어가거나, 아니면 바로 아래의 수와 붙어 있는 수로만 이동할 수 있다는 것이다. 이 제약 조건을 그림으로 나타내어 보면 다음과 같다.



별표는 현재 위치이고, 그 아랫 줄의 파란 동그라미는 원룡이가 다음 줄로 내려갈 수 있는 위치이며, 빨간 가위표는 원룡이가 내려갈 수 없는 위치가 된다. 숫자표가 주어져 있을 때, 얻을 수 있는 최대 점수, 최소 점수를 구하는 프로그램을 작성하시오. 점수는 원룡이가 위치한 곳의 수의 합이다.

입력
첫째 줄에 N(1 ≤ N ≤ 100,000)이 주어진다. 다음 N개의 줄에는 숫자가 세 개씩 주어진다. 숫자는 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 중의 하나가 된다.

출력
첫째 줄에 얻을 수 있는 최대 점수와 최소 점수를 띄어서 출력한다.

예제 입력
3
1 2 3
4 5 6
4 9 0
예제 출력
18 6
*/
#include <iostream>
#include <vector>
#include <algorithm>

const int P_INF = 10e6;
const int N_INF = -10e6;

const int iter_x[] = { -1, 0, 1 };
const int iter_size = 3;

int N;
std::vector<std::vector<int>> adj;
std::vector<std::vector<std::pair<int, int>>> dp;

std::pair<int, int> dfs(int y, int x) {
	std::pair<int, int> &ret = dp[y][x];
	int &min_ret = dp[y][x].first;
	int &max_ret = dp[y][x].second;

	if (y == N - 1) {
		return { adj[y][x], adj[y][x] };
	}

	if (min_ret != P_INF && max_ret != N_INF) {
		return ret;
	}

	for (int i = 0; i < iter_size; i++) {
		int next_y = y + 1;
		int next_x = x + iter_x[i];

		if (next_y >= 0 && next_y < N &&
			next_x >= 0 && next_x < N) {
			min_ret = std::min(min_ret, dfs(next_y, next_x).first + adj[y][x]);
			max_ret = std::max(max_ret, dfs(next_y, next_x).second + adj[y][x]);
		}
	}

	return ret;
}

int main() {

	std::cin >> N;

	adj = std::vector<std::vector<int>>(N, std::vector<int>(3));
	/* pair saves minmax value */
	dp = std::vector<std::vector<std::pair<int, int>>>(3);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			std::cin >> adj[i][j];
		}
	}

	std::pair<int, int> ret = { P_INF, N_INF };
	for (int i = 0; i < 3; i++) {
		std::pair<int, int> temp_ret = dfs(0, i);
		ret.first = std::min(ret.first, temp_ret.first);
		ret.second = std::max(ret.second, temp_ret.second);
	}
	
	std::cout << ret.second << " " << ret.first << std::endl;
	//std::system("pause");
}