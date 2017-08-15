//2577번: 숫자의 개수
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main() {
	int A, B, C;
	int ABC;
	string strABC;
	int num[10];
	memset(num, 0, sizeof(num));
	cin >> A >> B >> C;
	ABC = A * B * C;
	strABC = to_string(ABC);
	for (int i = 0; i < strABC.size(); i++) {
		num[((strABC[i] - '0') % 10)]++;
	}

	for (int i = 0; i < 10; i++) {
		cout << num[i] << endl;
	}
}