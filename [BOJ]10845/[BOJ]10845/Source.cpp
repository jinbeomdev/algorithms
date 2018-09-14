#include <stdio.h>
#include <string.h>

struct  NODE {
	int data;
	NODE* next;
};

class Queue {
public:
	Queue() {
		front = NULL;
		back = NULL;
		count = 0;
	}

	bool Push(int dataIn) {
		NODE* newPtr;

		if (!(newPtr = new NODE)) {
			return false;
		}

		newPtr->data = dataIn;
		newPtr->next = NULL;

		if (count == 0) {
			front = newPtr;
		} else {
			back->next = newPtr;
		}

		count++;
		back = newPtr;

		return true;
	}

	bool Pop(int& dataOut) {
		NODE* delPtr;

		if (count == 0) {
			return false;
		}

		dataOut = front->data;
		delPtr = front;

		if (count == 1) {
			front = back = NULL;
		} else {
			front = front->next;
		}

		count--;
		delete delPtr;

		return true;
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

	int Size() {
		return count;
	}

	bool Empty() {
		return (count == 0);
	}

private:
	NODE* front;
	NODE* back;
	int count;
};

int main() {
	int N;
	Queue q;
	
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		char query[16];
		
		scanf("%s", query);

		int dataIn;
		int dataOut;
		bool success;
		if (!strcmp(query, "push")) {
			scanf("%d", &dataIn);
			q.Push(dataIn);
			continue;
		} else if (!strcmp(query, "pop")) {
			success = q.Pop(dataOut);
		} else if (!strcmp(query, "front")) {
			success = q.Front(dataOut);
		} else if (!strcmp(query, "back")) {
			success = q.Back(dataOut);
		} else if (!strcmp(query, "size")) {
			printf("%d\n", q.Size());
			continue;
		} else if (!strcmp(query, "empty")) {
			printf("%d\n", q.Empty());
			continue;
		}

		if (!success) {
			printf("-1\n");
		} else {
			printf("%d\n", dataOut);
		}
	}
}