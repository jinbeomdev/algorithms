#include <string>
#include <vector>

using namespace std;

pair<int, vector<int>> answer;

void dfs(const vector<int>& healths, const vector<vector<int>>& items,
				 int power, int healths_index, vector<bool>& usage) {
	if (healths_index == healths.size()) {
		if (power > answer.first) {
			answer.first = power;

			answer.second.clear();
			vector<int> temp;
			for (int i = 0; i < usage.size(); i++) {
				if (usage[i]) {
					temp.push_back(i + 1);
				}
			}
			answer.second = temp;
		}

		return;
	}

	for (int i = 0; i < items.size(); i++) {
		if (!usage[i] && healths[healths_index] - items[i][1] >= 100) {
			usage[i] = true;
			dfs(healths, items, power + items[i][0], healths_index + 1, usage);
			usage[i] = false;
		} else {
			dfs(healths, items, power, healths_index + 1, usage);
		}
	}
}

vector<int> solution(vector<int> healths, vector<vector<int>> items) {
	answer.first = 0;
	answer.second.clear();

	vector<bool> usage;
	usage.resize(items.size(), false);

	dfs(healths, items, 0, 0, usage);

	return answer.second;
}

int main() {
	vector<int> healths;
	healths.push_back(200);
	healths.push_back(120);
	healths.push_back(150);

	vector<vector<int>> items;
	vector<int> item;
	item.push_back(30);
	item.push_back(100);
	items.push_back(item);
	item.clear();

	item.push_back(500);
	item.push_back(30);
	items.push_back(item);
	item.clear();

	item.push_back(100);
	item.push_back(400);
	items.push_back(item);
	item.clear();

	solution(healths, items);

	return 0;
}