#include <bits/stdc++.h>
using namespace std;
#define int long long
int N, C;
vector<int> v;
vector<int> merge(vector<int> v) {
    vector<int> ret;
    if (v.empty()) {
        return v;
    } else if (v.size() == 1) {
        ret.push_back(0);
        ret.push_back(v[0]);
        return ret;
    }
    int m = v.size() / 2;
    vector<int> left(v.begin(), v.begin() + m);
    vector<int> right(v.begin() + m, v.end());
    vector<int> leftMerge = merge(left);
    vector<int> rightMerge = merge(right);
    for (int i = 0; i < leftMerge.size(); i++) {
        for (int j = 0; j < rightMerge.size(); j++) {
            ret.push_back(leftMerge[i] + rightMerge[j]);
        }
    }
    return ret;
}
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> C;
    v.resize(N);
    for (auto &e : v) cin >> e;
    auto left = vector<int>(v.begin(), v.begin() + N / 2);
    auto right = vector<int>(v.begin() + N / 2, v.end());
    auto leftMerge = merge(left);
    auto rightMerge = merge(right);
    sort(leftMerge.begin(), leftMerge.end());
    sort(rightMerge.begin(), rightMerge.end());
    if (leftMerge.empty()) {
        leftMerge.push_back(0);
    }
    if (rightMerge.empty()) {
        rightMerge.push_back(0);
    }
    int ans = 0;
    for (auto e : leftMerge) {
        ans += upper_bound(rightMerge.begin(), rightMerge.end(), C - e) - rightMerge.begin();
    }
    cout << ans;
}