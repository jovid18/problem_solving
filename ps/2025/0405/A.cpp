#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>

// https://atcoder.jp/contests/abc400/tasks/abc400_a
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int x;
    cin >> x;
    int y = 400 / x;
    cout << (x * y == 400 ? y : -1);
}