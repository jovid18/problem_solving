#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int N;
    cin >> N;
    vector<int> A(N);
    if (N == 2) {
        cout << "Yes";
        return 0;
    }
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 1; i < N - 1; ++i) {
        if (A[i] * A[i] != A[i - 1] * A[i + 1]) {
            cout << "No";
            return 0;
        }
    }
    cout << "Yes";
}