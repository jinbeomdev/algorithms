/*
만약 스택의 최대 크기가 프로그램이 쓰여지기 전에 계산될 수 있다면,
연결리스트로 써서 동적 메모리에 스택을 구현하는 것 보다 배열로 스택을 구현하는 것이 더 효율적인다
*/

template<class TYPE>
struct  NODE {
	TYPE data;
};

template<class TYPE>
class Stack {
private:
	NODE<TYPE> *stackAry;
	int count;
	int stackMax;
	int top;

public:
	Stack(int size = 100);
	~Stack(void);
	bool pushStack(TYPE dataIn);
	bool popStack(TYPE& dataOut);
	bool stackTop(TYPE& dataOut);
	bool emptyStack(void);
	bool fullStack(void);
	int stackCount(void);
};

template<class TYPE>
Stack<TYPE>::Stack(int size) {
	stackMax = size;
	stackArr = new NODE<TYPE>[stackMax];

	if (!stackAry) {
		abort();
	}

	count = 0;
	top = -1;
}

template<class TYPE>
bool Stack<TYPE>::pushStack(TYPE dataIn) {
	if (count >= stackMax) {
		return false;
	}

	count++;
	top++;
	stackAry[top].data = dataIn;
	return true;
}

template<class TYPE>
bool Stack<TYPE>::popStack(TYPE& dataOut) {
	bool success;

	if (count == 0) {
		success = false;
	} else {
		dataOut = stackAry[top].data;
		top--;
		count--;
		success = true;
	}
}