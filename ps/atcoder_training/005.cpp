#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    // A피자, B피자, AB피자 가격, A피자 개수, B피자 개수
    int a, b, ab, x, y;
    cin >> a >> b >> ab >> x >> y;
    int acnt = 0, bcnt = 0, abcnt = 0;
    int ans = 1LL << 60;
    for (int abcnt = 0; abcnt <= 2 * max(x, y); abcnt += 2) {
        acnt = max(0LL, x - abcnt / 2);
        bcnt = max(0LL, y - abcnt / 2);
        ans = min(ans, acnt * a + bcnt * b + abcnt * ab);
    }
    cout << ans;
}