#include <bits/stdc++.h>
using namespace std;
#define int long long

int get(int x, int y) { return x / y + (x % y != 0); }

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int N, T, P, O = 0;
    ;
    vector<int> v(6);
    cin >> N;
    for (auto &e : v) {
        cin >> e;
    }
    cin >> T >> P;
    for (int i = 0; i < 6; i++) {
        O += get(v[i], T);
    }

    cout << O << '\n';
    cout << (N / P) << " " << (N % P) << "\n";
}