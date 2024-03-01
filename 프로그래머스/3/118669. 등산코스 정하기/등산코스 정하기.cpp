#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
using pii = pair<int, int>;
const int maxn = 50002;

vector<vector<pii>> G;
int chk[maxn];
int bestsummits;
int minimumdist = 1e7 + 1;
vector<int> dist;
vector<bool> visited;
bool isfinished = 0;
void dfs(int n, int p, int maxd) {
    if (isfinished)
        return;
    for (auto &e : G[n]) {
        if (e.first == p)
            continue;
        if (visited[e.first])
            continue;
        if (e.second > maxd)
            continue;
        if (chk[e.first] == 2)
            continue;
        if (chk[e.first] == 1) {
            isfinished = 1;
            return;
        }
        visited[e.first] = 1;
        dfs(e.first, n, maxd);
    }
}
void find(int n, vector<int> &gates) {
    int s = 0;
    int f = 1e7 + 1;
    while (s < f) {
        dist.assign(maxn, 1e7 + 1);
        visited.assign(maxn, 0);
        isfinished = 0;
        int m = (s + f) / 2;
        dist[n] = 0;
        visited[n] = 1;
        dfs(n, -1, m);
        if (isfinished) {
            f = m;
        } else {
            s = m + 1;
        }
    }
    if (s < minimumdist) {
        minimumdist = s;
        bestsummits = n;
    }
}

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates,
                     vector<int> summits) {
    sort(summits.begin(), summits.end());
    for (auto e : gates) {
        chk[e] = 1;
    }
    for (auto e : summits) {
        chk[e] = 2;
    }
    G.resize(n + 1);
    for (auto &p : paths) {
        G[p[0]].push_back({p[1], p[2]});
        G[p[1]].push_back({p[0], p[2]});
    }
    for (auto &p : summits) {
        find(p, gates);
    }
    vector<int> answer;
    answer.push_back(bestsummits);
    answer.push_back(minimumdist);
    return answer;
}