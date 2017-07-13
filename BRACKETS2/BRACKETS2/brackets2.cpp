//������ �̿��� ¦�� ���� �ʴ� ��ȣ ������ �ذ��ϴ� �˰����� ����
#include <iostream>
#include <string>
#include<stack>
using namespace std;

bool wellMatched(const string& formula) {
	//���� ��ȣ ���ڵ�� �ݴ� ��ȣ ���ڵ�
	const string opening("({["), closing(")}]");
	//�̹� ���� ��ȣ���� ������� ��� ����
	stack<char> openStack;
	for (int i = 0; i < formula.size(); ++i) {
		//���� ��ȣ���� �ݴ� ��ȣ���� Ȯ���Ѵ�
		if (opening.find(formula[i]) != -1)
			//���� ��ȣ��� ������ ���ÿ� ����ִ´�.
			openStack.push(formula[i]);
		else {

			//�� ���� ��� ���� �� ���� ���ڿ� ���纸��.
			//������ ��� �ִ� ��쿡�� ����
			if (openStack.empty()) return false;
			if (opening.find(openStack.top()) != closing.find(formula[i]))
				return false;
			//¦�� ���� ��ȣ�� ���ÿ��� ����.
			openStack.pop();
		}
		//������ ���� ��ȣ�� ����� ����
		return openStack.empty();
	}
}