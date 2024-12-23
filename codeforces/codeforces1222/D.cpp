#include <bits/stdc++.h>
using namespace std;
#define int long long
int t;
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> t;
    while (t--) {
        int n, x, y;
        cin >> n >> x >> y;
        vector<int> a;
        a.resize(n);
        for (auto &i : a) cin >> i;
        int ans = 0;
        sort(a.begin(), a.end());
        int sum = 0;
        for (auto i : a) sum += i;
        int allowMin = sum - y;
        int allowMax = sum - x;
        int minIdx = 0;
        int maxIdx = n - 1;
        for (int i = 0; i < n; ++i) {
            minIdx = i + 1;
            while (a[minIdx] < allowMin - a[i]) {
                minIdx++;
            }
            while (a[maxIdx] > allowMax - a[i]) {
                maxIdx--;
            }
            if (maxIdx <= i) break;
            if (minIdx > maxIdx) continue;
            ans += maxIdx - minIdx + 1;
        }
        cout << ans << '\n';
    }
}