#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
#define pii pair<int, int>

// https://atcoder.jp/contests/abc400/tasks/abc400_c
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    int t = sqrtl(n / 2);
    int u = sqrtl(n / 4);
    cout << t + u << endl;
}