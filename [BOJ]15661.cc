#include <stdio.h>
#include <vector>
#include <stdlib.h>

using namespace std;

int N;
int senergy[20][20];
vector<int> a;
vector<int> b;
int answer = 1e9;

void dfs(int idx) {
	if(idx == N) {
		if(a.empty() || b.empty()) return;
		int sum_a = 0, sum_b = 0;
		for(int i = 0 ; i < a.size(); i++) {
			for(int j = i + 1; j < a.size(); j++) {
				sum_a = sum_a + senergy[a[i]][a[j]] + senergy[a[j]][a[i]];
			}
		}
		for(int i = 0; i < b.size(); i++) {
			for(int j = i  + 1; j < b.size(); j++) {
				sum_b = sum_b + senergy[b[i]][b[j]] + senergy[b[j]][b[i]];
			}
		}
		if(answer > abs(sum_a - sum_b)) {
			answer = abs(sum_a - sum_b);
		}
		return;
	}
	
	a.push_back(idx);
	dfs(idx + 1);
	a.pop_back();

	b.push_back(idx);
	dfs(idx + 1);
	b.pop_back();
}

int main() {
	scanf("%d", &N);

	for(int i = 0; i < N; i++) {
		for(int j =0; j < N; j++) {
			scanf("%d", &senergy[i][j]);	
		}
	}

	dfs(0);
	printf("%d", answer);
	return 0;
}
