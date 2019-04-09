#include <stdio.h>
#include <vector>

using namespace std;

int N;
vector<int> beads;
int answer = 0;

void dfs(int mul, int cnt) {
	if (cnt == N - 2) {
		if (answer < mul) answer = mul;
		return;
	}

	for (int i = 1; i < beads.size() - 1; i++) {
		if (!beads[i]) continue;

		int left = i - 1;
		int right = i + 1;
		while (beads[left] == 0) {
			left--;
		}
		while (beads[right] == 0) {
			right++;
		}
		
		int temp = beads[i];
		beads[i] = 0;
		dfs(mul + beads[left] * beads[right], cnt + 1);
		beads[i] = temp;
	}
}

int main() {
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		int a;
		scanf("%d", &a);
		beads.push_back(a);
	}

	dfs(0, 0);
	printf("%d", answer);
}