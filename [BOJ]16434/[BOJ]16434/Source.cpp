#include <stdio.h>
#include <limits>

using namespace std;

long long int min(long long int a , long long int b) {
	if (a > b) {
		return b;
	}
	return a;
}

struct Room {
	long long int t;
	long long int a;
	long long int h;
}rooms[123456];

int main() {
	long long int N, H_ATK;

	scanf("%lld%lld", &N, &H_ATK);

	for (int i = 0; i < N; i++) {
		scanf("%lld", &rooms[i].t);
		scanf("%lld", &rooms[i].a);
		scanf("%lld", &rooms[i].h);
	}

	long long int left = 0, right = 223372036854775800;
	long long int H_MAX;

	while (left <= right) {
		H_MAX = (left + right) / 2;
		bool is_win = true;
		long long int A = H_ATK;
		long long int H = H_MAX;

		for (int i = 0; i < N; i++) {
			if (rooms[i].t == 1) {
				long long int M_H = rooms[i].h;

				long long int numAtk;
				if (M_H % A == 0) {
					numAtk = M_H / A - 1;
				} else {
					numAtk = M_H / A;
				}
				H -= (numAtk* rooms[i].a);
				if (H <= 0) {
					is_win = false;
					break;
				}
			} else {
				A += rooms[i].a;
				H = min(H_MAX, H + rooms[i].h);
			}

			if (!is_win) {
				break;
			}
		}

		if (is_win) {
			right = H_MAX - 1;
		} else {
			left = H_MAX + 1;
		}
	}

	printf("%lld", left);
}