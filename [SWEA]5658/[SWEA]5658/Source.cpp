#include <stdio.h>
#include <vector>
#include <set>
#include <functional>

using namespace std;

int main() {
	int T, N, K;
	scanf("%d", &T);

	for (int test_case = 1; test_case <= T; test_case++) {
		vector<char> password;
		set<int, greater<int>> s;
		scanf("%d%d\n", &N, &K);
		password.resize(N);
		for (int i = 0; i < N; i++) {
			scanf("%c", &password[i]);
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j += (N / 4)) {
				int hex = 0;
				for (int k = (N / 4) - 1, pow = 1; k >= 0; k--, pow *= 16) {
					if (password[k] >= 'A' && password[k] <= 'Z') {
						hex += (password[k] - 'A' + 10) * pow;
					} else {
						hex += (password[k] - '0') * pow;
					}
				}
				s.insert(hex);
			}

			password.push_back(password.front());
			password.erase(password.begin());
		}

		set<int, greater<int>>::iterator it = s.begin();

		for (int i = 0; i < K; i++) {
			it++;
		}

		printf("#%d %d\n", test_case, *it);
	}
}