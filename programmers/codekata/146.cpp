#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
map<string, int> g;
map<string, pair<int, int>> s;
vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    for (int i = 0; i < genres.size(); ++i) {
        g[genres[i]] += plays[i];
        if (s.find(genres[i]) == s.end()) {
            s[genres[i]] = {i, -1};
        } else {
            if (plays[s[genres[i]].first] < plays[i]) {
                s[genres[i]].second = s[genres[i]].first;
                s[genres[i]].first = i;
            } else if (plays[s[genres[i]].second] < plays[i]) {
                s[genres[i]].second = i;
            }
        }
    }
    vector<pair<int, string>> v;
    for (auto e : g) {
        v.push_back({e.second, e.first});
    }
    sort(v.begin(), v.end(), greater<pair<int, string>>());
    for (auto e : v) {
        answer.push_back(s[e.second].first);
        if (s[e.second].second != -1)
            answer.push_back(s[e.second].second);
    }
    return answer;
}