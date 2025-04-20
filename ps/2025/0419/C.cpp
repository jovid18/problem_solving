#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(m);
    vector<int> ing(m);
    vector<vector<int>> uses(n + 1);
    for (int i = 0; i < m; i++) {
        int k;
        cin >> k;
        a[i].resize(k);
        for (auto &e : a[i]) {
            cin >> e;
            uses[e].push_back(i);
        }
        sort(a[i].begin(), a[i].end());
        ing[i] = a[i].size();
    }
    vector<int> b(n);
    for (auto &e : b) {
        cin >> e;
    }
    int edible = 0;
    for (int i = 0; i < n; ++i) {
        int ok = b[i];
        int cnt = 0;
        for (auto &e : uses[ok]) {
            ing[e]--;
            if (ing[e] == 0) {
                cnt++;
            }
        }
        edible += cnt;
        cout << edible << '\n';
    }
}