#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
	int T, test_case;

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		int Answer;
		int N;

		cin >> N;

		for (int base = 2; base <= N + 1; base++) {
			bool flag = true;
			int quotient = N;
			int remainder;

			remainder = quotient % base;
			quotient = quotient / base;

			while (quotient != 0) {
				if (remainder != quotient % base) {
					flag = false;
					break;
				}

				remainder = quotient % base;
				quotient = quotient / base;
			}
			
			if (flag) {
				Answer = base;
				break;
			}
		}

		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0;
}