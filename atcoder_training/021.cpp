#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>

// https://atcoder.jp/contests/abc023/tasks/abc023_d
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> h(n), s(n);
    for (int i = 0; i < n; i++) cin >> h[i] >> s[i];
    auto chk = [&](int x) {
        vector<int> t(n);
        for (int i = 0; i < n; i++) {
            if (x < h[i]) return false;
            t[i] = (x - h[i]) / s[i];
        }
        sort(t.begin(), t.end());
        for (int i = 0; i < n; i++) {
            if (t[i] < i) return false;
        }
        return true;
    };
    int lo = 0, hi = 1LL << 60;
    // chk[lo] = false, chk[hi] = true
    while (lo + 1 < hi) {
        int mid = (lo + hi) >> 1;
        chk(mid) ? hi = mid : lo = mid;
    }
    cout << hi << '\n';
}