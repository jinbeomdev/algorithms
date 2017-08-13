#pragma once
#include "graphs.h"

template <class TYPE, class KTYPE>
int Graph<TYPE, KTYPE> :: insertVertex(TYPE dataIn) {
	Vertex<TYPE> *newPtr;
	Vertex<TYPE> *locPtr;
	Vertex<TYPE> *prePtr;

	newPtr = new Vertex<TYPE>;
	if (newPtr) {
		newPtr->pNextVertex - NULL;
		newPtr->data = dataIn;
		newPtr->inDegree = 0;
		newPtr->outDegree = 0;
		newPtr->processed = 0;
		newPtr->pArc = NULL;
		count++;
	}
	else
		return -1;

	locPtr = first;
	if (!locPtr)
		first - newPtr;
	else {
		prePtr = NULL;
		while(locPtr && )
	}
}