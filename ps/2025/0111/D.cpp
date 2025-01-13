#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int N;
    cin >> N;
    vector<int> A(N);
    for (auto &e : A) cin >> e;
    vector<int> C(N), D(N + 1);
    for (int i = 0; i < N; i++) {
        if (i) {
            C[i] = C[i - 1] + D[i];
        }
        A[i] += C[i];
        int diff = min(A[i], N - i - 1);
        A[i] -= diff;
        D[i + 1]++;
        D[i + 1 + diff]--;
    }
    for (int i = 0; i < N; i++) {
        cout << A[i] << " ";
    }
}