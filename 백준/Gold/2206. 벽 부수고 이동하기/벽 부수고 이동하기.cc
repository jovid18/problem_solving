#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;
int N, M;
int Map[1000][1000] = {0};
int visited[1000][1000][2] = {0};
int xctrl[4] = {1,-1,0,0};
int yctrl[4] = {0,0,1,-1};
bool in (int x, int y) {
    if (0 <= x && 0 <= y && x < N && y < M) {
        return true;
    } else {
        return false;
    }
}
struct point {
    int x;
    int y;
    int wall;
};
queue < point > process;
void BFS() {
    bool finish = true;
    while (!process.empty() && finish) {
        int size = process.size();
        for (int i = 0; i < size; ++i) {
            int x = process.front().x;
            int y = process.front().y;
            int wall = process.front().wall;
            for (int j = 0; j < 4; ++j) {
                int nx = x + xctrl[j];
                int ny = y + yctrl[j];
                if (in(nx, ny)) {
                    if (Map[nx][ny] == 0 && visited[nx][ny][wall] == 0) {
                        visited[nx][ny][wall] = visited[x][y][wall] + 1;
                        process.push({nx,ny,wall});
                    }
                    if (Map[nx][ny] == 1 && visited[nx][ny][wall] == 0 && wall == 0) {
                        visited[nx][ny][wall + 1] = visited[x][y][wall] + 1;
                        process.push({nx,ny,wall + 1});
                    }
                    if (nx == N - 1 && ny == M - 1) {
                        finish = false;
                    }
                }
            }
            process.pop();
        }
    }
    bool a = visited[N - 1][M - 1][0] == 0;
    bool b = visited[N - 1][M - 1][1] == 0;
    if (a && b) {
        cout << -1;
    } else {
        cout << max(visited[N - 1][M - 1][0], visited[N - 1][M - 1][1]);
    }
}
int main() {
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        string a;
        cin >> a;
        for (int j = 0; j < M; ++j) {
            Map[i][j] = a[j] - '0';
        }
    }
    visited[0][0][0] = 1;
    process.push({
        0,
        0,
        0
    });
    BFS();
}