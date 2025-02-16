#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>

vector<int> get_divisor(int n) {
    vector<int> divisor;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            divisor.push_back(i);
            if (i * i != n) divisor.push_back(n / i);
        }
    }
    return divisor;
}

// https://atcoder.jp/contests/abc106/tasks/abc106_b
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int N;
    cin >> N;
    int ans = 0;
    for (int i = 1; i <= N; ++i) {
        if (i & 1) {
            int siz = get_divisor(i).size();
            if (siz == 8) {
                ans++;
            }
        }
    }
    cout << ans << '\n';
}