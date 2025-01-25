#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
const int INF = 1LL << 60;
struct Food {
    int vitamin, units, calories;
};

// NOTE: DP[i][j] = calorie가 j일 때 i번째 비타민의 최대 units
int DP[3][5001];

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int N, X;
    cin >> N >> X;
    vector<Food> foods(N);
    for (auto &e : foods) {
        cin >> e.vitamin >> e.units >> e.calories;
    }

    for (auto e : foods) {
        if (e.vitamin == 1) {
            for (int i = X; i >= e.calories; i--) {
                DP[0][i] = max(DP[0][i], DP[0][i - e.calories] + e.units);
            }
        } else if (e.vitamin == 2) {
            for (int i = X; i >= e.calories; i--) {
                DP[1][i] = max(DP[1][i], DP[1][i - e.calories] + e.units);
            }
        } else {
            for (int i = X; i >= e.calories; i--) {
                DP[2][i] = max(DP[2][i], DP[2][i - e.calories] + e.units);
            }
        }
    }
    int s1 = 0, s2 = 0, s3 = 0;
    int idx1 = 0, idx2 = 0, idx3 = 0;
    for (int i = 1; i <= X; i++) {
        if (s1 <= s2 && s1 <= s3) {
            s1 = DP[0][++idx1];
        } else if (s2 <= s1 && s2 <= s3) {
            s2 = DP[1][++idx2];
        } else {
            s3 = DP[2][++idx3];
        }
    }
    cout << min({s1, s2, s3});
}