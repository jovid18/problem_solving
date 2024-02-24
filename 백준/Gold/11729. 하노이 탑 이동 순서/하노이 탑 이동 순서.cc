#include <bits/stdc++.h>
using namespace std;
#define int long long
int x;
void solve(int x, int start, int goal) {
    if (x == 0)
        return;
    solve(x - 1, start, 6-start - goal);
    cout << start << " " << goal << "\n";
    solve(x - 1, 6 - start - goal, goal);
}
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> x;
    cout << (1 << x) - 1 << "\n";
    solve(x, 1, 3);
}