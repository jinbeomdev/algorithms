#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

pair<int, int> toSeconds(const string& line) {
	vector<string> tokens;

	stringstream ss(line);
	string intermediate;

	getline(ss, intermediate, ' ');
	getline(ss, intermediate, ' ');

	double h = ((intermediate[0] - '0') * 10 + intermediate[1] - '0') * 3600;
	double m = ((intermediate[3] - '0') * 10 + intermediate[4] - '0') * 60;
	double s = ((intermediate[6] - '0') * 10 + intermediate[7] - '0');
	double f = (intermediate[9] - '0') * 0.1 + (intermediate[10] - '0') * 0.01 + (intermediate[11] - '0') * 0.001;
	double range;
	ss >> range;
	
	int time = (h + m + s + f) * 1000;
	return make_pair(time - range * 1000 + 1, time);
}

int solution(vector<string> lines) {
	vector<pair<int, int>> ranges;

	for (int i = 0; i < lines.size(); i++) {
		ranges.push_back(toSeconds(lines[i]));
	}

	int answer = 0;
	for (int i = 0; i < ranges.size(); i++) {
		int cnt_first = 0;
		int cnt_last = 0;

		for (int j = 0; j < ranges.size(); j++) {
			if (ranges[i].first - 999 <= ranges[j].second && ranges[i].first >= ranges[j].second) { //-999~first
				cnt_first++;
			} else if (ranges[i].first >= ranges[j].first && ranges[i].first <= ranges[j].second) {
				cnt_first++;
			} else if (ranges[i].first - 999 >= ranges[j].first && ranges[i].first <= ranges[j].second) {
				cnt_first++;
			}

			if (ranges[i].second <= ranges[j].second && ranges[i].second + 999 >= ranges[j].second) {
				cnt_last++;
			} else if (ranges[i].second >= ranges[j].first && ranges[i].second <= ranges[j].second) {
				cnt_last++;
			} else if (ranges[i].second + 999 >= ranges[j].first && ranges[i].second <= ranges[j].second) {
				cnt_last++;
			}
		}

		answer = max(answer, max(cnt_first, cnt_last));
	}

	return answer;
}

int main() {
	vector<string> v;
	string s;
	s = "20160915 20:59:57.421 0.351s";
	v.push_back(s);
	s = "20160915 20:59:58.233 1.181s";
	v.push_back(s);
	s = "20160915 20:59:58.299 0.8s";
	v.push_back(s);
	s = "20160915 20:59:58.688 1.041s";
	v.push_back(s);
	s = "20160915 20:59:59.591 1.412s";
	v.push_back(s);
	s = "20160915 21:00:00.464 1.466s";
	v.push_back(s);
	s = "20160915 21:00:00.741 1.581s";
	v.push_back(s);
	s = "20160915 21:00:00.748 2.31s";
	v.push_back(s);
	s = "20160915 21:00:00.966 0.381s";
	v.push_back(s);
	s = "20160915 21:00:02.066 2.62s";
	v.push_back(s);
	solution(v);
}