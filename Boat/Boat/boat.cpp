#include <iostream>
#include <vector>

using namespace std;

int N;
vector<vector<int>> schools;

int f(int picked, int school) {
	if (school == N - 1) {
		return 1;
	}

	for (int i = schools[school][0]; i < schools[school][1]; i++) {
		if (i > picked) {
			f(i, school++);
		}
		else {
			f(picked, school++);
		}
	}
}

int main() {

	cin >> N;

	schools = vector<vector<int>>(N, vector<int>(2, 0));

	//1 �� ai �� bi �� 109

	for (int i = 0; i < N; i++) {
		cin >> schools[i][0] >> schools[i][1];
	}

	//i�� �б��� ������ ��Ʈ�� �ϳ��� �������� ���� �� �ִ�.
	//i�� �б��� ��Ʈ�� ��������� �� ��쿡�� i���� ��ȣ�� ���� �� ��� �б��� ������ ��Ʈ �� ���� ���� ���� ��Ʈ�� �������� ��.
	//�ּ��� �� �б��� ������ ��츸 ��꿡 ����.

	f(0, 0);
}