#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>

const int INF = 1LL << 62;

int count(int x, int y, int z) {
    if (y <= 0) return 0;
    if (x >= y) return 1;
    if (x <= z) return INF;
    __int128 num = (__int128)y - z;
    __int128 den = (__int128)x - z;
    int m = (int)((num + den - 1) / den);  // ceil
    return m;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int atk, xl, yl, xh, yh;
    cin >> atk >> xl >> yl >> xh >> yh;
    if (xl == 0 && yl == 0) {
        cout << 0;
        return 0;
    }
    int ans = INF;
    for (int i = 0; i < 2; ++i) {
        // kill x
        int d1 = count(2 * atk, xl, xh);
        // d1일 뒤에는 무조건 죽음 즉, d1일에는 xl<= 0;
        // (d1-1)일의 x의 체력
        int x_last_life = xl - (d1 - 1) * (2 * atk) + (d1 - 1) * xh;
        int d2;
        if (x_last_life > atk) {
            // 2마리 독수리가 합심해야 하는 경우
            d2 = count(2 * atk, yl + d1 * yh, yh);
        } else {
            // 그날 밤 회복 전, 공격 직후 체력
            int y_post = yl + (d1 - 1) * yh - atk;
            if (y_post <= 0) {
                d2 = 0;  // 그날 즉시 사망 → 추가 일수 0
            } else {
                d2 = count(2 * atk, y_post + yh, yh);
            }
        }
        ans = min(ans, d1 + d2);
        swap(xl, yl);
        swap(xh, yh);
    }
    cout << ans;
}