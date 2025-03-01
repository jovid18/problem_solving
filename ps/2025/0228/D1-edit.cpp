#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    vector<int> pref(n + 1);
    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i - 1] + a[i];
    }
    // n이 짝수인 경우 -> 추가 처리로 n을 홀수로 만들어줌
    // a(2k+1) = a1 ^ a2 ^ ... ^ a(k)=pref[k];
    if (n % 2 == 0) {
        n++;
        int cur = pref[n / 2] & 1;
        a.push_back(cur);
        pref.push_back(pref.back() + cur);
    }
    // 2n까지 작업
    for (int i = n + 1; i <= n * 2; i++) {
        int cur = pref[i / 2] & 1;
        a.push_back(cur);
        pref.push_back(pref.back() + cur);
    }
    int p = pref[n] & 1;
    auto get = [&](int x) {
        int ret = 0;
        // case1) x <= n*2 -> a[x]
        // case2) x가 짝수 -> p + a(x/2)
        // case3) x가 홀수 -> p
        while (true) {
            // case1
            if (x <= n * 2) {
                ret ^= a[x];
                break;
            }
            ret ^= p;
            // case2
            // 모든 짝이 매칭 되는 경우 (a(n+1)<-> a(n+2), a(n+3)<->a(n+4), ...)
            if ((x / 2 - n) % 2 == 0) {
                break;
            }
            // case3
            x /= 2;
        }
        return ret;
    };
    cout << get(l) << '\n';
}

// https://codeforces.com/contest/2071/problem/D1
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}