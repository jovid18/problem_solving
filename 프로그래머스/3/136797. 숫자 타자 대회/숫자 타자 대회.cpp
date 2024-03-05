#include <cstring>
#include <map>
#include <string>
#include <vector>
using namespace std;
int DP[100001][10][10];
vector<vector<pair<int, int>>> adj;
pair<int, int> m(int x) {
    if (x == 0)
        return {3, 1};
    return {(x - 1) / 3, (x - 1) % 3};
}
int minpath(int a, int b) {
    if (a == b)
        return 1;
    int dx = abs(m(a).first - m(b).first);
    int dy = abs(m(a).second - m(b).second);
    int diagonal = min(dx, dy);
    dx -= diagonal;
    dy -= diagonal;
    return 3 * diagonal + 2 * dx + 2 * dy;
}
int solution(string numbers) {
    int N = numbers.size();
    memset(DP, 0x3f, sizeof(DP));
    DP[0][4][6] = 0;
    DP[0][6][4] = 0;
    for (int i = 0; i < N; ++i) {
        int num = numbers[i] - '0';
        for (int j = 0; j < 10; ++j) {
            for (int k = 0; k < 10; ++k) {
                if (DP[i][j][k] == 0x3f3f3f3f)
                    continue;
                if (num != k)
                    DP[i + 1][num][k] =
                        min(DP[i + 1][num][k], DP[i][j][k] + minpath(j, num));
                if (num != j)
                    DP[i + 1][j][num] =
                        min(DP[i + 1][j][num], DP[i][j][k] + minpath(k, num));
            }
        }
    }
    int answer = 0x3f3f3f3f;
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (i == j)
                continue;
            answer = min(answer, DP[N][i][j]);
        }
    }
    return answer;
}