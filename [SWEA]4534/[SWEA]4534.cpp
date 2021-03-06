/*
4534. 트리 흑백 색칠 D5
*/

#include <cstdio>
#include <vector>

using namespace std;

const int mod = 1000000007;

enum Color { BLACK, WHITE };
const char *color[] = {
	"BLACK",
	"WHITE"
};

void solution(vector<pair<int, Color>> &tree,
	           int idx,
	           int &result) {
	if (idx == tree.size()) {
		for (int i = 1; i < tree.size(); i++) {
			if (tree[i].first == 0) continue; //leaf node

			if (tree[i].second == BLACK &&
				  tree[tree[i].first].second == BLACK) {
				return;
			}
		}

		for (int i = 1; i < tree.size(); i++) {
			printf("%d:%s\n",
				i, color[tree[i].second]);
		}
		putchar('\n');
		result++;
		return;
	}

	tree[idx].second = BLACK;
	solution(tree, idx + 1, result);
	tree[idx].second = WHITE;
	solution(tree, idx + 1, result);

	return;
}

int main() {
	int test_case_num;
	int N;
	int x, y;

	vector<pair<int, Color>> tree;

	int result;

	scanf("%d", &test_case_num);

	for (int test_case = 1; test_case <= test_case_num; test_case++) {
		scanf("%d", &N);

		tree.clear();
		tree.resize(N + 1);

		result = 0;

		for (int edge_num = 1; edge_num < N; edge_num++) {
			scanf("%d %d", &x, &y);

			tree[x] = make_pair(y, BLACK);
		}

		solution(tree, 1, result);
		printf("#%d %d\n", test_case, result);
	}
	//system("pause");

	return 0;
}