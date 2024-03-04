#include <cstring>
#include <string>
#include <vector>
using namespace std;
int DP[100001];
int solution(int N, int number) {
    memset(DP, 0x3f, sizeof(DP));
    DP[N] = 1;
    DP[10 * N + N] = 2;
    DP[100 * N + 10 * N + N] = 3;
    DP[1000 * N + 100 * N + 10 * N + N] = 4;
    DP[10000 * N + 1000 * N + 100 * N + 10 * N + N] = 5;
    for (int cnt = 2; cnt <= 4; ++cnt) {
        vector<pair<int, int>> v;
        for (int i = 1; i < 100001; ++i) {
            if (DP[i] != 1061109567) {
                v.push_back({i, DP[i]});
            }
        }
        for (auto e : v) {
            for (auto f : v) {
                if (0 < e.first + f.first && e.first + f.first < 100001)
                    DP[e.first + f.first] =
                        min(DP[e.first + f.first], e.second + f.second);
                if (0 < e.first - f.first && e.first - f.first < 100001)
                    DP[e.first - f.first] =
                        min(DP[e.first - f.first], e.second + f.second);
                if (0 < e.first * f.first && e.first * f.first < 100001)
                    DP[e.first * f.first] =
                        min(DP[e.first * f.first], e.second + f.second);
                if (0 < e.first / f.first && e.first / f.first < 100001)
                    DP[e.first / f.first] =
                        min(DP[e.first / f.first], e.second + f.second);
            }
        }
    }
    if (DP[number] > 8)
        DP[number] = -1;
    return DP[number];
}