#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> A(N);
    for (auto &e : A) cin >> e;
    int l = 0, r = N / 2 + 1;
    while (l + 1 < r) {
        int m = (l + r) / 2;
        bool is_ok = true;
        for (int i = 0; i < m; i++) {
            if (A[i] * 2 > A[N - m + i]) {
                is_ok = false;
                break;
            }
        }
        if (is_ok) {
            l = m;
        } else {
            r = m;
        }
    }
    bool chk = true;
    for (int i = 0; i < r; i++) {
        if (A[i] * 2 > A[N - r + i]) {
            chk = false;
            break;
        }
    }
    cout << l;
}
