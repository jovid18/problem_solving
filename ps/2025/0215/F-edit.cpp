#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9 + 100;

// https://atcoder.jp/contests/abc393/tasks/abc393_f
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int &i : a) cin >> i;
    vector<vector<pair<int, int>>> qs(n);
    for (int i = 0; i < q; i++) {
        int r, x;
        cin >> r >> x;
        qs[--r].emplace_back(i, x);
    }
    vector<int> ans(q);
    // dp[i] = 길이가 i인 증가하는 부분수열 중 가장 작은 마지막 원소
    vector<int> dp(n, inf);
    for (int i = 0; i < n; i++) {
        auto it = lower_bound(dp.begin(), dp.end(), a[i]);
        *it = a[i];
        // id: 쿼리 번호, x: 쿼리 값, i: 길이
        for (auto [id, x] : qs[i]) {
            ans[id] = upper_bound(dp.begin(), dp.end(), x) - dp.begin();
        }
    }
    for (int i = 0; i < q; i++) {
        cout << ans[i] << '\n';
    }
}