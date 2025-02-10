#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>

// https://atcoder.jp/contests/sumitrust2019/tasks/sumitb2019_d
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    string s;
    cin >> n >> s;
    vector<string> v;
    for (int i = 0; i < 1000; i++) {
        string t = to_string(i);
        while (t.size() < 3) t = '0' + t;
        v.push_back(t);
    }
    int cnt = 0;
    for (auto e : v) {
        int idx = 0;
        for (auto c : s) {
            if (c == e[idx]) idx++;
            if (idx == 3) break;
        }
        if (idx == 3) cnt++;
    }
    cout << cnt;
}