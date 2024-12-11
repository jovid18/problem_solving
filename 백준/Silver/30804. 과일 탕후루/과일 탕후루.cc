#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<int> v, cur(10);

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int N;
    cin >> N;
    v.resize(N);
    for (auto &e : v) {
        cin >> e;
    }
    int l = 0;
    int ans = 1;
    cur[v[0]]++;
    for (int r = 1; r < N; r++) {
        cur[v[r]]++;
        while (1) {
            int cnt = 0;
            for (int i = 1; i <= 9; i++) {
                if (cur[i] > 0) {
                    cnt++;
                }
            }
            if (cnt > 2) {
                cur[v[l]]--;
                l++;
            } else {
                break;
            }
        }
        ans = max(ans, r - l + 1);
    }
    cout << ans;
}