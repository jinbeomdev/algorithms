#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

const int dx[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
const int dy[] = { -1, -1, 0, 1, 1, 1, 0, -1 };

struct Tree {
	int age;
	bool alive;
	int year_dead;

	Tree(int age_) : age(age_), alive(true) {}
};

bool Comp(const Tree &a, const Tree &b) {
	return a.age < b.age;
}

int main() {
	int N, M, K;
	int A[10][10];
	int land[10][10];
	vector<Tree> trees[10][10];

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

		trees[r - 1][c - 1].push_back(Tree(age));
	}

	for (int year = 0; year < K; year++) {
		//봄
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				sort(trees[i][j].begin(), trees[i][j].end(), Comp);

				for (int k = 0; k < trees[i][j].size(); k++) {
					if (trees[i][j][k].alive == false) continue;

					if (trees[i][j][k].age > land[i][j]) {
						trees[i][j][k].alive = false;
						trees[i][j][k].year_dead = year;
						continue;
					}

					land[i][j] -= trees[i][j][k].age;
					trees[i][j][k].age++;
				}
			} 
		}

		//여름
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				for (int k = 0; k < trees[i][j].size(); k++) {
					if (trees[i][j][k].alive) continue;

					if (trees[i][j][k].year_dead != year) continue;

					land[i][j] += trees[i][j][k].age / 2;
				}
			}
		}

		//가을
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				for (int k = 0; k < trees[i][j].size(); k++) {
					if (trees[i][j][k].alive == false) continue;

					if (trees[i][j][k].age % 5 != 0) continue;

					for (int d = 0; d < 8; d++) {
						if (i + dy[d] < 0 || i + dy[d] >= N ||
							  j + dx[d] < 0 || j + dx[d] >= N) continue;

						trees[i + dy[d]][j + dx[d]].push_back(Tree(1));
					}
				}
			}
		}

		//겨울
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				land[i][j] += A[i][j];
			}
		}
	}

	int ret = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < trees[i][j].size(); k++) {
				if (trees[i][j][k].alive) ret++;
			}
		}
	}

	printf("%d", ret);

	return 0;
}