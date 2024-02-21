#include <iostream>
using namespace std;
#define int long long
int T;
int _x1, _y1, r1, _x2, _y2, r2;
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> T;
    while (T--) {
        cin >> _x1 >> _y1 >> r1 >> _x2 >> _y2 >> r2;
        int d = (_x1 - _x2) * (_x1 - _x2) + (_y1 - _y2) * (_y1 - _y2);
        if (_x1 == _x2 && _y1 == _y2 && r1 == r2) {
            cout << -1 << '\n';
        } else if ((r2 - r1) * (r2 - r1) < d && d < (r1 + r2) * (r1 + r2)) {
            cout << 2 << '\n';
        } else if ((r1 + r2) * (r1 + r2) == d || (r1 - r2) * (r1 - r2) == d) {
            cout << 1 << '\n';
        } else {
            cout << 0 << '\n';
        }
    }
}