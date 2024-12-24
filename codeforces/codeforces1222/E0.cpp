#include <bits/stdc++.h>
using namespace std;
#define int long long
int t;
#define pii pair<int, int>
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a, b;
        a.resize(n);
        b.resize(n);
        for (auto &i : a) cin >> i;
        for (auto &i : b) cin >> i;
        vector<pii> v;
        // type : 0 -> 넘으면 negative +1
        for (auto e : a) v.push_back({e, 0});
        // type : 1 -> 넘으면 negative -1, buying -1
        for (auto e : b) v.push_back({e, 1});
        sort(v.begin(), v.end());
        int ans = 0;
        int cnt = n;
        int ngt = 0;
        for (int i = 0; i < 2 * n;) {
            auto [price, type] = v[i];
            // 현재 가격까지는 safe -> ans 갱신
            // cout << cnt << ' ' << ngt << ' ' << price << ' ' << type << '\n';
            if (ngt <= k) ans = max(ans, price * cnt);
            // 이후에는 인상 이벤트 발생 -> 그래서 while문 이후 ans를 구할 필요가 없음
            while (i < 2 * n && v[i].first == price) {
                auto [ithPrice, ithType] = v[i];
                if (ithType == 0) {
                    ngt++;
                } else {
                    ngt--;
                    cnt--;
                }
                i++;
            }
        }
        cout << ans << '\n';
    }
}