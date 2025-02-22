#include <bits/stdc++.h>
using namespace std;
#define int long long

int toIdx(char c) { return c - 'a'; }

void solve() {
    string s;
    cin >> s;
    if (s == string(s.rbegin(), s.rend())) {
        cout << 0 << '\n';
        return;
    }

    int l = 0, r = s.size() - 1;
    while (l < r && s[l] == s[r]) {
        l++;
        r--;
    }
    string t = s.substr(l, r - l + 1);
    const int n = t.size();
    int ans = n;
    for (int z = 0; z < 2; ++z) {
        // lo -> impossible, hi -> possible
        int lo = 0;
        int hi = n;
        while (lo + 1 < hi) {
            int mid = (lo + hi) / 2;
            vector<int> cnt(26);
            for (int i = 0; i < mid; ++i) {
                cnt[toIdx(t[i])]++;
            }
            bool ok = true;
            for (int i = 0; i < min(n / 2, n - mid); ++i) {
                char c = t[n - i - 1];
                if (i < mid) {
                    ok &= cnt[toIdx(c)] > 0;
                    cnt[toIdx(c)]--;
                } else {
                    ok &= (c == t[i]);
                }
            }
            for (auto x : cnt) ok &= (x % 2 == 0);
            if (ok) {
                hi = mid;
            } else {
                lo = mid;
            }
        }
        ans = min(ans, hi);
        reverse(t.begin(), t.end());
    }
    cout << ans << '\n';
}

// https://codeforces.com/contest/2069/problem/D
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}