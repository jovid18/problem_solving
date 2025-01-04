#include <bits/stdc++.h>
using namespace std;
#define int long long

int t;
int l, r;

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> t;

    while (t--) {
        cin >> l >> r;
        bool isMax = false;
        int a = 0;
        for (int i = 31; i >= 0; --i) {
            int l_bit = (l >> i) & 1;
            int r_bit = (r >> i) & 1;
            if (r_bit) a |= (1 << i);
            if (r_bit != l_bit) {
                break;
            }
        }
        int b = a - 1;
        int c = a + 1 > r ? b - 1 : a + 1;
        cout << a << " " << b << " " << c << endl;
    }
    return 0;
}
