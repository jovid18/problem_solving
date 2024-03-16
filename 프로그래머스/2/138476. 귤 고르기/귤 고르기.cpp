#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int cnt[100001];
vector<pair<int, int>> s;
int solution(int k, vector<int> tangerine) {
    sort(tangerine.begin(), tangerine.end());
    auto v = tangerine;
    v.erase(unique(v.begin(), v.end()), v.end());
    for (int i = 0; i < tangerine.size(); i++) {
        auto idx = lower_bound(v.begin(), v.end(), tangerine[i]) - v.begin();
        cnt[idx]++;
    }
    for (int i = 0; i < 100001; i++) {
        if (cnt[i] == 0)
            continue;
        s.push_back({cnt[i], i + 1});
    }
    sort(s.begin(), s.end());
    int sum = 0;
    int answer = 0;
    while (sum < k) {
        sum += s.back().first;
        s.pop_back();
        answer++;
    }
    return answer;
}