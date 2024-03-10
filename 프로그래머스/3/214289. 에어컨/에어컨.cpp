#include <iostream>
#include <string>
#include <vector>
using namespace std;
const int INF = 0x3f3f3f3f;
int DP[1001][52];
int solution(int temperature, int t1, int t2, int a, int b,
             vector<int> onboard) {
    for (int i = 0; i < 1001; i++) {
        for (int j = 0; j < 51; j++) {
            DP[i][j] = INF;
        }
    }
    int target = max(temperature - t2, t1 - temperature);
    DP[0][0] = 0;
    for (int i = 0; i < onboard.size(); i++) {
        if (onboard[i] == 1) {
            for (int j = 0; j < 50; j++) {
                if (j != target && j != target + 1) {
                    DP[i][j] = INF;
                }
            }
        }
        for (int j = 0; j < 51; ++j) {
            if (DP[i][j] == INF)
                continue;
            if (j == 0) {
                DP[i + 1][j + 1] = min(DP[i + 1][j + 1], DP[i][j] + a);
                DP[i + 1][j] = min(DP[i + 1][j], DP[i][j] + 0);
            } else {
                DP[i + 1][j + 1] = min(DP[i + 1][j + 1], DP[i][j] + a);
                DP[i + 1][j] = min(DP[i + 1][j], DP[i][j] + b);
                DP[i + 1][j - 1] = min(DP[i + 1][j - 1], DP[i][j] + 0);
            }
        }
    }
    if (onboard.back() == 1) {
        return min(DP[onboard.size() - 1][target],
                   DP[onboard.size() - 1][target + 1]);
    }
    int answer = INF;
    for (int i = 0; i < 51; i++) {
        answer = min(answer, DP[onboard.size() - 1][i]);
    }
    return answer;
}