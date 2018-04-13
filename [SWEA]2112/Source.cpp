#include <iostream>
#include <cassert>
#include <algorithm>
#include <queue>

using namespace std;

const int kMaxD = 13;
const int kMaxW = 20;
const int kInf = 10e6;

int D, W, K;
bool protection_film[kMaxD][kMaxW];
int min_use;

void InjectChemicals(int film_location, int chemical_type) {
	for (int i = 0; i < W; i++) {
		protection_film[film_location][i] = chemical_type;
	}
}

void GetFilmInfo(int temp_Film[][kMaxW]) {
	for (int i = 0; i < D; i++) {
		for (int j = 0; j < W; j++) {
			protection_film[i][j] = temp_Film[i][j];
		}
	}
}

void SaveFilmInfo(int temp_Film[][kMaxW]) {
	for (int i = 0; i < D; i++) {
		for (int j = 0; j < W; j++) {
			temp_Film[i][j] = protection_film[i][j];
		}
	}
}

bool FilmTest() {
	for (int j = 0; j < W; j++) {
		int longest = 0;
		int sum = 1;
		for (int i = 0; i < D - 1; i++) {
			if (protection_film[i][j] == protection_film[i + 1][j]) sum++;
			if (protection_film[i][j] != protection_film[i + 1][j]) sum = 1;
			if (sum == K) break;
		}

		if (sum != K) return false;
	}
	return true;
}

void Dfs(int film_location, int num_use) {
	if (num_use > min_use) return;

	bool success = FilmTest();
	
	if (success && num_use < min_use) {
		min_use = num_use;
		return;
	}

	if (film_location >= D) return;

	int temp_film[kMaxD][kMaxW];

	Dfs(film_location + 1, num_use);

	/* A */
	SaveFilmInfo(temp_film);
	InjectChemicals(film_location + 1, 0);
	Dfs(film_location + 1, num_use + 1);
	GetFilmInfo(temp_film);

	/* B */
	SaveFilmInfo(temp_film);
	InjectChemicals(film_location + 1, 1);
	Dfs(film_location + 1, num_use + 1);
	GetFilmInfo(temp_film);
}

int main() {
	int test_case_size;

	cin >> test_case_size;

	for (int test_case = 1; test_case <= test_case_size; test_case++) {
		/* init */
		cin >> D >> W >> K;
		min_use = kInf;
		
		/* exception */
		assert(D <= kMaxD);
		assert(W <= kMaxW);
		assert(K <= D);

		/* input */
		for (int i = 0; i < D; i++) {
			for (int j = 0; j < W; j++) {
				cin >> protection_film[i][j];
			}
		}
		
		Dfs(0, 0);

		cout << "#" << test_case << " " << min_use << endl;
	}
	//system("pause");
}