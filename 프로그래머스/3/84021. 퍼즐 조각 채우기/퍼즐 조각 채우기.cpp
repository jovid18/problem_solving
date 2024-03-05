#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;
int N;
vector<vector<pair<int, int>>> G;
vector<vector<pair<int, int>>> T;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
bool isin(int x, int y) { return x >= 0 && x < N && y >= 0 && y < N; }
void changeto0(vector<pair<int, int>> &v) {
    sort(v.begin(), v.end());
    int minx = 100, miny = 100;
    for (auto i : v) {
        minx = min(minx, i.first);
        miny = min(miny, i.second);
    }
    for (auto &i : v) {
        i.first -= minx;
        i.second -= miny;
    }
}
void rotate0(vector<pair<int, int>> &v) {
    for (auto &i : v) {
        int temp = i.first;
        i.first = i.second;
        i.second = -temp;
    }
    changeto0(v);
}
bool Gmatched[2501];
bool Tmatched[2501];
int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
    int answer = 0;
    N = game_board.size();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            vector<pair<int, int>> temp;
            if (game_board[i][j] == 0) {
                temp.push_back({i, j});
                game_board[i][j] = 1;
                queue<pair<int, int>> q;
                q.push({i, j});
                while (!q.empty()) {
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();
                    for (int k = 0; k < 4; k++) {
                        int nx = x + dx[k];
                        int ny = y + dy[k];
                        if (isin(nx, ny) && game_board[nx][ny] == 0) {
                            game_board[nx][ny] = 1;
                            temp.push_back({nx, ny});
                            q.push({nx, ny});
                        }
                    }
                }
            }
            if (temp.size() > 0)
                G.push_back(temp);
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            vector<pair<int, int>> temp;
            if (table[i][j] == 1) {
                temp.push_back({i, j});
                table[i][j] = 0;
                queue<pair<int, int>> q;
                q.push({i, j});
                while (!q.empty()) {
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();
                    for (int k = 0; k < 4; k++) {
                        int nx = x + dx[k];
                        int ny = y + dy[k];
                        if (isin(nx, ny) && table[nx][ny] == 1) {
                            table[nx][ny] = 0;
                            temp.push_back({nx, ny});
                            q.push({nx, ny});
                        }
                    }
                }
            }
            if (temp.size() > 0)
                T.push_back(temp);
        }
    }
    for (auto &i : G) {
        changeto0(i);
    }
    for (auto &i : T) {
        changeto0(i);
    }
    for (int r = 0; r < 4; ++r) {
        for (int i = 0; i < G.size(); i++) {
            if (Gmatched[i])
                continue;
            for (int j = 0; j < T.size(); j++) {
                if (Tmatched[j])
                    continue;
                if (G[i].size() == T[j].size()) {
                    bool flag = true;
                    for (int k = 0; k < G[i].size(); k++) {
                        if (G[i][k] != T[j][k]) {
                            flag = false;
                            break;
                        }
                    }
                    if (flag) {
                        Gmatched[i] = true;
                        Tmatched[j] = true;
                        answer += G[i].size();
                        break;
                    }
                }
            }
        }
        for (auto &i : T) {
            rotate0(i);
        }
    }
    return answer;
}