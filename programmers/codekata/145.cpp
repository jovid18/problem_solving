#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
int n, s, f;
int answer = 0;
map<string, int> m;
vector<vector<int>> adj;
void dfs(int n, int p, int d) {
    if (d > adj.size())
        return;
    if (n == f) {
        answer = answer == 0 ? d : min(answer, d);
        return;
    }
    for (auto e : adj[n]) {
        if (e == p)
            continue;
        dfs(e, n, d + 1);
    }
}
int solution(string begin, string target, vector<string> words) {
    n = words.size();
    if (find(words.begin(), words.end(), target) == words.end())
        return 0;
    for (int i = 0; i < n; i++) {
        m[words[i]] = i;
    }
    adj.resize(n + 1);
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int diff = 0;
            for (int k = 0; k < begin.size(); ++k) {
                if (words[i][k] != words[j][k])
                    diff++;
            }
            if (diff == 1) {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    s = find(words.begin(), words.end(), begin) != words.end() ? m[begin] : n;
    for (int i = 0; i < n; ++i) {
        int diff = 0;
        for (int j = 0; j < begin.length(); ++j) {
            if (begin[j] != words[i][j])
                diff++;
        }
        if (diff == 1)
            adj[s].push_back(i);
    }
    f = m[target];
    dfs(s, -1, 0);
    return answer;
}