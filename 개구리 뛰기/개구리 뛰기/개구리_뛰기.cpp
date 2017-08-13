#include <iostream>
#include <vector>

using namespace std;

int Answer;

inline int min(int a, int b) { return (((a) < (b)) ? (a) : (b)); }

int main(int argc, char** argv)
{
	int T, test_case;

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		int N;
		int K;
		vector<int> stones;
		int temp = 0;
		int frog = 0;
		int Answer = 0;

		//이동 가능한 돌의 개수
		cin >> N;

		stones = vector<int>(N + 1, 0);

		for (int i = 1; i < N + 1; i++) {
			cin >> stones[i];
		}

		//최대 이동한 거리
		cin >> K;
		
		for (int i = 1; i < N + 1; i++) {
			temp = frog + K; //개구리가 뛸 수 있는 최대 위치

			if (temp >= stones[i]) //만약에 개구리가 뛸 수 있는 최대의 위치가 stones[i] 보다 크다면
			{
				if (i == N) //만약에 마지막 돌에서 뛰는 거라면
				{
					//횟수를 하나 증가시키고 종료
					Answer++;
					break;
				}
				
				if (temp < stones[i + 1]) //만약에 개구리가 최대로 뛸 수 있는 거리가 i + 1보다는 작다면
				{
					Answer++;
					frog = stones[i]; //개구리의 위치를 [i] 로 옮김
				}
			}
			else
			{
				Answer = -1;
			}
		}


		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0;
}