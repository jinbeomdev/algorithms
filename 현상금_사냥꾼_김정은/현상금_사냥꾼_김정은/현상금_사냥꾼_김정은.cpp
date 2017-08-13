#include <iostream>
#include <vector>
#include <algorithm>

#define INF DOUBLE_MAX
using namespace std;

int N;
vector<pair<int, int>> vertexs;
vector<bool> visited;

int shortestPath(vector<int> &path,
	vector<bool> &visited,
	double currentLength) {
	//shortestPath
	if (path.size() == N) {
		return currentLength +
			sqrt(pow(vertexs[0].first - vertexs[path.back()].first, 2) +
			pow(vertexs[0].second - vertexs[path.back()].second, 2));
	}

	double ret = numeric_limits<double>::max();

	for (int i = 0; i < N; i++) {

	}
}

int main() {
	int T, test_case;

	cin >> T;

	for (test_case = 0; test_case < T; test_case++) {


		cin >> N;

		vertexs = vector<pair<int, int>>(N);
		visited = vector<bool>(N, 0);

		for (int i = 0; i < N; i++) {
			int x, y;
			cin >> x >> y;
			vertexs[i] = make_pair(x, y);
		}

		sort(vertexs.begin(), vertexs.end());
	}
}