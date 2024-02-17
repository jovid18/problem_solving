#include <bits/stdc++.h>
using namespace std;
#define int long long
int t;
int n;
vector<int> a;
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> t;
    while (t--) {
        cin >> n;
        a.resize(n);
        int sum = 0;
        for (auto &e : a) {
            cin >> e;
            sum += e;
        }
        if (sum % n != 0) {
            cout << "NO\n";
            continue;
        }
        int avg = sum / n;
        bool ispossible = true;
        for (int i = 0; i < n - 1; ++i) {
            if (a[i] < avg) {
                ispossible = false;
            } else {
                a[i + 1] += a[i] - avg;
                a[i] = avg;
            }
        }
        if (ispossible)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}