#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
using pii = pair<int, int>;
int N;
char M[25][25];
vector<int> ans;
int x[4] = {1, -1, 0, 0};
int y[4] = {0, 0, 1, -1};
bool in(int x, int y) {
    if (x < 0 || y < 0 || x >= N || y >= N)
        return false;
    return true;
}
queue<pii> q;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> M[i][j];
        }
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (M[i][j] == '0')
                continue;
            q.push({i, j});
            M[i][j] = '0';
            int num = 0;
            while (!q.empty()) {
                num++;
                int x0 = q.front().first;
                int y0 = q.front().second;
                q.pop();
                for (int i = 0; i < 4; ++i) {
                    int xi = x0 + x[i];
                    int yi = y0 + y[i];
                    if (in(xi, yi) && M[xi][yi] == '1') {
                        M[xi][yi] = '0';
                        q.push({xi, yi});
                    }
                }
            }
            ans.push_back(num);
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for (auto e : ans) {
        cout << e << '\n';
    }
}
