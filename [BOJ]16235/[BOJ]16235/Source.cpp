#include <stdio.h>
#include <queue>
#include <algorithm>

using namespace std;

const int dx[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
const int dy[] = { -1, -1, 0, 1, 1, 1, 0, -1 };

struct Tree {
	int r, c;
	int age;

	Tree(int r_, int c_, int age_) : r(r_), c(c_), age(age_) {}
};

class Comp {
public:
	bool operator() (Tree lhs, Tree rhs) {
		return lhs.age > rhs.age;
	}
};

int main() {
	int N, M, K;
	int A[10][10];
	int land[10][10];
	vector<Tree> trees;

	//fill(&land[0][0], &land[0][0] + sizeof(land), 5);
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			land[i][j] = 5;
		}
	}

	scanf("%d%d%d", &N, &M, &K);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &A[i][j]);
		}
	}

	for (int i = 0; i < M; i++) {
		int r, c, age;

		scanf("%d%d%d", &r, &c, &age);

		trees.push_back(Tree(r - 1, c - 1, age));
	}


	for (int year = 0; year < K; year++) {
		//봄
		priority_queue<Tree, vector<Tree>, Comp> pq;
		vector<Tree> trees_dead;
		
		for (int i = 0; i < trees.size(); i++) {
			pq.push(trees[i]);
		}

		trees.clear();

		while(!pq.empty()) {
			Tree tree = pq.top();
			pq.pop();

			if (tree.age > land[tree.r][tree.c]) {
				trees_dead.push_back(tree);
				continue;
			}

			land[tree.r][tree.c] -= tree.age;
			trees.push_back(Tree(tree.r, tree.c, tree.age + 1));
		}

		//여름
		for (Tree tree : trees_dead) {
			land[tree.r][tree.c] += (tree.age / 2);
		}
	
		//가을
		int tree_size = trees.size();
		for (int i = 0; i < tree_size; i++) {
			if (trees[i].age % 5 != 0) continue;
			
			for (int d = 0; d < 8; d++) {
				if (trees[i].r + dy[d] < 0 || trees[i].r + dy[d] >= N ||
					trees[i].c + dx[d] < 0 || trees[i].c + dx[d] >= N) continue;

				trees.push_back(Tree(trees[i].r + dy[d], trees[i].c + dx[d], 1));
			}
		}

		//겨울
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				land[i][j] += A[i][j];
			}
		}
	}

	printf("%d", trees.size());

	return 0;
}

//정렬 내림차순 오름차순을 주의하자.