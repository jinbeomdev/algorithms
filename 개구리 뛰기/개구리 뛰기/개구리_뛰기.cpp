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

		//�̵� ������ ���� ����
		cin >> N;

		stones = vector<int>(N + 1, 0);

		for (int i = 1; i < N + 1; i++) {
			cin >> stones[i];
		}

		//�ִ� �̵��� �Ÿ�
		cin >> K;
		
		for (int i = 1; i < N + 1; i++) {
			temp = frog + K; //�������� �� �� �ִ� �ִ� ��ġ

			if (temp >= stones[i]) //���࿡ �������� �� �� �ִ� �ִ��� ��ġ�� stones[i] ���� ũ�ٸ�
			{
				if (i == N) //���࿡ ������ ������ �ٴ� �Ŷ��
				{
					//Ƚ���� �ϳ� ������Ű�� ����
					Answer++;
					break;
				}
				
				if (temp < stones[i + 1]) //���࿡ �������� �ִ�� �� �� �ִ� �Ÿ��� i + 1���ٴ� �۴ٸ�
				{
					Answer++;
					frog = stones[i]; //�������� ��ġ�� [i] �� �ű�
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