#include <bits/stdc++.h>
using namespace std;
#define int long long

bool isPerfectSquare(int num) {
    if (num < 0) return false;
    int sqrtNum = static_cast<int>(std::sqrt(num));
    return sqrtNum * sqrtNum == num;
}

void solve() {
    int N;
    cin >> N;
    if (isPerfectSquare(N * (N + 1) / 2)) {
        cout << -1 << endl;
        return;
    }
    vector<int> ans;
    for (int i = 1; i <= N; ++i) {
        ans.push_back(i);
    }
    int sum = 0;
    for (int i = 0; i < N; ++i) {
        sum += ans[i];
        if (isPerfectSquare(sum)) {
            sum -= ans[i];
            swap(ans[i], ans[i + 1]);
            sum += ans[i];
        }
    }
    for (int i = 0; i < N; ++i) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
}

// https://codeforces.com/contest/2071/problem/B
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}