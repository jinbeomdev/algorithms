#include <stdio.h>
#include <string.h>

int main() {
	int N;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		char query[16];

		scanf("%s", query);
		if (!strcmp(query, "push_front")) {

		} else if (!strcmp(query, "push_back")) {

		} else if (!strcmp(query, "pop_front")) {

		} else if (!strcmp(query, "pop_back")) {

		} else if (!strcmp(query, "size")) {

		} else if (!strcmp(query, "empty")) {

		} else if (!strcmp(query, "front")) {

		} else if (!strcmp(query, "back")) {

		} else {

		}
	}
}