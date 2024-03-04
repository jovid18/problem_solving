#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
using pii = pair<int, int>;
int N, M;
bool isin(int x, int y) { return 0 <= x && x < N && 0 <= y && y < M; }
int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
pair<char, int> B(vector<vector<int>> board, pii a, pii b, int cnt);
pair<char, int> A(vector<vector<int>> board, pii a, pii b, int cnt) {
    if (board[a.first][a.second] == 0)
        return {'B', cnt};
    vector<pair<char, int>> Awins;
    vector<pair<char, int>> Bwins;
    bool cannotmove = true;
    for (int i = 0; i < 4; i++) {
        int ax = a.first + dx[i], ay = a.second + dy[i];
        if (!isin(ax, ay))
            continue;
        if (board[ax][ay] == 0)
            continue;
        cannotmove = false;
        auto board2 = board;
        board2[a.first][a.second] = 0;
        auto result = B(board2, {ax, ay}, b, cnt + 1);
        if (result.first == 'A')
            Awins.push_back(result);
        else
            Bwins.push_back(result);
    }
    if (cannotmove)
        return {'B', cnt};
    sort(Awins.begin(), Awins.end());
    sort(Bwins.begin(), Bwins.end());
    if (Awins.empty()) {
        return Bwins.back();
    }
    return Awins.front();
}
pair<char, int> B(vector<vector<int>> board, pii a, pii b, int cnt) {
    if (board[b.first][b.second] == 0)
        return {'A', cnt};
    vector<pair<char, int>> Awins;
    vector<pair<char, int>> Bwins;
    bool cannotmove = true;
    for (int i = 0; i < 4; i++) {
        int bx = b.first + dx[i], by = b.second + dy[i];
        if (!isin(bx, by))
            continue;
        if (board[bx][by] == 0)
            continue;
        cannotmove = false;
        auto board2 = board;
        board2[b.first][b.second] = 0;
        auto result = A(board2, a, {bx, by}, cnt + 1);
        if (result.first == 'B')
            Bwins.push_back(result);
        else
            Awins.push_back(result);
    }
    if (cannotmove)
        return {'A', cnt};
    sort(Awins.begin(), Awins.end());
    sort(Bwins.begin(), Bwins.end());
    if (Bwins.empty())
        return Awins.back();
    return Bwins.front();
}
int solution(vector<vector<int>> board, vector<int> aloc, vector<int> bloc) {
    N = board.size(), M = board[0].size();
    pair<char, int> res = A(board, {aloc[0], aloc[1]}, {bloc[0], bloc[1]}, 0);
    return res.second;
}