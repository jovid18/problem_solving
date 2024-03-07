#include <string>
#include <vector>

using namespace std;
vector<vector<int>> C;
int N;
int dx[5] = {0, 1, 0, -1, 0};
int dy[5] = {0, 0, 1, 0, -1};
int answer = 0x3f3f3f3f;
bool isIn(int x, int y) { return x >= 0 && x < N && y >= 0 && y < N; }
void turn(int x, int y, vector<vector<int>> &clockHands) {
    for (int i = 0; i < 5; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (isIn(nx, ny)) {
            clockHands[nx][ny] = (clockHands[nx][ny] + 1) % 4;
        }
    }
}
void solve(int x) {
    int cnt = 0;
    auto Ccopy = C;
    int i = 0;
    while (x != 0) {
        int y = x % 4;
        x /= 4;
        while (y--) {
            turn(0, i, Ccopy);
            cnt++;
        }
        ++i;
    }
    for (int i = 1; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            while (Ccopy[i - 1][j] != 0) {
                turn(i, j, Ccopy);
                cnt++;
            }
        }
    }
    for (int i = 0; i < N; ++i) {
        if (Ccopy[N - 1][i] != 0) {
            return;
        }
    }
    if (answer > cnt) {
        answer = cnt;
    }
}
int solution(vector<vector<int>> clockHands) {
    C = clockHands;
    N = clockHands.size();
    for (int i = 0; i < (1 << 2 * N); ++i) {
        solve(i);
    }

    return answer;
}