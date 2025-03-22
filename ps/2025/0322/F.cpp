#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>

vector<int> getPi(const string &p) {
    int j = 0, plen = p.length();
    vector<int> pi;
    pi.resize(plen);
    for (int i = 1; i < plen; i++) {
        while (j > 0 && p[i] != p[j]) j = pi[j - 1];
        if (p[i] == p[j]) pi[i] = ++j;
    }
    return pi;
}

string solve(const string &S) {
    string revS = S;
    reverse(revS.begin(), revS.end());
    string T = revS + '|' + S;
    vector<int> pi = getPi(T);
    int L = pi.back();
    string leftover = revS.substr(L);
    return S + leftover;
}

// https://atcoder.jp/contests/abc398/tasks/abc398_f
int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    string s;
    cin >> s;
    string ans = solve(s);
    cout << ans << "\n";

    return 0;
}
