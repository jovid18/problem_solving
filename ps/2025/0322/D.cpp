#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>

// https://atcoder.jp/contests/abc398/tasks/abc398_d
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    pii man;
    cin >> n >> man.second >> man.first;
    man.second *= -1;
    string s;
    cin >> s;
    pii fire = {0, 0};
    set<pii> visited;
    visited.insert(fire);
    string ans = "";
    for (char c : s) {
        if (c == 'N') {
            man.second--;
            fire.second--;
        }
        if (c == 'S') {
            man.second++;
            fire.second++;
        }
        if (c == 'W') {
            man.first++;
            fire.first++;
        }
        if (c == 'E') {
            man.first--;
            fire.first--;
        }
        visited.insert(fire);
        if (visited.count(man)) {
            ans += "1";
        } else {
            ans += "0";
        }
    }
    cout << ans << '\n';
}