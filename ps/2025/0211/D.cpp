#include <bits/stdc++.h>
using namespace std;
#define int long long

// https://codeforces.com/contest/2067/problem/D
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<bool> chk(n + 1);
    int ans1, ans2;
    for (int &x : a) {
        cin >> x;
        chk[x] = true;
    }
    bool is_perm = true;
    for (int i = 1; i <= n; i++) {
        if (!chk[i]) {
            is_perm = false;
            break;
        }
    }
    bool is_A = true;
    if (is_perm) {
        // permutation
        // 먼저, a[i] = 1, a[j] = n인 i, j를 찾는다.
        int i = 0, j = 0;
        for (; i < n; ++i) {
            if (a[i] == 1) {
                break;
            }
        }
        for (; j < n; ++j) {
            if (a[j] == n) {
                break;
            }
        }
        cout << "? " << i + 1 << " " << j + 1 << endl;
        cin >> ans1;
        cout << "? " << j + 1 << " " << i + 1 << endl;
        cin >> ans2;
        // B인 경우 맨해튼 거리이므로 ans1 == ans2이며 A인 경우 방향 그래프이기때문에 ans >= n - 1이 불가능하다.
        if (ans1 == ans2 && ans1 >= n - 1) {
            is_A = false;
        }
    } else {
        // not permutation
        // chk[i] == false인 i를 찾는다.
        int i = 0;
        for (; i < n; ++i) {
            if (!chk[i + 1]) {
                break;
            }
        }
        int j = i == 0 ? 1 : i - 1;
        cout << "? " << i + 1 << " " << j + 1 << endl;
        cin >> ans1;
        cout << "? " << j + 1 << " " << i + 1 << endl;
        cin >> ans2;
        // A인 경우 i와 연결된 노드가 없으므로 ans1 == 0이어야 한다. 그러나 B는 서로 다른 점들간의 거리이므로 ans1 != 0이어야 한다.
        if (ans1 != 0) {
            is_A = false;
        }
    }

    if (is_A) {
        cout << "! A" << endl;
    } else {
        cout << "! B" << endl;
    }
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
