#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string toTime(int minute) {
	string time = "";
	int hour = minute / 60;
	int m = minute % 60;

	if (hour < 10) {
		time += "0";
	}

	time += to_string(hour);
	time += ":";

	if (m < 10) {
		time += "0";
	}

	time += to_string(m);

	return time;
}

int toMinute(string& a) {
	int a_hour = (a[0] - '0') * 10 + (a[1] - '0');
	int a_minute = (a[3] - '0') * 10 + (a[4] - '0');
	return a_hour * 60 + a_minute;
}

bool Comp(string& a, string& b) {
	return toMinute(a) < toMinute(b);
}

string solution(int n, int t, int m, vector<string> timetable) {
	sort(timetable.begin(), timetable.end(), Comp);

	int shuttle_time = 9 * 60;
	bool is_full = false;
	int answer;
	int shuttle_cnt;
	int people;

	for (shuttle_cnt = 0; shuttle_cnt < n; shuttle_cnt++, shuttle_time += t) {
		for (people = 0; people < m; people++) {
			if (timetable.empty()) break;
			if (toMinute(timetable.front()) > shuttle_time) break;
			answer = toMinute(timetable.front());
			timetable.erase(timetable.begin());
		}
	}

	shuttle_time -= t;

	if (shuttle_cnt == n && people == m) { //막차에 사람이 꽉 찼을 경우 마지막에 탄 사람보다 일찍 와야 함.
		return toTime(answer - 1);
	} else { //막차에 자리에 있을 경우 셔틀이 출발할 때 오면 됨.
		return toTime(shuttle_time);
	}
}

int main() {
	//	1, 1, 5, ["08:00", "08:01", "08:02", "08:03"]
	vector<string> timetable;
	timetable.push_back("23:59");
	timetable.push_back("23:59");
	timetable.push_back("23:59");
	timetable.push_back("23:59");
	timetable.push_back("23:59");
	timetable.push_back("23:59");
	timetable.push_back("23:59");
	timetable.push_back("23:59");
	timetable.push_back("23:59");
	timetable.push_back("23:59");
	timetable.push_back("23:59");
	timetable.push_back("23:59");
	timetable.push_back("23:59");
	timetable.push_back("23:59");
	timetable.push_back("23:59");
	timetable.push_back("23:59");
	timetable.push_back("23:59");
	cout << solution(10, 60, 45, timetable);
}