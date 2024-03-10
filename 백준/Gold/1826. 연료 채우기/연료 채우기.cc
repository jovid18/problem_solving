#include <bits/stdc++.h>
using namespace std;
#define int long long
using pii = pair<int, int>;
int N, L, P, ans, now;
vector<pii> v;
priority_queue<int> pq;
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    v.resize(N);
    for (auto &e : v) {
        cin >> e.first >> e.second;
    }
    cin >> L >> P;
    sort(v.begin(), v.end());
    v.push_back({L, 0});
    for (int i = 0; i < v.size(); i++) {
        int dist = v[i].first - now;
        while (P < dist) {
            if (pq.empty()) {
                cout << -1;
                return 0;
            }
            P += pq.top();
            pq.pop();
            ans++;
        }
        P -= dist;
        now = v[i].first;
        pq.push(v[i].second);
    }
    cout << ans;
}