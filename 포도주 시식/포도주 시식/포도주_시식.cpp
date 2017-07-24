#include <iostream>
#include <vector>
using namespace std;

#define __max(a,b) (((a) > (b)) ? (a) : (b))

int main() {
	//포도주 잔의 개수
	int N;
	vector<int> glasses;
	vector<int> DP;
	int Answer = 0;

	cin >> N;

	glasses = vector<int>(N, 0);
	DP = vector<int>(N, -1);

	for (int i = 0; i < glasses.size(); i++) {
		cin >> glasses[i];
	}

	/*
	* 연속으로 놓여 있는 3잔을 모두 마실 수 없다.
	* 이럴 경우에 잔을 선택할 수 있는 경우의 수
	* DP[N] = max(DP[N-2] + glsses[N], DP[N-3] + glasses[N-1] + glasses[N])
	* 범위를 주의 하자
	* N - 3이 있으므로 이 부분의 예외처리 한다. 
	* (수정) 착각하고 있었는데, 만약에 3번 째 포도주를 마셔야한다고 하면 3번 째 포도주를 굳이 마실 필요가 없다.
	* (수정) 1,2번 째 포도주만 마시면 된다
	*/
	for (int i = 0; i < DP.size(); i++) {
		if (i == 0)
			DP[i] = glasses[i];
		else if (i == 1)
			DP[i] = glasses[i - 1] + glasses[i];
		else if (i == 2)
			DP[i] = __max(DP[i - 1], __max(glasses[i - 2], glasses[i - 1]) + glasses[i]);
		else {
			// (원래) DP[i] = __max(DP[i - 3] + glasses[i - 1], DP[i - 2]) + glasses[i]);
			// (수정) ->
			DP[i] = __max(DP[i - 1], __max(DP[i - 3] + glasses[i - 1], DP[i - 2]) + glasses[i]);
		}

		if (Answer < DP[i])
			Answer = DP[i];
	}

	cout << Answer;
}