#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>

// https://atcoder.jp/contests/abc396/tasks/abc396_a
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &i : a) cin >> i;
    int cnt = 0;
    int now = -1;
    for (int i = 0; i < n; i++) {
        if (a[i] == now) {
            cnt++;
            if (cnt == 3) {
                cout << "Yes";
                return 0;
            }
        } else {
            now = a[i];
            cnt = 1;
        }
    }
    cout << "No";
}