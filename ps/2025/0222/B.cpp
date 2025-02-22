#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
bool cmp(string a, string b) { return a.size() < b.size(); }

// https://atcoder.jp/contests/abc394/tasks/abc394_b
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    sort(s.begin(), s.end(), cmp);
    for (int i = 0; i < n; i++) {
        cout << s[i];
    }
}