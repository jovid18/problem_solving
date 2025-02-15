#include <bits/stdc++.h>
using namespace std;
#define int long long
int N, D;
vector<int> v, A, B;
vector<int> dfs(int l, int r, vector<int> &v) {
    if (l > r) {
        return {0};
    }
    auto res1 = dfs(l + 1, r, v);
    auto res2 = res1;
    auto res3 = res1;
    int N = res1.size();
    for (auto &e : res2) e += v[l];
    for (auto &e : res3) e -= v[l];
    vector<int> ret(N * 3);
    int idx = 0, idx1 = 0, idx2 = 0, idx3 = 0;
    while (idx1 != N || idx2 != N || idx3 != N) {
        if (idx1 != N && (idx2 == N || res1[idx1] <= res2[idx2]) && (idx3 == N || res1[idx1] <= res3[idx3])) {
            ret[idx++] = res1[idx1++];
        } else if (idx2 != N && (idx1 == N || res2[idx2] <= res1[idx1]) && (idx3 == N || res2[idx2] <= res3[idx3])) {
            ret[idx++] = res2[idx2++];
        } else {
            ret[idx++] = res3[idx3++];
        }
    }
    return ret;
}
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    v.resize(N);
    for (auto &e : v) cin >> e;
    cin >> D;
    A = dfs(0, N / 2 - 1, v);
    B = dfs(N / 2, N - 1, v);
    int ans = 0;
    int l = 0, r = 0;
    for (auto e : A) {
        while (l < B.size() && B[l] < e - D) {
            l++;
        }
        while (r < B.size() && B[r] <= e + D) {
            r++;
        }
        ans += r - l;
    }
    cout << ans;
}