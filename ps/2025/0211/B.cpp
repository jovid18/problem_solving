#include <bits/stdc++.h>
using namespace std;
#define int long long

// https://codeforces.com/contest/2067/problem/B
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<bool> is_visited(n + 1, false);
    vector<bool> is_possible(2 * n, false);
    for (auto &e : a) cin >> e;
    bool ans = true;
    sort(a.begin(), a.end());
    for (int i = 1; i < n; i++) {
        if (is_visited[i] || is_visited[i - 1]) {
            continue;
        }
        if (a[i] == a[i - 1]) {
            is_visited[i] = true;
            is_visited[i - 1] = true;
            is_possible[a[i]] = true;
        }
        for (int j = 0; j < n; ++j) {
            if (is_visited[j]) {
                continue;
            }
            while (is_possible[a[j]]) {
                a[j]++;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (!is_visited[i]) {
            ans = false;
            break;
        }
    }
    cout << (ans ? "Yes" : "No") << endl;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}