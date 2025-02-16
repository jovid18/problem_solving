#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>

// https://atcoder.jp/contests/abc393/tasks/abc393_a
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    string s1, s2;
    cin >> s1 >> s2;
    if (s1 == "fine" && s2 == "fine") {
        cout << 4;
    }
    if (s1 == "sick" && s2 == "fine") {
        cout << 2;
    }
    if (s1 == "fine" && s2 == "sick") {
        cout << 3;
    }
    if (s1 == "sick" && s2 == "sick") {
        cout << 1;
    }
}