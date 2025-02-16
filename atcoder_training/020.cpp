#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>

// https://atcoder.jp/contests/abc077/tasks/arc084_a
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int N;
    cin >> N;
    vector<int> A(N), B(N), C(N);
    for (auto &x : A) cin >> x;
    for (auto &x : B) cin >> x;
    for (auto &x : C) cin >> x;
    sort(A.begin(), A.end());
    sort(C.begin(), C.end());
    int ans = 0;
    for (auto x : B) {
        // 미만 찾기
        int a = lower_bound(A.begin(), A.end(), x) - A.begin();
        // 초과 찾기
        int c = C.end() - upper_bound(C.begin(), C.end(), x);
        ans += a * c;
    }
    cout << ans;
}