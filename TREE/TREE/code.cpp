#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//Ʈ���� ��带 ǥ���ϴ� ��ü�� ����
struct TreeNode {
	string label; // ������ �ڷ�(���� �� ���ڿ��� �ʿ�� ����.)
	TreeNode* parent; // �θ� ��带 ����Ű�� ������
	vector<TreeNode*> children; //�ڼ� ��带 ����Ű�� �������� �迭
};

//Ʈ���� ��ȸ�ϸ� ��� ��忡 ���Ե� ���� ����ϱ�
//�־��� Ʈ���� �� ��忡 ����� ���� ��� ����Ѵ�.
void printLabels(TreeNode* root) {
	//��Ʈ�� ����� ���� ����Ѵ�
	cout << root->label << endl;
	//�� �ڼյ��� ��Ʈ�� �ϴ� ����Ʈ���� ���Ե� ������ ��������� ����Ѵ�.
	for (int i = 0; i < root->children.size(); i++) {
		printLabels(root->children[i]);
	}
}

//��ȸ�� �̿��� Ʈ���� ���̸� ����ϱ�
//root�� ��Ʈ�� �ϴ� Ʈ���� ���̸� ���Ѵ�.
int height(TreeNode* root) {
	int h = 0;
	for (int i = 0; i < root->children.size(); i++) {
		h = max(h, 1 + height(root->children[i]));
	}
	return h;
}

//�ڵ� 21.4 Ʈ�� ��ȸ ���� ���� ������ �ذ��ϴ� ��� ȣ�� �ڵ�
vector<int> slice(const vector<int>& v, int a, int b) {
	return vector<int>(v.begin() + a, v.begin() + b);
}


//Ʈ���� ��带 ǥ���ϴ� ��ü�� ����
typedef int KeyType;
//Ʈ���� �� ��鸣 �����Ѵ�.
struct Node {
	KeyType key;
	//�� ����� �켱����(priority)
	//�� ��带 ��Ʈ�� �ϴ� ����Ʈ���� ũ��(size)
	int priority, size;
	//�� �ڽ� ����� ������
	Node *left, *right;
	// �����ڿ��� ���� �켱������ �����ϰ�, size�� left/right�� �ʱ�ȭ�Ѵ�.
	Node(const KeyType& _key) : key(_key), priority(rand()), size(1), left(NULL), right(NULL) {	}
	void setLeft(Node* newLeft) { left = newLeft; calcSize(); }
	void setRight(Node* newRight) { right = newRight; calcSize(); }
	//size ����� �����Ѵ�
	void calcSize() {
		size = 1;
		if (left) size += left->size;
		if (right) size += right->size;
	}
};

//Ʈ�������� ��� �߰��� �ɰ��� ������ ����
typedef pair<Node*, Node*> NodePair;
//root�� ��Ʈ�� �ϴ� Ʈ���� key �̸��� ���� �̻��� ���� ����
// �� ���� Ʈ������ �и��Ѵ�.
NodePair split(Node* root, KeyType key) {
	if (root == NULL) return NodePair(NULL, NULL);
	//��Ʈ�� Key �̸��̸� ������ ����Ʈ���� �ɰ���.
	if (root->key < key) {
		NodePair rs = split(root->right, key);
		root->setRight(rs.first);
		return NodePair(root, rs.second);
	}
	NodePair ls = split(root->left, key);
	root->setLeft(ls.second);
	return NodePair(ls.first, root);
}

// root�� ��Ʈ�� �ϴ� Ʈ���� �� ��� node�� ������ �� ��� Ʈ����
// ��Ʈ�� ��ȯ�Ѵ�.
Node* insert(Node* root, Node* node) {
	if (root == NULL) return node;
	// node�� ��Ʈ�� ��ü�ؾ� �Ѵ�. �ش� ����Ʈ���� ������ �߶�
	// ���� �ڼ����� �Ѵ�.
	if (root->priority < node->priority) {
		NodePair splitted = split(root, node->key);
		node->setLeft(splitted.first);
		node->setRight(splitted.second);
		return node;
	} else if (node->key < root->key) {
		root->setLeft(insert(root->left, node));
	} else {
		root->setRight(insert(root->right, node));
	}
	return root;
}

//Ʈ������ ����� ������ ��ġ�� ������ ����
// a�� b�� �� ���� Ʈ���̰�, max(a) < min(b)�� �� �� ���� ��ģ��.
Node* merge(Node* a, Node* b) {
	if (a == NULL) return b;
	if (b == NULL) return a;
	if (a->priority < b->priority) {
		b->setLeft(merge(a, b->left));
		return b;
	}
	a->setRight(merge(a->right, b));
	return a;
}

//root�� ��Ʈ�� �ϴ� Ʈ������ key�� ����� ��� Ʈ���� ��Ʈ�� ��ȯ�Ѵ�.
Node* erase(Node* root, KeyType key) {
	if (root = NULL) return root;
	//root�� ����� �� ����Ʈ���� ��ģ �� ��ȯ�Ѵ�.
	if (root->key == key) {
		Node* ret = merge(root->left, root->right);
		delete root;
		return ret;
	}
	if (key < root->key) {
		root->setLeft(erase(root->left, key));
	} else {
		root->setRight(erase(root->right, key));
	}
	return root;
}

//Ʈ������ k��° ���Ҹ� ã�� �˰����� ����
//root�� ��Ʈ�� �ϴ� Ʈ�� �߿��� k��° ���Ҹ� ��ȯ�Ѵ�.
Node* kth(Node* root, int k) {
	//���� ����Ʈ���� ũ�⸦ �켱 ����Ѵ�.
	int leftSize = 0;
	if (root->left != NULL) leftSize = root->left->size;
	if (k <= leftSize) return kth(root->left, k);
	if (k == leftSize + 1) return root;
	return kth(root->right, k - leftSize - 1);
}

//Ʈ������ X���� ���� ������ ���� ã�� �˰����� ����
//key���� ���� Ű ���� ���� ��ȯ�Ѵ�.
int countLessThan(Node* root, KeyType key) {
	if (root == NULL) return 0;
	if (root->key >= key) return countLessThan(root->left, key);
	int ls = (root->left ? root->left->size : 0);
	return ls + 1 + countLessThan(root->right, key);
}