#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>

// https://atcoder.jp/contests/abc122/tasks/abc122_b
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    string S;
    cin >> S;
    vector<char> v = {'A', 'C', 'G', 'T'};
    int ans = 0;
    int cnt = 0;
    for (auto e : S) {
        if (find(v.begin(), v.end(), e) != v.end()) {
            cnt++;
            ans = max(ans, cnt);
        } else {
            cnt = 0;
        }
    }
    cout << ans << '\n';
}