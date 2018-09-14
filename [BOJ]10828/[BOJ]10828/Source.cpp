#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

struct NODE {
	int data;
	NODE* next;
};

class Stack {
public:
	Stack() {
		count = 0;
		top = NULL;
	}

	bool Push(int dataIn) {
		NODE* newPtr;

		newPtr = new NODE;

		if (!newPtr) {
			return false;
		}

		newPtr->data = dataIn;
		newPtr->next = top;
		top = newPtr;
		count++;

		return true;
	}

	bool Pop(int& dataOut) {
		NODE* delPtr;

		if (count == 0) {
			return false;
		}

		delPtr = top;
		dataOut = top->data;
		top = top->next;
		count--;

		delete delPtr;

		return true;
	}

	bool Top(int& dataOut) {
		if (count == 0) {
			return false;
		}

		dataOut = top->data;

		return true;
	}

	bool Empty() {
		return (count == 0);
	}

	int Size() {
		return count;
	}

private:
	int count;
	NODE* top;
};

int main() {
	int N;
	Stack s;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		char query[16];

		scanf("%s", query);

		int dataIn;
		int dataOut;
		if (!strcmp(query, "push")) {
			scanf("%d", &dataIn);
			s.Push(dataIn);
		} else if (!strcmp(query, "pop")) {
			if (!s.Pop(dataOut)) {
				printf("-1\n");
			} else {
				printf("%d\n", dataOut);
			}
		} else if (!strcmp(query, "top")) {
			if (!s.Top(dataOut)) {
				printf("-1\n");
			} else {
				printf("%d\n", dataOut);
			}
		} else if (!strcmp(query, "size")) {
			printf("%d\n", s.Size());
		} else if (!strcmp(query, "empty")) {
			printf("%d\n", s.Empty());
		} else {
			assert(true);
		}
	}
}