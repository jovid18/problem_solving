#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>

// https://atcoder.jp/contests/abc396/tasks/abc396_b
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int q;
    cin >> q;
    stack<int> s;
    while (q--) {
        int x, y;
        cin >> x;
        if (x == 1) {
            cin >> y;
            s.push(y);
        } else {
            if (!s.size()) {
                cout << 0 << '\n';
                continue;
            }
            cout << s.top() << '\n';
            s.pop();
        }
    }
}