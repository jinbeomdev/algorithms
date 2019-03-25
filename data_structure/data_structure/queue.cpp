template<class TYPE>
struct NODE {
	NODE<TYPE> data;
};

template<class TYPE>
class Queue {
private:
	NODE<TYPE> *queueAry;
	int count;
	int maxSize;
	int front;
	int rear;

public:
	Queue(int size = 100);
	~Queue(void);
	bool dequeue(TYPE& dataOut);
	bool enqueue(TYPE dataIn);
};

template <class TYPE>
Queue<TYPE>::Queue(int size) {
	maxSize = size;
	front = -1;
	rear = -1;
	count = 0;
	queueAry = new NODE<TYPE>[maxSize];
	if (!queueAry) {
		exit(100);
	}
}

template<class TYPE>
bool Queue<TYPE>::enqueue(int dataIn) {
	if (count == maxSize) {
		return false;
	}

	rear++;
	if (rear == maxSize) {
		rear = 0;
	}

	queueAry[rear].data = dataIn;

	if (count == 0) {
		front = 0;
	}

	count++;
	return true;
}

template<class TYPE>
bool Queue<TYPE>::dequeue(TYPE& dataOut) {
	if (count == 0) {
		return false;
	}

	dataOut = queueAry[front].data;
	front++;
	if (fron == maxSize) {
		front = 0;
	}

	if (count == 1) {
		rear = front = -1;
	}

	count--;

	return true;
}