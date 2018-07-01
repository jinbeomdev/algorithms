#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> houses;
vector<pair<int, int>> chickens;
int n, m;
int answer = 1e9;
void dfs(int idx, int cnt, vector<bool> selected);
int getDistance(pair<int, int> house, pair<int, int> chicken);
int main() {
	scanf("%d %d", &n, &m);
	int mat[51][51] = { 0, };

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &mat[i][j]);
			if (mat[i][j] == 1) houses.push_back({ i , j });
			else if (mat[i][j] == 2) chickens.push_back({ i,j });
		}
	}
	vector<bool> selected(chickens.size(), false);
	dfs(0, 0, selected);

	printf("%d", answer);
	return 0;
}
void dfs(int idx, int cnt, vector<bool> selected) {
	if (cnt == m) {
		//�Ÿ����
		int sum = 0;
		for (int i = 0; i < houses.size(); i++) {
			int min = 1e9;
			int temp = 0;
			for (int j = 0; j < chickens.size(); j++) {
				if (selected[j]) {
					temp = getDistance(houses[i], chickens[j]);
					if (temp < min) min = temp;
				}
			}
			sum += min;
		}
		if (sum < answer) answer = sum;
		return;
	}

	if (idx == chickens.size()) {
		return;
	}

	//��� ġŲ �� �� �� ����
	selected[idx] = false;
	dfs(idx + 1, cnt, selected); //���þ���
	selected[idx] = true;
	dfs(idx + 1, cnt + 1, selected); //������
}

int getDistance(pair<int, int> house, pair<int, int> chicken) {
	return(abs(house.first - chicken.first) + abs(house.second - chicken.second));
}