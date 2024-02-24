#include <bits/stdc++.h>
using namespace std;
#define int long long
int N, C;
vector<int> v;

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> C;
    v.resize(N);
    for (auto &e : v) {
        cin >> e;
    }
    sort(v.begin(), v.end());

    int s = 0, f = v.back() - v.front();
    while (s <= f) {
        int m = (s + f) / 2;
        int cnt = 1, last_pos = v[0];
        for (int i = 1; i < N; ++i) {
            if (v[i] - last_pos >= m) {
                last_pos = v[i];
                cnt++;
            }
        }
        if (cnt >= C) {
            s = m + 1;
        } else {
            f = m - 1;
        }
    }
    cout << f;
    return 0;
}
