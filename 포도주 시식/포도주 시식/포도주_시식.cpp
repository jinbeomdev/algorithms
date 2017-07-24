#include <iostream>
#include <vector>
using namespace std;

#define __max(a,b) (((a) > (b)) ? (a) : (b))

int main() {
	//������ ���� ����
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
	* �������� ���� �ִ� 3���� ��� ���� �� ����.
	* �̷� ��쿡 ���� ������ �� �ִ� ����� ��
	* DP[N] = max(DP[N-2] + glsses[N], DP[N-3] + glasses[N-1] + glasses[N])
	* ������ ���� ����
	* N - 3�� �����Ƿ� �� �κ��� ����ó�� �Ѵ�. 
	* (����) �����ϰ� �־��µ�, ���࿡ 3�� ° �����ָ� ���ž��Ѵٰ� �ϸ� 3�� ° �����ָ� ���� ���� �ʿ䰡 ����.
	* (����) 1,2�� ° �����ָ� ���ø� �ȴ�
	*/
	for (int i = 0; i < DP.size(); i++) {
		if (i == 0)
			DP[i] = glasses[i];
		else if (i == 1)
			DP[i] = glasses[i - 1] + glasses[i];
		else if (i == 2)
			DP[i] = __max(DP[i - 1], __max(glasses[i - 2], glasses[i - 1]) + glasses[i]);
		else {
			// (����) DP[i] = __max(DP[i - 3] + glasses[i - 1], DP[i - 2]) + glasses[i]);
			// (����) ->
			DP[i] = __max(DP[i - 1], __max(DP[i - 3] + glasses[i - 1], DP[i - 2]) + glasses[i]);
		}

		if (Answer < DP[i])
			Answer = DP[i];
	}

	cout << Answer;
}