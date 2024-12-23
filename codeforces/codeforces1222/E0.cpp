#include <bits/stdc++.h>
using namespace std;
#define int long long
int t;
const int MAX = 2LL * 1000000000LL;
#define pii pair<int, int>
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<pii> v;
        v.resize(n);
        for (auto &i : v) cin >> i.first;
        for (auto &i : v) cin >> i.second;
        int ans = 0;
        for (auto [x1, x2] : v) {
            int buying = 0;
            int negativeReview = 0;
            for (auto [a, b] : v) {
                if (x1 <= a) {
                    buying++;
                } else if (x1 <= b) {
                    buying++;
                    negativeReview++;
                }
            }
            if (negativeReview > k) continue;
            ans = max(ans, buying * x1);
        }
        for (auto [x1, x2] : v) {
            int buying = 0;
            int negativeReview = 0;
            for (auto [a, b] : v) {
                if (x2 <= a) {
                    buying++;
                } else if (x2 <= b) {
                    buying++;
                    negativeReview++;
                }
            }
            if (negativeReview > k) continue;
            ans = max(ans, buying * x2);
        }
        cout << ans << endl;
    }
}