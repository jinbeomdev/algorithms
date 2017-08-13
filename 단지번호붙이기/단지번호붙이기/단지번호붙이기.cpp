#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//지도의 크기 N(정사각형이므로 가로와 세로의 크기는 같으며 5≤N≤25)
int N;

vector<vector<int>> adj;
vector<vector<int>> visited;

int X[] = { 0, 1, 0, -1 };
int Y[] = { -1, 0, 1, 0 };

//컴포넌트의 원소 개수 반환
int dfs(int y, int x) {
	//해당 컴포넌트의 원소 개수
	int num = 1;

	visited[y][x] = 1;

	//인정한 정점에 방문
	for (int i = 0; i < 4; i++) {
		//방문하지 않은 정점에 방문
		if (y + Y[i] >= 0 && y + Y[i] < N && x + X[i] >= 0 && x + X[i] < N &&
			!visited[y + Y[i]][x + X[i]] && adj[y + Y[i]][x + X[i]] == 1) {
			num += dfs(y + Y[i], x + X[i]);
		}
	}

	return num;
}

int main() {
	//component의 개수
	vector<int> component;
	
	//첫 번째 줄에는 지도의 크기 N(정사각형이므로 가로와 세로의 크기는 같으며 5≤N≤25)이 입력되고,
	cin >> N;

	adj = vector<vector<int>>(N, vector<int>(N, 0));
	visited = vector<vector<int>>(N, vector<int>(N, 0));

	//그 다음 N줄에는 각각 N개의 자료(0혹은 1)가 입력된다.
	for (int i = 0; i < N; i++) {
		string s;

		cin >> s;

		for (int j = 0; j < s.size(); j++) {
			adj[i][j] = s[j] - '0';
		}
	}

	//모든 정점을 순회하면서, 아직 방문한 적 없으면 방문한다.
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j] && adj[i][j] == 1) {
				component.push_back(dfs(i, j));
			}
		}
	}

	sort(component.begin(), component.end());

	cout << component.size() << endl;

	for (int i = 0; i < component.size(); i++) {
		cout << component[i] << endl;
	}
}