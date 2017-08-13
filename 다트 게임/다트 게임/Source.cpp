/*
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/

#include <iostream>
#include <cmath>
using namespace std;

int Answer;

int main(int argc, char** argv)
{
	int T, test_case;
	/*
	The freopen function below opens input.txt file in read only mode, and afterward,
	the program will read from input.txt file instead of standard(keyboard) input.
	To test your program, you may save input data in input.txt file,
	and use freopen function to read from the file when using cin function.
	You may remove the comment symbols(//) in the below statement and use it.
	Use #include<cstdio> or #include <stdio.h> to use the function in your program.
	But before submission, you must remove the freopen function or rewrite comment symbols(//).
	*/

	// freopen("input.txt", "r", stdin);

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		int A, B, C, D, E;
		int num;
		Answer = 0;
		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
		Implement your algorithm here.
		The answer to the case will be stored in variable Answer.
		*/
		cin >> A >> B >> C >> D >> E;
		cin >> num;
		for (int i = 0; i < num; i++) {
			int x, y;
			cin >> x >> y;
			int length = sqrt(double(x*x + y*y));
			if (length <= A) {
				Answer += 50;
			}
			else if (length >= B && length <= C) {
				if (x == 0 && y > 0) {
					Answer += 20 * 3;
				}
				else if (x == 0 && y < 0) {
					Answer += 3 * 3;
				}
				else if (x > 0 && y == 0) {
					Answer += 6 * 3;
				}
				else if (x < 0 && y == 0) {
					Answer += 11 * 3;
				}
				else if (x > 0 && y > 0) {
					Answer += 18 * 3;
				}
				else if (x > 0 && y < 0) {
					Answer += 2 * 3;
				}
				else if (x < 0 && y > 0) {
					Answer += 9 * 3;
				}
				else if (x < 0 && y < 0) {
					Answer += 16 * 3;
				}
			}
			else if (length >= D && length <= E) {
				if (x == 0 && y > 0) {
					Answer += 20 * 2;
				}
				else if (x == 0 && y < 0) {
					Answer += 3 * 2;
				}
				else if (x > 0 && y == 0) {
					Answer += 6 * 2;
				}
				else if (x < 0 && y == 0) {
					Answer += 11 * 2;
				}
				else if (x > 0 && y > 0) {
					Answer += 18 * 2;
				}
				else if (x > 0 && y < 0) {
					Answer += 2 * 2;
				}
				else if (x < 0 && y > 0) {
					Answer += 9 * 2;
				}
				else if (x < 0 && y < 0) {
					Answer += 16 * 2;
				}
			}
			else if (length > E) {
				Answer += 0;
			}
			else {
				if (x == 0 && y > 0) {
					Answer += 20;
				}
				else if (x == 0 && y < 0) {
					Answer += 3;
				}
				else if (x > 0 && y == 0) {
					Answer += 6;
				}
				else if (x < 0 && y == 0) {
					Answer += 11;
				}
				else if (x > 0 && y > 0) {
					Answer += 18;
				}
				else if (x > 0 && y < 0) {
					Answer += 2;
				}
				else if (x < 0 && y > 0) {
					Answer += 9;
				}
				else if (x < 0 && y < 0) {
					Answer += 16;
				}
			}
		}
		/////////////////////////////////////////////////////////////////////////////////////////////

		// Print the answer to standard output(screen).
		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}