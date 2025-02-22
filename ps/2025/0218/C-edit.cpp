#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MOD = 998244353;

int add(int x, int y) {
    x += y;
    if (x >= MOD) x -= MOD;
    return x;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    // dp[i][j] - 처음 i개의 원소를 고려했을 때, 현재 상태 j일때의 부분 수열의 개수
    // 상태 0은 아직 아무 원소도 선택되지 않은(빈) 상태
    // 상태 1은 값이 1인 원소를 선택한 상태
    // 상태 2는 값이 2인 원소들을 (하나 이상) 선택한 상태
    // 상태 3은 값이 3인 원소를 선택했고, 그로써 시퀀스가 완성된 상태
    vector<int> dp(4, 0);
    dp[0] = 1;
    for (auto x : a) {
        if (x == 2) dp[x] = add(dp[x], dp[x]);
        dp[x] = add(dp[x], dp[x - 1]);
    }
    cout << dp[3] << '\n';
}

// https://codeforces.com/contest/2069/problem/C
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}