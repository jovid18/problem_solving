#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<vector<int>> G;
int N;
int light[100001];
int ans = 0;
void dfs(int v, int p) {
    for (auto e : G[v]) {
        if (e == p)
            continue;
        dfs(e, v);
        if (light[e] == 0 && light[v] == 0) {
            light[v] = 1;
            ans++;
        }
    }
}
int solution(int n, vector<vector<int>> lighthouse) {
    N = n;
    G.resize(n + 1);
    for (auto e : lighthouse) {
        G[e[0]].push_back(e[1]);
        G[e[1]].push_back(e[0]);
    }
    dfs(1, 0);
    return ans;
}