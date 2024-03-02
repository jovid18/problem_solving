#include <bits/stdc++.h>
using namespace std;
#define int long long
int N;
int DP[2000][2000];
int V[2000];
int solve(int l, int r) {
    if (DP[l][r] != 0)
        return DP[l][r];
    if (l == r) {
        return DP[l][r] = N * V[l];
    }
    int k = N - (r - l);
    return DP[l][r] =
               max(k * V[l] + solve(l + 1, r), k * V[r] + solve(l, r - 1));
}
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> V[i];
    }
    cout << solve(0, N - 1);
}