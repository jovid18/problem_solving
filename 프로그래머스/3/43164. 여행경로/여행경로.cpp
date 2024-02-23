#include <bits/stdc++.h>
using namespace std;
map<string, int> m;
map<int, string> rm;
map<string, int> check;
vector<vector<int>> G;
vector<vector<string>> answer;
int total = 0;
void dfs(int s, int p, vector<string> v, map<string, int> used) {
    v.push_back(rm[s]);
    if (v.size() == G.size() + 1) {
        answer.push_back(v);
        return;
    }
    for (auto e : G[s]) {
        if (used[rm[s] + rm[e]] <= 0)
            continue;
        used[rm[s] + rm[e]]--;
        dfs(e, s, v, used);
        used[rm[s] + rm[e]]++;
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    int n = tickets.size();
    G.resize(n);
    int number = 0;
    int cnt = 1;
    for (auto e : tickets) {
        if (m.find(e[0]) == m.end())
            m[e[0]] = number++;
        if (m.find(e[1]) == m.end())
            m[e[1]] = number++;
        G[m[e[0]]].push_back(m[e[1]]);
        rm[m[e[0]]] = e[0];
        rm[m[e[1]]] = e[1];
        if (check.find(e[0] + e[1]) == check.end()) {
            check[e[0] + e[1]] = 1;
        } else {
            check[e[0] + e[1]]++;
        }
    }
    total = number;
    int s = m["ICN"];
    auto used = check;
    dfs(s, -1, {}, used);
    sort(answer.begin(), answer.end());
    return answer[0];
}