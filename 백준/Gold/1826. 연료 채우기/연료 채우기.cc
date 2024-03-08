#include <bits/stdc++.h>
using namespace std;
#define int long long
int N, L, P;
vector<pair<int, int>> v;
struct cmp1 {
    bool operator()(pair<int, int> a, pair<int, int> b) {
        return a.first > b.first;
    }
};
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    v.resize(N);
    for (auto &e : v) {
        cin >> e.first >> e.second;
    }
    sort(v.begin(), v.end());
    cin >> L >> P;
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp1> pq;
    pq.push({P, 0});
    for (auto e : v) {
        while (pq.size() && pq.top().first < e.first) {
            pq.pop();
        }
        if (pq.empty()) {
            cout << -1;
            return 0;
        }
        vector<int> temp;
        temp.assign(10001, -1);
        while (pq.size()) {
            temp[pq.top().second] = max(temp[pq.top().second], pq.top().first);
            temp[pq.top().second + 1] =
                max(temp[pq.top().second + 1], pq.top().first + e.second);
            pq.pop();
        }
        for (int i = 0; i < 10001; i++) {
            if (temp[i] != -1) {
                pq.push({temp[i], i});
            }
        }
    }
    while (pq.size() && pq.top().first < L) {
        pq.pop();
    }
    if (pq.empty()) {
        cout << -1;
        return 0;
    }
    int ans = 0x3f3f3f3f;
    while (pq.size()) {
        ans = min(ans, pq.top().second);
        pq.pop();
    }
    cout << ans;
}