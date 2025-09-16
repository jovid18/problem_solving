#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>

const int MOD = 1e9 + 7;

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int N, M, K;
    cin >> N >> M >> K;
    vector<vector<char>> G(M, vector<char>(N, 'x'));
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> G[i][j];
        }
    }
    vector<vector<int>> A(M, vector<int>(N, 0));
    vector<vector<int>> B(M, vector<int>(N, 0));
    A[0][0] = 1;
    B[M - 1][N - 1] = 1;

    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            if (G[i][j] == '1') {
                continue;
            }
            if (i >= 1) {
                A[i][j] += A[i - 1][j];
                A[i][j] %= MOD;
            }
            if (j >= 1) {
                A[i][j] += A[i][j - 1];
                A[i][j] %= MOD;
            }
        }
    }

    for (int i = M - 1; i >= 0; --i) {
        for (int j = N - 1; j >= 0; --j) {
            if (G[i][j] == '1') {
                continue;
            }
            if (i < M - 1) {
                B[i][j] += B[i + 1][j];
                B[i][j] %= MOD;
            }
            if (j < N - 1) {
                B[i][j] += B[i][j + 1];
                B[i][j] %= MOD;
            }
        }
    }

    int ans = A[M - 1][N - 1];
    for (int i = 0; i < K; ++i) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        bool isNext = (x1 == x2 && abs(y1 - y2) == 1) || (y1 == y2 && abs(x1 - x2) == 1);
        if (!isNext) {
            ans += A[y1][x1] * B[y2][x2] % MOD;
            ans %= MOD;
            ans += A[y2][x2] * B[y1][x1] % MOD;
            ans %= MOD;
            continue;
        }
        if (x1 == x2) {
            if (y1 > y2) swap(y1, y2);
            ans += A[y2][x2] * B[y1][x1] % MOD;
            ans %= MOD;
        } else {
            if (x1 > x2) swap(x1, x2);
            ans += A[y2][x2] * B[y1][x1] % MOD;
            ans %= MOD;
        }
    }
    cout << ans;
}