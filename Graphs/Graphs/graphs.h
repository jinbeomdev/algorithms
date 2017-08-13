#pragma once
template <class TYPE>
struct Vertex;

template <class TYPE>
struct Arc;

template <class TYPE>
struct Vertex {
	Vertex<TYPE> *pNextVertex;
	TYPE data;
	int inDegree;
	int outDegree;
	short processed;
	Arc<TYPE> *pArc;
};

template <class TYPE>
struct Arc {
	Vertex<TYPE> *destination;
	Arc<TYPE> *pNextArc;
};

template <class TYPE, class KTYPE>
class Graph {
private:
	int count;
	Vertex<TYPE> *first;
public:
	Graph();
	~Graph();

	int insertVertex(TYPE dataIn);
	int deleteVertex(KTYPE dltKey);
	int insertArc(KTYPE fromKey, KTYPE toKey);
	int deleteArc(KTYPE formKey, KTYPE toKey);
	int retrieveVertex(KTYPE key, TYPE &DataOut);
	int firstArc(KTYPE key, TYPE &DataOut);
	bool emptyGraph(void);
	bool graphFull(void);
	int graphCount(void);

	void depthFirst(void(*process) (TYPE dataProc));
	void breadthFirst(void(*process) (TYPE dataProc));
}; // Graph