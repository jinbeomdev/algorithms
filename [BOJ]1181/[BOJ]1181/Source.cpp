#include <stdlib.h>
#include <string.h>
#include <stdio.h>

const int STR_MAX = 51;
const int MAX = 20001;

struct string {
	char c_str[STR_MAX];
	int size;
}s[MAX];

int GetSize(char* c_str) {
	char *p = c_str;

	int size = 0;
	while (*p++) {
		size++;
	}

	return size;
}



void Copy(string *dest, string *src) {
	dest->size = src->size;

	register char *p_dest = dest->c_str;
	register const char *p_src = src->c_str;

	while (*p_dest++ = *p_src++);
}

int Comp(string* a, string *b) {
	if (a->size == b->size) {
		char *p_a = a->c_str;
		char *p_b = b->c_str;

		while (*p_a && *p_b) {
			if (*p_a < *p_b) {
				return -1;
			} else if(*p_a > *p_b) {
				return 1;
			}
			p_a++;
			p_b++;
		}
	} else {
		return a->size - b->size; //a가 길면 양수, b가 길면 음수
	}

	return 0;
}

void Merge(string s[], int left, int mid, int right) {
	int p = left, q = mid + 1, k = 0;

	string* temp = (string*)calloc(right - left + 1, sizeof(string));

	while (p <= mid && q <= right) {
		if (Comp(&s[p], &s[q]) >= 0) {
			Copy(&temp[k++], &s[q++]);
		} else {
			Copy(&temp[k++], &s[p++]);
		}
	}

	while (p <= mid) {
		Copy(&temp[k++], &s[p++]);
	}

	while (q <= right) {
		Copy(&temp[k++], &s[q++]);
	}

	for (int i = left, j = 0; i <= right; i++, j++) {
		Copy(&s[i], &temp[j]);
	}

	free(temp);
}

void MergeSort(string s[], int left, int right) {
	if (left < right) {
		int mid = (left + right) / 2;	
		MergeSort(s, left, mid);
		MergeSort(s, mid + 1, right);
		Merge(s, left, mid, right);
	}
}

int main() {
	int N;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%s", &s[i].c_str);
		s[i].size = GetSize(s[i].c_str);
	}

	MergeSort(s, 0, N - 1);

	for (int i = 0; i < N; i++) {
		if (i == 0) {
			printf("%s\n", s[i].c_str);
		} else if (Comp(&s[i], &s[i - 1]) != 0) {
			printf("%s\n", s[i].c_str);
		}
	}

	return 0;
}