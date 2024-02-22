#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;
int par[101], siz[101];
int find(int x) { return x == par[x] ? x : (par[x] = find(par[x])); }
bool unite(int x, int y) {
    int u = find(x), v = find(y);
    if (u == v)
        return false;
    if (siz[u] > siz[v])
        swap(u, v);
    siz[v] += siz[u];
    par[u] = par[v];
    return true;
}
struct Compare {
    bool operator()(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {
        return a.first > b.first;
    }
};
int solution(int n, vector<vector<int>> costs) {
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
                   Compare>
        pq;
    for (int i = 0; i < n; ++i) {
        par[i] = i;
        siz[i] = 1;
    }
    int answer = 0;
    for (auto &cost : costs) {
        pq.push({cost[2], {cost[0], cost[1]}});
    }
    while (!pq.empty()) {
        auto [c, p] = pq.top();
        pq.pop();
        if (unite(p.first, p.second)) {
            answer += c;
        }
    }
    return answer;
}