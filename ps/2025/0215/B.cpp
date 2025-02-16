#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>

// https://atcoder.jp/contests/abc393/tasks/abc393_b
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    string s;
    cin >> s;
    int n = s.size();
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            for (int k = j + 1; k < n; ++k) {
                if (j - i != k - j) continue;
                if (s[i] == 'A' && s[j] == 'B' && s[k] == 'C') ans++;
            }
        }
    }
    cout << ans;
}