#include <string>

using namespace std;

// ���� ������ ������ ��� �Լ� ���� �ʱ�ȭ �ڵ带 �� �ۼ����ּ���.
string solution(string sentence) {
	string answer = "";
	int pos = 0;

	//���ڿ� ������
	while (pos < sentence.size()) {

		//ó���� �ҹ���(Ư����ȣ)�� ������ ������ ���� �ҹ��ڰ� ���;� �Ѵ�
		if (sentence[pos] < 'A' || sentence[pos] > 'Z') {

			pos++;

			//���ο� �ҹ���(Ư����ȣ)�� ���� �� ���� ����!
			while (sentence[pos] >= 'A' && sentence[pos] <= 'Z')
				pos++;
			answer += sentence.substr()
		}

		//ó���� �빮�ڰ� ������ ���ڵ��� ���̿� �ҹ��ڰ� ���;� �Ѵ�
		if (sentence[pos] >= 'A' && sentence[pos] <= 'Z') {

		}
	}
}