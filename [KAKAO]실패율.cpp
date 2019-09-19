#include <string>
#include <vector>

#include <iostream>
#include <algorithm>

#include <stdio.h>

using namespace std;

int segTree[4 * 500];

int sum(int L, int R, int nodeNum, int nodeL, int nodeR) {
    if (R < nodeL || L > nodeR) return 0;
    if (L <= nodeL && R >= nodeR) return segTree[nodeNum];
    int mid = (nodeL + nodeR) / 2;
    return sum(L, R, nodeNum * 2, nodeL, mid) + 
        sum(L, R, nodeNum * 2 + 1, mid + 1, nodeR);
}

int update(int index, int nodeNum, int nodeL, int nodeR) {
    if (index < nodeL || index > nodeR) return segTree[nodeNum];
    if (nodeL == nodeR) return (segTree[nodeNum] += 1);
    int mid = (nodeL + nodeR) / 2;
    return segTree[nodeNum] = 
        update(index, nodeNum * 2, nodeL, mid) + 
        update(index, nodeNum * 2 + 1, mid + 1, nodeR);
}

void init() {
    for (int i = 0; i < 4 * 500; i++) {
        segTree[i] = 0;
    }
}

bool comp(pair<int, double> a, pair<int, double> b) {
    if(a.second == b.second) {
        return a.first < b.first;
    }
    return a.second > b.second;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<int, double>> vecPair;

    init();

    for (int i = 0; i < stages.size(); i++) {
        update(stages[i], 1, 0, N + 1);
        // printf("%d\n", sum(stages[i], stages[i], 1, 0, N + 1));
    }

    for (int i = 1; i <= N; i++) {
        double bunja = (double)sum(i, i, 1, 0, N + 1);
        double bunmo = (double)sum(i, N + 1, 1, 0, N + 1);
        double rateFail =  bunja / bunmo;
        // printf("%lf\n", rateFail);
        vecPair.push_back(make_pair(i, rateFail));
    }
    
    sort(vecPair.begin(), vecPair.end(), comp);

    for (int i = 0; i < vecPair.size(); i++) {
        answer.push_back(vecPair[i].first);
    }

    return answer;
}