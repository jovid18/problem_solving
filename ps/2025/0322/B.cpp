#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>

// https://atcoder.jp/contests/abc398/tasks/abc398_b
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    vector<int> v(7);
    for (auto &i : v) cin >> i;
    sort(v.begin(), v.end());
    unordered_map<int, int> mp;
    for (int i = 0; i < 7; ++i) {
        if (mp.find(v[i]) == mp.end()) {
            mp[v[i]] = 1;
        } else {
            mp[v[i]]++;
        }
    }
    int cnt3 = 0;
    int cnt2 = 0;
    for (auto [_, cnt] : mp) {
        if (cnt >= 2) cnt2++;
        if (cnt >= 3) cnt3++;
    }
    (cnt2 >= 2 && cnt3 >= 1) ? cout << "Yes" : cout << "No";
}