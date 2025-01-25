#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int A1, A2, A3, A4, A5;
    cin >> A1 >> A2 >> A3 >> A4 >> A5;
    int cnt = 0;
    if (A1 == 2 && A2 == 1 && A3 == 3 && A4 == 4 && A5 == 5) {
        cout << "Yes";
        return 0;
    }
    if (A1 == 1 && A2 == 3 && A3 == 2 && A4 == 4 && A5 == 5) {
        cout << "Yes";
        return 0;
    }
    if (A1 == 1 && A2 == 2 && A3 == 4 && A4 == 3 && A5 == 5) {
        cout << "Yes";
        return 0;
    }
    if (A1 == 1 && A2 == 2 && A3 == 3 && A4 == 5 && A5 == 4) {
        cout << "Yes";
        return 0;
    }
    cout << "No";
}