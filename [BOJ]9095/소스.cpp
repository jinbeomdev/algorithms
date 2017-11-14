/*
https://www.acmicpc.net/problem/9095

문제
정수 4를 1, 2, 3의 조합으로 나타내는 방법은 총 7가지가 있다.

1+1+1+1
1+1+2
1+2+1
2+1+1
2+2
1+3
3+1
정수 n이 주어졌을 때, n을 1,2,3의 합으로 나타내는 방법의 수를 구하는 프로그램을 작성하시오.

입력
첫쨰 줄에 테스트 케이스의 개수 T가 주어진다. 각 테스트 케이스는 한 줄로 이루어져 있고, 정수 n이 주어진다. n은 양수이며 11보다 작다.

출력
각 테스트 케이스마다, n을 1,2,3의 합으로 나타내는 방법의 수를 출력한다.

예제 입력  복사
3
4
7
10
예제 출력  복사
7
44	
274
*/
#include <iostream>

using namespace std;

int main() {
	int T, test_case;


	cin >> T;


	for (test_case = 0; test_case < T; test_case++) {
		int n;
		int dp[15] = { 0, };
		dp[0] = 1;

		cin >> n;
		for (int i = 1; i <= n; i++) {
			if (i - 1 >= 0) {
				dp[i] += dp[i - 1];
			}
			if (i - 2 >= 0) {
				dp[i] += dp[i - 2];
			}
			if (i - 3 >= 0) {
				dp[i] += dp[i - 3];
			}
		}
		cout << dp[n] << endl;
	}
}