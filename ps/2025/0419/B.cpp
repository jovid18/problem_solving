#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int q;
    cin >> q;
    queue<int> q1;
    while (q--) {
        int x;
        cin >> x;
        if (x == 1) {
            int y;
            cin >> y;
            q1.push(y);
        } else {
            cout << q1.front() << '\n';
            q1.pop();
        }
    }
}