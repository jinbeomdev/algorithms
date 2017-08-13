#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//������ ũ�� N(���簢���̹Ƿ� ���ο� ������ ũ��� ������ 5��N��25)
int N;

vector<vector<int>> adj;
vector<vector<int>> visited;

int X[] = { 0, 1, 0, -1 };
int Y[] = { -1, 0, 1, 0 };

//������Ʈ�� ���� ���� ��ȯ
int dfs(int y, int x) {
	//�ش� ������Ʈ�� ���� ����
	int num = 1;

	visited[y][x] = 1;

	//������ ������ �湮
	for (int i = 0; i < 4; i++) {
		//�湮���� ���� ������ �湮
		if (y + Y[i] >= 0 && y + Y[i] < N && x + X[i] >= 0 && x + X[i] < N &&
			!visited[y + Y[i]][x + X[i]] && adj[y + Y[i]][x + X[i]] == 1) {
			num += dfs(y + Y[i], x + X[i]);
		}
	}

	return num;
}

int main() {
	//component�� ����
	vector<int> component;
	
	//ù ��° �ٿ��� ������ ũ�� N(���簢���̹Ƿ� ���ο� ������ ũ��� ������ 5��N��25)�� �Էµǰ�,
	cin >> N;

	adj = vector<vector<int>>(N, vector<int>(N, 0));
	visited = vector<vector<int>>(N, vector<int>(N, 0));

	//�� ���� N�ٿ��� ���� N���� �ڷ�(0Ȥ�� 1)�� �Էµȴ�.
	for (int i = 0; i < N; i++) {
		string s;

		cin >> s;

		for (int j = 0; j < s.size(); j++) {
			adj[i][j] = s[j] - '0';
		}
	}

	//��� ������ ��ȸ�ϸ鼭, ���� �湮�� �� ������ �湮�Ѵ�.
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