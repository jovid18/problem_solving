#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> cnt(n + 1);
    vector<bool> isDeletable(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    auto b = a;
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    int init = a.size() - b.size();
    if (init == 0) {
        // 모든 원소가 서로 다름
        cout << 1 << ' ' << n << '\n';
        return;
    } else if (b.size() == 1) {
        // 하나의 원소로 구성
        cout << 0 << '\n';
        return;
    } else {
        int maxLen = 0;
        int l = -1, r = -1;
        int currLen = 0;
        for (int i = 0; i < n; ++i) {
            if (cnt[a[i]] == 1) {
                isDeletable[i] = true;
            }
        }
        for (int i = 0; i < n; i++) {
            if (isDeletable[i]) {
                currLen++;
                if (maxLen < currLen) {
                    maxLen = currLen;
                    l = i - currLen + 1;
                    r = i;
                }
            } else {
                currLen = 0;
            }
        }
        if (maxLen == 0) {
            cout << 0 << '\n';
            return;
        } else {
            cout << l + 1 << ' ' << r + 1 << '\n';
        }
    }
}

// https://codeforces.com/contest/2064/problem/B
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}