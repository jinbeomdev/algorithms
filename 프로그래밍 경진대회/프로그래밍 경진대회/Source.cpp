/*
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/

#include <iostream>
#include <cstdlib>

using namespace std;

int Answer;

int compare(const void *a, const void *b) {
	return *(int *)a - *(int *)b;
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
		int max = 0;
		int *scores;
		int *tempScores;
		int players; //the number of player
		Answer = 0;
		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
		Implement your algorithm here.
		The answer to the case will be stored in variable Answer.
		*/
		cin >> players;
		scores = new int[players];
		
		for (int i = 0; i < players; i++) {
			cin >> scores[i];
		}

		qsort(scores, players, sizeof(int), compare);

		for (int i = 0; i < players; i++) {
			if (scores[i] + players - i >= max)
				max = scores[i] + players - i;
		}

		for (int i = 0; i < players; i++) {
			if (scores[i] + players >= max) {
				Answer++;
			}
		}

		/////////////////////////////////////////////////////////////////////////////////////////////

		// Print the answer to standard output(screen).
		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}