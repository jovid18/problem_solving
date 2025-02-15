#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>

// https://atcoder.jp/contests/abc150/tasks/abc150_c
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int N;
    cin >> N;
    vector<int> P(N), Q(N), perm(N);
    for (auto &x : P) cin >> x;
    for (auto &x : Q) cin >> x;
    iota(perm.begin(), perm.end(), 1);
    int a, b;
    int cnt = 0;
    do {
        cnt++;
        if (perm == P) a = cnt;
        if (perm == Q) b = cnt;
    } while (next_permutation(perm.begin(), perm.end()));
    cout << abs(a - b) << endl;
}