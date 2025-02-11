#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<long long> x(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> x[i];
        }

        cout << "? 1 2\n" << flush;
        long long ans1;
        cin >> ans1;

        cout << "? 2 1\n" << flush;
        long long ans2;
        cin >> ans2;

        if (ans1 == 0 || ans2 == 0) {
            cout << "! A\n" << flush;
            continue;
        }

        if (ans1 != ans2) {
            cout << "! A\n" << flush;
            continue;
        }
        cout << "! B\n" << flush; 
    }
    return 0;
}
