//1546¹ø: Æò±Õ
#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;

int main() {
	int N;
	double MAX_SCORE;
	double sum = 0;
	vector<double> scores;
	
	cin >> N;
	
	scores = vector<double>(N);

	for (int i = 0; i < N; i++) {
		cin >> scores[i];
	}

	sort(scores.begin(), scores.end(), greater<double>());

	MAX_SCORE = scores[0];

	for (int i = 0; i < N; i++) {
		scores[i] = scores[i] / MAX_SCORE * 100;
		sum += scores[i];
	}

	cout << fixed;
	cout.precision(2);
	cout << sum / (double)N;
}