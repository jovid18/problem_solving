#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
#define ld long double

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    int K = n - 1;
    int P10 = 1;
    for (int i = 0; i < K; i++) {
        P10 = (P10 * 10) % m;
    }

    vector<vector<vector<int>>> r1(n, vector<vector<int>>(n));
    vector<vector<vector<int>>> r2(n, vector<vector<int>>(n));

    auto dfs1 = [&](auto self, int i, int j, int depth, int val) -> void {
        if (depth == K) {
            r1[i][j].push_back(val);
            return;
        }
        if (i + 1 < n) {
            int nv = (val * 10 + a[i + 1][j]) % m;
            self(self, i + 1, j, depth + 1, nv);
        }
        if (j + 1 < n) {
            int nv = (val * 10 + a[i][j + 1]) % m;
            self(self, i, j + 1, depth + 1, nv);
        }
    };
    dfs1(dfs1, 0, 0, 0, a[0][0] % m);

    auto dfs2 = [&](auto self, int i, int j, int depth, int val, int si, int sj) -> void {
        if (depth == K) {
            r2[si][sj].push_back(val);
            return;
        }
        if (i + 1 < n) {
            int nv = (val * 10 + a[i + 1][j]) % m;
            self(self, i + 1, j, depth + 1, nv, si, sj);
        }
        if (j + 1 < n) {
            int nv = (val * 10 + a[i][j + 1]) % m;
            self(self, i, j + 1, depth + 1, nv, si, sj);
        }
    };

    for (int i = 0; i < n; i++) {
        int j = K - i;
        if (j < 0 || j >= n) continue;
        dfs2(dfs2, i, j, 0, 0, i, j);
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int j = K - i;
        if (j < 0 || j >= n) continue;

        auto &v1 = r1[i][j];
        auto &v2 = r2[i][j];
        if (v1.empty() || v2.empty()) continue;

        sort(v2.begin(), v2.end());
        int max2 = v2.back();

        for (int a : v1) {
            int t = (a * P10) % m;

            int cand = t + max2;
            if (cand >= m) cand -= m;
            ans = max(ans, cand);

            int need = m - 1 - t;
            auto it = upper_bound(v2.begin(), v2.end(), need);
            if (it != v2.begin()) {
                --it;
                int r2v = *it;
                int cand2 = t + r2v;
                ans = max(ans, cand2);
            }
        }
    }

    cout << ans;
}
