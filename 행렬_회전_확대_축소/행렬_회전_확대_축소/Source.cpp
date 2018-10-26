#include <stdio.h>

int image[100][100];
int w, h;

void print() {
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			printf("%d", image[i][j]);
		}
		puts("");
	}
}

void Scale(int size) {
	w = w * 2;
	h = h * 2;
	int temp[100][100];

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			temp[i][j] = image[i / 2][j / 2];
		}
	}

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			image[i][j] = temp[i][j];
		}
	}
}

void Rotation(int dir) {
	int temp[100][100];
	int temp_w = h;
	int temp_h = w;

	if (dir == 0) {
		for (int i = 0; i < temp_h; i++) {
			for (int j = 0; j < temp_w; j++) {
				temp[i][j] = image[temp_w - j - 1][i];
			}
		}
	} else {
		for (int i = 0; i < temp_h; i++) {
			for (int j = 0; j < temp_w; j++) {
				temp[i][j] = image[j][temp_h - i - 1];
			}
		}
	}

	w = temp_w;
	h = temp_h;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			image[i][j] = temp[i][j];
		}
	}
}

int main() {
	scanf("%d%d", &w, &h);

	for (int i = 0; i < w; i++) {
		for (int j = 0; j < h; j++) {
			scanf("%d", &image[i][j]);
		}
	}

	int query_cnt;

	scanf("%d", &query_cnt);
	for (int i = 0; i < query_cnt; i++) {
		char query[2];
		scanf("%s", query);
		if (query[0] == 'R') {
			Rotation(query[1] - '0');
		} else if (query[0] == 'S') {
			Scale(query[1] - '0');
		}
		print();
	}
}