#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>

// https://atcoder.jp/contests/abc149/tasks/abc149_b
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int a, b, k;
    cin >> a >> b >> k;
    int x = min(a, k);
    a -= x;
    k -= x;
    int y = min(b, k);
    b -= y;
    cout << a << " " << b;
}