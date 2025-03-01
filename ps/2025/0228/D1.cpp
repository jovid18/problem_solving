#include <bits/stdc++.h>
using namespace std;

static const int MAXN = 200000;

// https://codeforces.com/contest/2071/problem/D1
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        long long n, L, R;
        cin >> n >> L >> R;
        vector<int> a(n + 1), pref(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        for (int i = 1; i <= n; i++) {
            pref[i] = pref[i - 1] ^ a[i];
        }

        if (L <= n) {
            cout << a[L] << "\n";
            continue;
        }

        unordered_map<int, int> memo;
        memo.reserve(64);

        int p_n = pref[n];
        function<int(long long)> getP = [&](long long x) -> int {
            if (x <= n) return pref[x];
            auto it = memo.find(x);
            if (it != memo.end()) return it->second;
            int halfVal = getP(x / 2);
            int ret = p_n ^ (((x % 2 == 0) ? halfVal : 0) ^ 0);
            memo[x] = ret;
            return ret;
        };

        int gN = 0;
        if (n % 2 == 0) {
            gN = getP(n / 2);
        }

        memo.clear();
        memo.reserve(64);

        function<int(long long)> getP_final = [&](long long x) -> int {
            if (x <= n) return pref[x];
            auto it = memo.find(x);
            if (it != memo.end()) return it->second;

            int halfVal = getP_final(x / 2);
            int ret = p_n ^ (((x % 2 == 0) ? halfVal : 0) ^ gN);
            memo[x] = ret;
            return ret;
        };

        long long x = L / 2;
        int ans = getP_final(x);
        cout << ans << "\n";
    }

    return 0;
}
