#include <map>
#include <string>
#include <vector>
using namespace std;
using pii = pair<int, int>;
pii dp[100001];
map<int, pii> m;
vector<int> solution(int target) {
    for (int i = 0; i <= target; i++)
        dp[i] = {1e9, 1e9};
    dp[0] = {0, 0};
    m[50] = {1, 1};
    for (int i = 1; i <= 20; ++i) {
        m[i] = {1, 1};
    }
    for (int i = 1; i <= 20; ++i) {
        if (m.find(2 * i) == m.end()) {
            m[2 * i] = {1, 0};
        }
    }
    for (int i = 1; i <= 20; ++i) {
        if (m.find(3 * i) == m.end()) {
            m[3 * i] = {1, 0};
        }
    }
    for (int i = 0; i <= target; ++i) {
        for (auto it : m) {
            auto score = it.first;
            auto shoot = it.second.first;
            auto singleorbool = it.second.second;
            if (i + score <= target) {
                if (dp[i + score].first > dp[i].first + shoot) {
                    dp[i + score].first = dp[i].first + shoot;
                    dp[i + score].second = dp[i].second + singleorbool;
                } else {
                    if (dp[i + score].first == dp[i].first + shoot) {
                        dp[i + score].second = max(dp[i + score].second,
                                                   dp[i].second + singleorbool);
                    }
                }
            }
        }
    }

    vector<int> answer = {dp[target].first, dp[target].second};
    return answer;
}