#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
using pii = pair<int, int>;
int T, M, N, K;
bool visited[51][51];
int x[4] = {1, -1, 0, 0};
int y[4] = {0, 0, 1, -1};
bool in(int x, int y) {
    if (x < 0 || y < 0 || x >= N || y >= M)
        return false;
    return true;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> T;
    while (T--) {
        cin >> M >> N >> K;
        while (K--) {
            int X, Y;
            cin >> X >> Y;
            visited[Y][X] = 1;
        }
        int ans = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                if (!visited[i][j])
                    continue;
                visited[i][j] = 0;
                ans++;
                queue<pii> Q;
                Q.push({i, j});
                while (!Q.empty()) {
                    int x0 = Q.front().first;
                    int y0 = Q.front().second;
                    Q.pop();
                    for (int k = 0; k < 4; ++k) {
                        int xk = x0 + x[k];
                        int yk = y0 + y[k];
                        if (in(xk, yk) && visited[xk][yk]) {
                            visited[xk][yk] = 0;
                            Q.push({xk, yk});
                        }
                    }
                }
            }
        }
        cout << ans << '\n';
    }
}
