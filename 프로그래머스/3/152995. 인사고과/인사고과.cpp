#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
using pii = pair<int, int>;
vector<pii> v;
bool comp(const pii &a, const pii &b) {
    if (a.first + a.second == b.first + b.second) {
        return a.first < b.first;
    } else {
        return a.first + a.second < b.first + b.second;
    }
}
int solution(vector<vector<int>> scores) {
    int wanhoscore = scores[0][0] + scores[0][1];
    pii wanho = {scores[0][0], scores[0][1]};
    for (auto e : scores) {
        v.push_back({e[0], e[1]});
        if (wanho.first < e[0] && wanho.second < e[1]) {
            return -1;
        }
    }
    sort(v.begin(), v.end(), comp);
    long long answer = 0;
    long long same = 0;
    for (int i = 0; i < v.size(); ++i) {
        if (v[i].first + v[i].second < wanhoscore) {
            continue;
        }
        bool isOk = true;
        for (int j = i + 1; j < v.size(); ++j) {
            if (v[i].first < v[j].first && v[i].second < v[j].second) {
                isOk = false;
                break;
            }
        }
        if (isOk) {
            answer++;
            if (v[i].first + v[i].second == wanhoscore) {
                same++;
            }
        }
    }
    return answer - same + 1;
}