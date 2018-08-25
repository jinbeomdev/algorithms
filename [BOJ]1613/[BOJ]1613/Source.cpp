#include <cstdio>
#include <vector>

using namespace std;

//사건의 개수 n
//알고있는 전후 관계의 수 k
//알고 싶은 사건의 쌍의 수 s
int n, k, s;
vector<vector<int>> map;
vector<int> order;

bool dfs(int here, int dest) {
	bool ret = false;
	if (here == dest) {
		return ret = true;;
	}

	for (auto there : map[here]) {
		if (ret = dfs(there, dest)) return ret;
	}

	return ret;
}

int main() {
	scanf("%d%d", &n, &k);

	map = vector<vector<int>>(n);
	for (int i = 0; i < k; i++) {
		int before, after;
		scanf("%d%d", &before, &after);
		map[before - 1].push_back(after - 1);
	}

	scanf("%d", &s);

	for (int i = 0; i < s; i++) {
		int case1, case2;
		scanf("%d%d", &case1, &case2);
		case1--; case2--;
		if (dfs(case1, case2)) {
			puts("-1");
		} else if (dfs(case2, case1)) {
			puts("1");
		} else {
			puts("0");
		}
	}
}