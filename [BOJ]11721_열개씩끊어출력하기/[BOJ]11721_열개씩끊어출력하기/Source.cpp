//11721번 : 열 개씩 끊어 출력하기

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