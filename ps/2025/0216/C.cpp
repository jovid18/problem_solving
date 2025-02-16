#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n;
    cin >> n;
    deque<int> dq;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        dq.push_back(x);
    }
    int ans = 0;
    // 음수면 그것 포함 뒤가 날라감
    // 양수면 그것 포함 앞이 날라감
    while (dq.size() && dq.front() > 0) {
        int x = dq.front();
        dq.pop_front();
        ans += abs(x);
    }
    while (dq.size() && dq.back() < 0) {
        int x = dq.back();
        dq.pop_back();
        ans += abs(x);
    }
    vector<int> v;
    while (dq.size()) {
        v.push_back(dq.front());
        dq.pop_front();
    }
    n = v.size();
    vector<int> plus(n, 0), minus(n, 0);
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        if (v[i] > 0) {
            sum += v[i];
        }
        plus[i] = sum;
    }
    sum = 0;
    for (int i = n - 1; i >= 0; --i) {
        if (v[i] < 0) {
            sum += v[i];
        }
        minus[i] = sum;
    }
    int best = 0;
    for (int i = 0; i < n; ++i) {
        best = max(best, plus[i] - minus[i]);
    }
    cout << ans + best << '\n';
}

// https://codeforces.com/contest/2064/problem/C
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}