#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, M;
    cin >> N >> M;
    vector<int> cnt(N, 0);

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        int key = (a + b) % N;
        cnt[key]++;
    }

    int total = M * (M - 1) / 2;
    for (int r = 0; r < N; r++) {
        if (cnt[r] >= 2) {
            total -= cnt[r] * (cnt[r] - 1) / 2;
        }
    }

    cout << total << "\n";
    return 0;
}
