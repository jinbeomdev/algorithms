#include <iostream>
#include <string>
#include <vector>
#include <math.h>
using namespace std;

//N���� �ڱ� �ڽ��� ã���鼭 ��Ÿ���� �κ� ��ġ�� �̿���
//pi[[]�� ����Ѵ�.
//pi[i]=N[..i]�� ���̻絵 �ǰ� ���λ絵 �Ǵ� ���ڿ��� �ִ����
vector<int> getPartialMatchNaive(const string& N) {
	int m = N.size();
	vector<int> pi(m, 0);

	//�ܼ��� ���ڿ� �˻� �˰����� �����Ѵ�.
	for (int begin = 1; begin < m; ++begin) {
		for (int i = 0; i < m; ++i) {
			if (N[begin + i] != N[i]) break;
			//i+1���ڰ� ���� �����Ǿ���.
			pi[begin + i] = max(pi[begin + i], i + 1);

		}
	}
}


vector<int> kmpSearch(const string& H, const string& N) {
	int n = H.size(), m = N.size();
	vector<int> ret;
	//pi[i]=N[..i]�� ���ð��� �ǰ� ���λ�� ���ڿ��� �ִ����
	vector<int> pi = getPartialMatch(N);
	//begin=matched=0�������� ��������.
	int begin = 0, matched = 0;
	while (begin <= n - m) { //�κ� ���ڿ��� ���̰� ���� ���ڿ��� �ʰ��� �� ���� ����
		//���࿡ ¤������ �ش� ���ڰ� �ٴ��� �ش� ���ڿ� ���ٸ�
		if (matched < m && H[begin + matched] == N[matched]) {
			++matched;
			//��������� m���ڰ� ��� ��ġ�ߴٸ� �信 �߰��Ѵ�.
			if (matched == m) ret.push_back(begin);
		}
		else {
			// ���� : matched�� 0�� ��쿡�� ���� ĭ�������� ���
			if (matched == 0)
				++begin;
			else {
				begin += matched - pi[matched - 1];
				//begin�� �Ű�ٰ� ó������ �ٽ� ���� �ʿ䰡 ����.
				//�ű� �Ŀ��� pi[matched - 1]��ŭ�� �׻� ��ġ�ϱ� �����̴�.
				matched = pi[matched - 1];
			}
		}
	}
}