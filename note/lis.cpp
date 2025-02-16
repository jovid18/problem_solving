#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>

vector<int> lis(const vector<int> &v) {
    if (v.empty()) return {};
    vector<int> prev(v.size());
    // first: value, second: index
    vector<pii> res;
    for (int i = 0; i < v.size(); i++) {
        // change  0 -> i for Xi<=Xj
        auto it = lower_bound(res.begin(), res.end(), pii(v[i], 0));
        if (it == res.end()) {
            res.emplace_back();
            it = res.end() - 1;
        }
        *it = {v[i], i};
        prev[i] = it == res.begin() ? 0 : (it - 1)->second;
    }
    int L = res.size();
    int cur = res.back().second;
    vector<int> ans(L);
    while (L--) {
        ans[L] = v[cur];
        cur = prev[cur];
    }
    return ans;
}
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    return 0;
}