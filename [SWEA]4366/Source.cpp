#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>

using namespace std;

int T;
string bi, tri;

void getTriFromDec(const int dec, string &tri) { //21..0, 7..1, 2..2
	if (dec < 3) {
		tri += dec;
		return;
	}
	
	getTriFromDec(dec / 3, tri);
	tri += dec % 3;
}

int getDecFromTri(const string &tri) {
	int dec = 0;
	int power = 1;
	for (int i = tri.size() - 1; i >= 0; i--, power *= 3) {
		dec += (tri[i] - '0') * power;
	}

	return dec;
}

int getDecFromBi(const string &bi) {
	int dec = 0;
	int power = 1;
	for (int i = bi.size() - 1; i >= 0; i--, power*=2) {
		dec += (bi[i] - '0') * power;
	}

	return dec;
}

int main() {
	scanf("%d", &T);

	for (int test_case = 1; test_case <= T; test_case++) {
		cin >> bi;
		cin >> tri;

		for (int i = 0; i < bi.size(); i++) {
			char temp = bi[i];

			if (bi[i] == '0') {
				bi[i] = '1';
			} else {
				bi[i] = '0';
			}

			int dec_bi = getDecFromBi(bi);
			int dec_tri = getDecFromTri(tri);
			bi[i] = temp;

			int diff = abs(dec_bi - dec_tri);

			string str_tri;
			getTriFromDec(diff, str_tri);

			int cnt = 0;
			for (char c : str_tri) {
				if (c != '\0') cnt++;
			}

			if (cnt == 1) {
				printf("%c%d %d\n",
					'#', test_case, dec_bi);
			}
		}
	}

	return 0;
}