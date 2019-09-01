#include <string>
#include <vector>

#include <map>

#include <iostream>
#include <sstream>

using namespace std;

const string ENTER = "Enter";
const string LEAVE = "Leave";
const string CHANGE = "Change";

vector<string> split(const string str, char delim= ' ') {
    vector<string> ret;
    stringstream ss(str);
    string token;
    while (getline(ss, token, delim)) {
        ret.push_back(token);
    }
    return ret;
}

vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string, string> nameMap;

    for (int idx = 0; idx < record.size(); idx++) {
        vector<string> tokens = split(record[idx]);
        if (tokens[0] == ENTER || tokens[0] == CHANGE) {
            nameMap[tokens[1]] = tokens[2];
        }
    }

    for (int idx = 0; idx < record.size(); idx++) {
        vector<string> tokens = split(record[idx]);
        if (tokens[0] == ENTER) {
            answer.push_back(nameMap[tokens[1]] + "님이 " + "들어왔습니다.");
        } else if (tokens[0] == LEAVE) {
            answer.push_back(nameMap[tokens[1]] + "님이 " + "나갔습니다.");
        } else {
            //pass
        }
    }
    
    return answer;
}