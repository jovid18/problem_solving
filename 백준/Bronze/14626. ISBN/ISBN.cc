#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    string s;
    cin >> s;
    for (int x = 0; x < 10; ++x) {
        int sum = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '*') {
                if (i % 2 == 0) {
                    sum += x;
                } else {
                    sum += 3 * x;
                }
                continue;
            }
            if (i % 2 == 0) {
                sum += s[i] - '0';
            } else {
                sum += 3 * (s[i] - '0');
            }
        }
        if (sum % 10 == 0) {
            cout << x;
            return 0;
        }
    }
}