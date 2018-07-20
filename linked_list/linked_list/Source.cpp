template <class TYPE>
struct  NODE {
	TYPE data;
	NODE *link;
}; //노드 선언 끝

// 리스트 클래스 선언
template <class TYPE, class KTYPE>
class List {
private:
	NODE<TYPE> *head;
	NODE<TYPE> *pos;
	NODE<TYPE> *rear;
	int count;

	//함수 선언
	bool _insert(NODE<TYPE> *pPre,
							 TYPE        dataIn);
	void _delete(NODE<TYPE> *pPre,
							 NODE<TYPE> *pLoc,
							 TYPE       *dataOutPtr);
	bool _search(NODE<TYPE>  **pPre,
							 NODE<TYPE> **pLoc,
							 KTYPE			key);

public:
	List(void);
	~List(void);
	int		addNode			(TYPE dataIn);
	bool	removeNode	(KTYPE key,
										 TYPE *dataOutPtr);
	bool	retrieveNode(KTYPE Argu,
										 TYPE& dataOut);
	bool	getNext			(int fromWhere,
										 TYPE& dataOut);
	int		listCount		(void);
	int		emptyList		(void);
	bool	fullList		(void);
};

template <class TYPE, class KTYPE>
int List<TYPE, KTYPE>::addNode(TYPE dataIn) {
	bool found;
	bool success;

	NODE<TYPE> *pPre;
	NODE<TYPE> *pLoc;

	found = _search(&pPre, &Loc, dataIn.key);
	if (found) return 1;

	success = _insert(pPre, dataIn);
	if (!success) return -1;

	return 0;
}

template <class TYPE, class KTYPE>
bool List<TYPE, KTYPE> ::_insert(NODE<TYPE> *pPre,
																 TYPE dataIn) {
	NODE<TYPE> *pNew;

	if (!(pNew = new NODE<TYPE>)) return false;

	pNew->data = dataIn;
	pNew->link = NULL;

	if (pPre == NULL) {
		pNew->link = head->link;
		head = pNew;
	} else {
		pNew->link = pPre->link;
		pPre->link = pNew;
	}

	if (pNew->link == NULL) {
		rear = pNew;
	}

	count++;

	return true;
}

template <class TYPE, class KTYPE>
bool List<TYPE, KTYPE>::
					removeNode(KTYPE dltkey, TYPE *pDataOut) {
	bool found;
	NODE<TYPE> *pPre;
	NODE<TYPE> *pLoc;

	found = _serach(&pPre, &pLoc, dltkey);
	if (found)
		_delete(pPre, pLoc, pDataOut);
	return found;
}

template <class TYPE, class KTYPE>
void List<TYPE, KTYPE>::_delete(NODE<TYPE> *pPre,
																NODE<TYPE> *pLoc,
																TYPE *pDataOut) {
	*pDataOut = pLoc->data;
	if (pPre == NULL) {
		head = pLoc->link;
	} else {
		pPre->link = pLoc->link;
	}

	if (pLoc->link == NULL) rear = pPre;

	count--;
	delete pLoc;
	return;
}

template<class TYPE, class KTYPE>
bool List<TYPE, KTYPE>::
					retrieveNode(KTYPE key, TYPE& dataOut) {
	bool found;
	NODE<TYPE> *pPre;
	NODE<TYPE> *pLoc;

	found = _search(&pPre, &pLoc, key);
	if (found)
		dataOut = pLoc->data;
	return found;
}

template<class TYPE, class KTYPE>
bool List<TYPE, KTYPE>::_search(NODE<TYPE> **pPre,
																NODE<TYPE> **pLoc,
																KTYPE key) {
	*pPre = NULL;
	*pLoc = head;
	if (count == 0) return false;

	if (key > rear->data) {
		*pPre = rear;
		*pLoc = NULL;
		return false;
	}

	while (key > (*pLoc)->data.key) {
		*pPre = *pLoc;
		*pLoc = (*pLoc)->link;
	}

	if (key == (*pLoc)->data.key) {
		return true;
	} else {
		return false;
	}
}

template<class TYPE, class KTYPE>
bool List<TYPE, KTYPE>::emptyList(void) {
	return (count == 0);
};

template<class TYPE, class KTYPE>
bool List<TYPE, KTYPE>::fullList(void) {
	NODE<TYPE> *temp;

	if (temp = new NODE<TYPE>) {
		delete temp;
		return false;
	}

	return true;
}

template<class TYPE, class KTYPE>
int List<TYPE, KTYPE>::listCount(void) {
	return count;
}

template <class TYPE, class KTYPE>
bool List<TYPE, KTYPE>::getNext(int fromWhere,
																TYPE& dataOut) {
	bool success;

	if (fromWhere == 0) {
		if (count == 0) {
			success = false;
		} else {
			pos = head;
			dataOut = pos->data;
			success = true;
		}
	} else {
		if (pos->link == NULL) {
			success = false;
		} else {
			pos = pos->link;
			dataOut = pos->data;
			success = true;
		}
	}

	return success;
}

template<class TYPE, class KTYPE>
List<TYPE, KTYPE> ::~List(void) {
	NODE<TYPE> *deletePtr;

	if (head) {
		while (count > 0) {
			deletePtr = head;
			head = head->link;
			count--;
			delete deletePtr;
		}
	}
}
