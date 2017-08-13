/*
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/

#include <iostream>
#include <cstring>

using namespace std;

int Answer;

int compare(const void * a, const void * b)
{
	return (*(int*)b - *(int*)a);
}

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

		Answer = 0;
		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
		Implement your algorithm here.
		The answer to the case will be stored in variable Answer.
		*/
		int N;

		cin >> N;

		int *data = new int[N];

		for (int i = 0; i < N; i++) {
			cin >> data[i];
		}

		qsort(data, N, sizeof(int), compare);

		int before = 0;
		int count = 1;

		for (int i = 1; i < N; i++) {
			if (data[before] == data[i]) {
				count++;
			}
			else {
				if (count % 2 == 1) {
					Answer ^= data[before];
				}
				count = 1;
			}
			before = i;

			if (i == N - 1 && (count % 2) == 1) {
				Answer ^= data[i];
			}
		}
		/////////////////////////////////////////////////////////////////////////////////////////////

		// Print the answer to standard output(screen).
		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;

		delete[] data;
	}

	return 0;//Your program should return 0 on normal termination.
}