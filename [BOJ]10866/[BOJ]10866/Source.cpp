#include <stdio.h>
#include <string.h>
#include <assert.h>

struct NODE {
	int data;
	NODE* pPre;
	NODE* pNext;
};

class Deque {
public:
	Deque() {
		front = NULL;
		back = NULL;
		count = 0;
	}

	bool PushFront(int dataIn) {
		NODE* newPtr;

		if (!(newPtr = new NODE)) {
			return false;
		}

		newPtr->data = dataIn;
		newPtr->pPre = NULL;
		newPtr->pNext = front;

		if (count == 0) {
			back = newPtr;
		} else {
			front->pPre = newPtr;
		}

		front = newPtr;
		count++;
		
		return true;
	}

	bool PushBack(int dataIn) {
		NODE* newPtr;

		if (!(newPtr = new NODE)) {
			return false;
		}

		newPtr->data = dataIn;
		newPtr->pPre = back;
		newPtr->pNext = NULL;

		if (count == 0) {
			front = newPtr;
		} else {
			back->pNext = newPtr;
		}

		back = newPtr;
		count++;

		return true;
	}

	bool PopFront(int& dataOut) {
		NODE* delPtr;

		if (count == 0) {
			return false;
		}

		dataOut = front->data;
		delPtr = front;

		if (count == 1) {
			front = back = NULL;
		} else {
			front = front->pNext;
			front->pPre = NULL;
		}

		count--;

		delete delPtr;

		return true;
	}

	bool PopBack(int& dataOut) {
		NODE* delPtr;

		if (count == 0) {
			return false;
		}

		dataOut = back->data;
		delPtr = back;
		

		if (count == 1) {
			front = back = NULL;
		} else {
			back = back->pPre;
			back->pNext = NULL;
		}

		count--;

		return true;
	}

	int Size() {
		return count;
	}

	bool Empty() {
		return (count == 0);
	}

	bool Front(int& dataOut) {
		if (count == 0) {
			return false;
		}

		dataOut = front->data;
		return true;
	}

	bool Back(int& dataOut) {
		if (count == 0) {
			return false;
		}

		dataOut = back->data;
		return true;
	}

private:
	NODE * front;
	NODE * back;
	int count;
};

int main() {
	int N;
	Deque d;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		char query[16];

		scanf("%s", query);

		int dataIn;
		int dataOut;
		bool success;
		if (!strcmp(query, "push_front")) {
			scanf("%d", &dataIn);
			d.PushFront(dataIn);
			continue;
		} else if (!strcmp(query, "push_back")) {
			scanf("%d", &dataIn);
			d.PushBack(dataIn);
			continue;
		} else if (!strcmp(query, "pop_front")) {
			success = d.PopFront(dataOut);
		} else if (!strcmp(query, "pop_back")) {
			success = d.PopBack(dataOut);
		} else if (!strcmp(query, "size")) {
			printf("%d\n", d.Size());
			continue;
		} else if (!strcmp(query, "empty")) {
			printf("%d\n", d.Empty());
			continue;
		} else if (!strcmp(query, "front")) {
			success = d.Front(dataOut);
		} else if (!strcmp(query, "back")) {
			success = d.Back(dataOut);
		} else {
			assert(true);
		}

		if (!success) {
			printf("-1\n");
		} else {
			printf("%d\n", dataOut);
		}
	}
}