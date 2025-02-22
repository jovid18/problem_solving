#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>

// https://atcoder.jp/contests/abc394/tasks/abc394_a
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    string s;
    cin >> s;
    string t = "";
    for (auto c : s) {
        if (c =='2') {
            t += '2';
        }
    }
    cout << t << '\n';
}