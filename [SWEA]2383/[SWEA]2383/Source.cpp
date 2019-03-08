#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

struct Pos {
	int x, y;
};

int T, N;
int num_h, num_s;
Pos h[10];
Pos s[2];
int time_s[2];
int answer;

void dfs(int n, vector<int> s1, vector<int> s2) {
	if (n == num_h) {
		sort(s1.begin(), s1.end());
		sort(s2.begin(), s2.end());

		for (int i = 0; i < s1.size(); i++) {
			if (i < s1.size() && i < 3) {
				s1[i]++;
			}

			if (i + 3 < s1.size() && s1[i] + time_s[0] > s1[i + 3]) {
				s1[i + 3] = s1[i] + time_s[0];
			}
			
			else if (i + 3 < s1.size() && s1[i] + time_s[0] == s1[i + 3]) {
				s1[i + 3] = s1[i] + time_s[0] + 1;
			}

			else if(i + 3 < s1.size()){
				s1[i + 3]++;
			}
		}

		for (int i = 0; i < s2.size(); i++) {
			if (i < s2.size() && i < 3) {
				s2[i]++;
			}

			if (i + 3 < s2.size() && s2[i] + time_s[1] > s2[i + 3]) {
				s2[i + 3] = s2[i] + time_s[1];
			}

			else if (i + 3 < s2.size() && s2[i] + time_s[1] == s2[i + 3]) {
				s2[i + 3] = s2[i] + time_s[1] + 1;
			}

			else if(i + 3 < s2.size()){
				s2[i + 3]++;
			}
		}

		int comp = 0;

		if (!s1.empty()) comp = s1.back() + time_s[0];
		if (!s2.empty()) comp = max(comp, s2.back() + time_s[1]);
		answer = min(answer, comp);

		return;
	}

	s1.push_back(abs(h[n].x - s[0].x) + abs(h[n].y - s[0].y));
	dfs(n + 1, s1, s2);
	s1.pop_back();

	s2.push_back(abs(h[n].x - s[1].x) + abs(h[n].y - s[1].y));
	dfs(n + 1, s1, s2);
	s2.pop_back();
}

int main() {
	scanf("%d", &T);

	for (int tc = 1; tc <= T; tc++) {
		scanf("%d", &N);
		num_h = 0;
		num_s = 0;
		answer = 1e8;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				int n;
				scanf("%d", &n);
				if (n == 1) {
					h[num_h].x = j;
					h[num_h++].y = i;
				}
				if (n > 1) {
					s[num_s].x = j;
					s[num_s].y = i;
					time_s[num_s++] = n;
				}
			}
		}

		dfs(0, vector<int>(), vector<int>());

		printf("#%d %d\n", tc, answer);
	}
}