#include <bits/stdc++.h>
using namespace std;
#define int long long
int N;
int f(int n) { return n % 2 ? (n + 1) * (n + 1) / 4 : n * (n + 2) / 4; }
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    while (N--) {
        int x, y;
        cin >> x >> y;
        int d = y - x;
        int answer = 1;
        int s = 1;
        int e = 1e5;
        while (s + 1 < e) {
            int m = (s + e) / 2;
            if (f(m) < d) {
                s = m + 1;
            } else
                e = m;
        }
        if (d <= f(s))
            cout << s << endl;
        else
            cout << s + 1 << endl;
    }
}