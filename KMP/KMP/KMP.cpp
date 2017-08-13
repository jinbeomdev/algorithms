#include <iostream>
#include <string>
#include <vector>
#include <math.h>
using namespace std;

//N에서 자기 자신을 찾으면서 나타나는 부분 일치를 이용해
//pi[[]를 계산한다.
//pi[i]=N[..i]의 접미사도 되고 접두사도 되는 문자열의 최대길이
vector<int> getPartialMatchNaive(const string& N) {
	int m = N.size();
	vector<int> pi(m, 0);

	//단순한 문자열 검색 알고리즘을 구현한다.
	for (int begin = 1; begin < m; ++begin) {
		for (int i = 0; i < m; ++i) {
			if (N[begin + i] != N[i]) break;
			//i+1글자가 서로 대응되었다.
			pi[begin + i] = max(pi[begin + i], i + 1);

		}
	}
}


vector<int> kmpSearch(const string& H, const string& N) {
	int n = H.size(), m = N.size();
	vector<int> ret;
	//pi[i]=N[..i]의 접시가도 되고 접두사는 문자열의 최대길이
	vector<int> pi = getPartialMatch(N);
	//begin=matched=0에서부터 시작하자.
	int begin = 0, matched = 0;
	while (begin <= n - m) { //부분 문자열의 길이가 원래 문자열를 초과할 수 없기 때문
		//만약에 짚더미의 해당 글자가 바늘의 해당 글자와 같다면
		if (matched < m && H[begin + matched] == N[matched]) {
			++matched;
			//결과적으로 m글자가 모두 일치했다면 답에 추가한다.
			if (matched == m) ret.push_back(begin);
		}
		else {
			// 예외 : matched가 0인 경우에는 다음 칸에서부터 계속
			if (matched == 0)
				++begin;
			else {
				begin += matched - pi[matched - 1];
				//begin을 옮겼다고 처음부터 다시 비교할 필요가 없다.
				//옮긴 후에도 pi[matched - 1]만큼은 항상 일치하기 때문이다.
				matched = pi[matched - 1];
			}
		}
	}
}