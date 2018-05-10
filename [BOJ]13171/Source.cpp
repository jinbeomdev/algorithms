/* https://www.acmicpc.net/problem/13171 */

//#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>

using namespace std;

const int kMod = (int)10e8 + 7;

int main() {
	long long a, x;
	long long result = 1;

	scanf("%lld\n%lld", &a, &x);

	long long sum = a;
	while (x > 0) {
		if (x % 2) result = ((result % kMod) * (sum % kMod)) % kMod;
		x = x / 2;
		sum = ((sum % kMod) * (sum % kMod)) % kMod;
	}

	printf("%lld", result);

	//system("pause");

	return 0;
}