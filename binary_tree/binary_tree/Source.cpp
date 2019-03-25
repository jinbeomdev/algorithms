#include <stdio.h>

struct NODE {
	int data;
	NODE* leftChild;
	NODE* rightChild;
};

class BST {
public:
	BST() {
		root = NULL;
		count = 0;
	}

	void _insert(NODE** root, NODE* dataIn) {
		if (!(*root)) {
			*root = dataIn;
		} else {
			if ((*root)->data > dataIn->data) {
				_insert(&(*root)->leftChild, dataIn);
			} else {
				_insert(&(*root)->rightChild, dataIn);
			}
		}
	}

	bool Insert(int dataIn) {
		NODE* newPtr;

		if (!(newPtr = new NODE)) {
			return false;
		}

		newPtr->data = dataIn;
		newPtr->leftChild = NULL;
		newPtr->rightChild = NULL;

		_insert(&root, newPtr);
		count++;

		return true;
	}

	bool _delete(NODE** root, int delKey) {
		NODE* delPtr;

		if (*root == NULL) {
			return false;
		}

		if (delKey < (*root)->data) {
			return _delete(&(*root)->leftChild, delKey);
		} else if (delKey > (*root)->data) {
			return _delete(&(*root)->rightChild, delKey);
		} else {
			if (!(*root)->leftChild) {
				//오른쪽 자식만 있는 경우
				delPtr = *root;
				(*root) = (*root)->rightChild;
				delete delPtr;
				return true;
			} else if (!(*root)->rightChild) {
				//왼쪽 자식만 있는 경우
				delPtr = *root;
				(*root) = (*root)->leftChild;
				delete delPtr;
				return true;
			} else {
				//자식 2
				delPtr = (*root)->leftChild;
				while (!(delPtr->rightChild)) {
					delPtr = delPtr->rightChild;
				}
				(*root)->data = delPtr->data;
				return _delete(&(*root)->leftChild, delPtr->data);
			}
		}
	}

	bool Delete(int delKey) {
		if (_delete(&root, delKey)) {
			return true;
		}

		return false;
	}

	void _inOrder(NODE* root) {
		if (root) {
			_inOrder(root->leftChild);
			printf("%d ", root->data);
			_inOrder(root->rightChild);
		}
	}

	void PrintBst() {
		_inOrder(root);
		puts("");
	}

private:
	NODE * root;
	int count;
};

int main() {
	BST bst;

	bst.Insert(1);
	bst.PrintBst();
	bst.Insert(2);
	bst.PrintBst();	
	bst.Insert(3);
	bst.PrintBst();	
	bst.Insert(4);
	bst.PrintBst();	
	bst.Insert(5);
	bst.PrintBst();	
	bst.Insert(6);
	bst.PrintBst();

	bst.Delete(1);
	bst.PrintBst();
	bst.Delete(2);
	bst.PrintBst();
	bst.Delete(3);
	bst.PrintBst();
	bst.Delete(4);
	bst.PrintBst();
	bst.Delete(5);
	bst.PrintBst();
	bst.Delete(6);
	bst.PrintBst();
}