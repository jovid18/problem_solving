#include <iostream>
#include <string>
#include <vector>
using namespace std;
using pii = pair<int, int>;
pii DP[1 << 17];
vector<vector<int>> G;
void dfs(int state, int n, vector<int> &info, vector<int> visited) {
    for (auto f : visited) {
        for (auto &e : G[f]) {
            int newstate = state | (1 << e);
            if (DP[newstate] != make_pair(-1, -1))
                continue;
            if (info[e] == 0) {
                DP[newstate] = {DP[state].first + 1, DP[state].second};
            } else {
                if (DP[state].first == DP[state].second + 1)
                    continue;
                DP[newstate] = {DP[state].first, DP[state].second + 1};
            }
            auto newvisited = visited;
            newvisited.push_back(e);
            dfs(newstate, e, info, newvisited);
        }
    }
}
int solution(vector<int> info, vector<vector<int>> edges) {
    int N = info.size();
    G.resize(N);
    for (auto &e : edges) {
        G[e[0]].push_back(e[1]);
        G[e[1]].push_back(e[0]);
    }
    for (int i = 0; i < (1 << N); i++) {
        DP[i] = {-1, -1};
    }
    if (info[0] == 0)
        DP[1] = {1, 0};
    else
        DP[1] = {0, 1};
    vector<int> visited;
    visited.push_back(0);
    dfs(1, 0, info, visited);
    int answer = 0;
    for (int i = 0; i < (1 << N); i++) {
        if (DP[i].first > DP[i].second)
            answer = max(answer, DP[i].first);
    }
    return answer;
}
