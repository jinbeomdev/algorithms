#include <cstdio>

int n, k, s;
bool adj[400][400] = { false };

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 0; i < k; i++) {
		int before, after;
		scanf("%d%d", &before, &after);
		adj[before - 1][after - 1] = true;
	}

	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (adj[i][k] && adj[k][j]) adj[i][j] = true;
			}
		}
	}

	scanf("%d", &s);

	for (int i = 0; i < s; i++) {
		int case1, case2;
		scanf("%d%d", &case1, &case2);
		case1--; case2--;
		if (adj[case1][case2]) {
			puts("-1");
		} else if (adj[case2][case1]) {
			puts("1");
		} else {
			puts("0");
		}
	}
}