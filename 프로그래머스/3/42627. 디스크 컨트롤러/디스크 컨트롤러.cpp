#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;
using pii = pair<int, int>;

struct comp {
    bool operator()(const pii &a, const pii &b) const {
        if (a.second == b.second)
            return a.first > b.first;
        else
            return a.second > b.second;
    }
};

priority_queue<pii, vector<pii>, comp> pq;

int solution(vector<vector<int>> jobs) {
    vector<pii> s;
    for (auto &e : jobs) {
        s.push_back({e[0], e[1]});
    }
    sort(s.begin(), s.end());

    int answer = 0, now = 0, i = 0, jobs_count = jobs.size();
    while (i < jobs_count || !pq.empty()) {
        if (i < jobs_count && s[i].first <= now) {
            pq.push(s[i++]);
            continue;
        }
        if (!pq.empty()) {
            auto e = pq.top();
            pq.pop();
            now += e.second;
            answer += now - e.first;
        } else if (i < jobs_count) {
            now = s[i].first;
        }
    }

    return answer / jobs_count;
}
