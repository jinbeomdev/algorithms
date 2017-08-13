#include <string>

using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
string solution(string sentence) {
	string answer = "";
	int pos = 0;

	//문자열 끝까지
	while (pos < sentence.size()) {

		//처음에 소문자(특수기호)가 나오면 문자의 끝에 소문자가 나와야 한다
		if (sentence[pos] < 'A' || sentence[pos] > 'Z') {

			pos++;

			//새로운 소문자(특수기호)를 만날 때 까지 고고싱!
			while (sentence[pos] >= 'A' && sentence[pos] <= 'Z')
				pos++;
			answer += sentence.substr()
		}

		//처음에 대문자가 나오면 문자들의 사이에 소문자가 나와야 한다
		if (sentence[pos] >= 'A' && sentence[pos] <= 'Z') {

		}
	}
}