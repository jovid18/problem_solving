#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
// https://atcoder.jp/contests/s8pc-6/tasks/s8pc_6_b
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    int a_to_b = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
        a_to_b += b[i] - a[i];
    }
    int ent_to_a = 1LL << 60;
    for (int i = 0; i < n; ++i) {
        int sum = 0;
        for (int j = 0; j < n; ++j) {
            sum += abs(a[i] - a[j]);
        }
        ent_to_a = min(ent_to_a, sum);
    }
    int b_to_exit = 1LL << 60;
    for (int i = 0; i < n; ++i) {
        int sum = 0;
        for (int j = 0; j < n; ++j) {
            sum += abs(b[i] - b[j]);
        }
        b_to_exit = min(b_to_exit, sum);
    }
    cout << a_to_b + ent_to_a + b_to_exit << '\n';
}