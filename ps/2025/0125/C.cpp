#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int H, W;
    cin >> H >> W;
    vector<string> S(H);
    int min_x = 1e9, max_x = -1, min_y = 1e9, max_y = -1;
    for (int i = 0; i < H; i++) {
        cin >> S[i];
    }
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (S[i][j] == '#') {
                min_x = min(min_x, i);
                max_x = max(max_x, i);
                min_y = min(min_y, j);
                max_y = max(max_y, j);
            }
        }
    }
    int cnt = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (min_x <= i && i <= max_x && min_y <= j && j <= max_y) {
                if (S[i][j] == '.') {
                    cout << "No";
                    return 0;
                }
            }
        }
    }
    cout << "Yes";
}