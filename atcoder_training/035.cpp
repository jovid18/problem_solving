#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>

int DP[10001];

// https://onlinejudge.u-aizu.ac.jp/problems/DPL_1_B
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, w;
    cin >> n >> w;
    vector<pii> items(n);
    for (int i = 0; i < n; i++) {
        int value, weight;
        cin >> value >> weight;
        for (int i = w; i >= weight; i--) {
            DP[i] = max(DP[i], DP[i - weight] + value);
        }
    }
    cout << DP[w] << '\n';
}