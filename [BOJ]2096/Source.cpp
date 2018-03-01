//https://www.acmicpc.net/problem/2096

/*
����
N�ٿ� 0 �̻� 9 ������ ���ڰ� �� ���� ���� �ִ�. �������� ������ �ϰ� �ִµ�, �� ������ ù �ٿ��� �����ؼ� ������ �ٿ��� ������ �Ǵ� �����̴�.

���� ó���� ���� �ִ� �� ���� ���� �߿��� �ϳ��� ��� �����ϰ� �ȴ�. �׸��� ���� �ٷ� �������µ�, ���� �ٷ� ������ ������ ������ ���� ���� ������ �ִ�. �ٷ� �Ʒ��� ���� �Ѿ�ų�, �ƴϸ� �ٷ� �Ʒ��� ���� �پ� �ִ� ���θ� �̵��� �� �ִٴ� ���̴�. �� ���� ������ �׸����� ��Ÿ���� ���� ������ ����.



��ǥ�� ���� ��ġ�̰�, �� �Ʒ� ���� �Ķ� ���׶�̴� �����̰� ���� �ٷ� ������ �� �ִ� ��ġ�̸�, ���� ����ǥ�� �����̰� ������ �� ���� ��ġ�� �ȴ�. ����ǥ�� �־��� ���� ��, ���� �� �ִ� �ִ� ����, �ּ� ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�. ������ �����̰� ��ġ�� ���� ���� ���̴�.

�Է�
ù° �ٿ� N(1 �� N �� 100,000)�� �־�����. ���� N���� �ٿ��� ���ڰ� �� ���� �־�����. ���ڴ� 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 ���� �ϳ��� �ȴ�.

���
ù° �ٿ� ���� �� �ִ� �ִ� ������ �ּ� ������ �� ����Ѵ�.

���� �Է�
3
1 2 3
4 5 6
4 9 0
���� ���
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