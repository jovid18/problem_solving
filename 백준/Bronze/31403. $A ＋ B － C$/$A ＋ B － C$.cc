#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int a, b, c;
    cin >> a >> b >> c;
    cout << a + b - c << '\n';
    cout << stoi(to_string(a) + to_string(b)) - c << '\n';
}