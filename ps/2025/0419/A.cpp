#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    string s;
    cin >> s;
    string t;
    for (char c : s) {
        if (isupper(c)) {
            t += c;
        }
    }
    cout << t;
}