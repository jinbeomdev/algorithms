//11721�� : �� ���� ���� ����ϱ�

#include <iostream>
#include <string>

using namespace std;

int main() {
	int c;
	int cnt = 0;
	while ((c = getchar()) != EOF) {
		cout << (char)c;
		cnt++;
		if (cnt % 10 == 0) {
			cout << endl;
		}
	}
}