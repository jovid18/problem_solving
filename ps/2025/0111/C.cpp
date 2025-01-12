#include <bits/stdc++.h>
using namespace std;
#define int long long
int N;
vector<int> A;
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    A.resize(N);
    for (auto &e : A) cin >> e;
    int ans = 0;
    for (int i = 0; i < N; i++) {
        int idx = lower_bound(A.begin(), A.end(), 2 * A[i]) - A.begin();
        ans += N - idx;
    }
    cout << ans;
}