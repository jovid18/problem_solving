#include <iostream>
#include <string.h>
#include <string>
#include <vector>
using namespace std;
vector<vector<int>> G;
bool visited[101];
int info[101];
void dfs(int v) {
    visited[v] = 1;
    for (auto next : G[v]) {
        if (visited[next] == 0) {
            dfs(next);
        }
    }
}
int solution(int n, vector<vector<int>> results) {
    G.resize(n + 1);
    for (auto e : results) {
        G[e[0]].push_back(e[1]);
    }
    for (int i = 1; i <= n; i++) {
        memset(visited, 0, sizeof(visited));
        dfs(i);
        for (int j = 1; j <= n; j++) {
            if (i == j)
                continue;
            if (visited[j]) {
                info[i]++;
                info[j]++;
            }
        }
    }
    int answer = 0;
    for (int i = 1; i <= n; i++) {
        if (info[i] == n - 1) {
            answer++;
        }
    }
    return answer;
}