#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>

int DP[50001];

// https://onlinejudge.u-aizu.ac.jp/problems/DPL_1_A
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int value, count;
    cin >> value >> count;
    vector<int> coins(count);
    for (int i = 0; i < count; i++) {
        cin >> coins[i];
    }
    for (int i = 1; i <= value; i++) {
        DP[i] = 1e9;
    }
    for (int i = 0; i < count; i++) {
        for (int j = coins[i]; j <= value; j++) {
            DP[j] = min(DP[j], DP[j - coins[i]] + 1);
        }
    }
    cout << DP[value] << '\n';
}