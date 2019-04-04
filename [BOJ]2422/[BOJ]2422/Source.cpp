#include <stdio.h>
#include <vector>

using namespace std;

int N, M;
bool bad_comb[201][201] = { false, };
vector<int> selecte_ice;
int answer;

void dfs(int idx, int cnt) {
	if (cnt == 3) {
		for (int i = 0; i < selecte_ice.size(); i++) {
			for (int j = i + 1; j < selecte_ice.size(); j++) {
				if (bad_comb[selecte_ice[i]][selecte_ice[j]]) return;
			}
		}
		answer++;
		return;
	}

	if (idx > N) {
		return;
	}

	dfs(idx + 1, cnt);

	selecte_ice.push_back(idx);
	dfs(idx + 1, cnt + 1);
	selecte_ice.pop_back();
}

int main() {
	answer = 0;
	scanf("%d%d", &N, &M);
	for (int i = 0; i < M; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		bad_comb[a][b] = true;
		bad_comb[b][a] = true;
	}
	dfs(1, 0);
	printf("%d", answer);
}