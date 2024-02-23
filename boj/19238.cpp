#include <bits/stdc++.h>
using namespace std;
#define int long long
using pii = pair<int, int>;
int N, M, F;
int board[21][21];
pii T;
pair<pii, pii> p[401];
bool finished[401];
int carry[401];
int x[4] = {0, 0, 1, -1};
int y[4] = {1, -1, 0, 0};
bool isin(pii a) {
    return a.first > 0 && a.first <= N && a.second > 0 && a.second <= N;
}
pii findguest(pii taxi) {
    queue<pii> q;
    q.push(taxi);
    int distance[21][21] = {0};
    distance[taxi.first][taxi.second] = 1;
    while (!q.empty()) {
        pii cur = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) {
            pii next = {cur.first + x[i], cur.second + y[i]};
            if (isin(next) && !distance[next.first][next.second] &&
                board[next.first][next.second] != 1) {
                distance[next.first][next.second] =
                    distance[cur.first][cur.second] + 1;
                q.push(next);
            }
        }
    }
    int min = 1e9;
    int guest = 0;
    pii ret = {0, 0};
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            for (int k = 0; k < M; ++k) {
                if (p[k].first == pii(i, j) && !finished[k]) {
                    if (distance[i][j] && distance[i][j] < min) {
                        min = distance[i][j];
                        ret = {i, j};
                        guest = k;
                    }
                }
            }
        }
    }
    finished[guest] = true;
    if (min == 1e9)
        return {-1, 0};
    return {guest, min - 1};
}
void gotodest() {
    for (int i = 0; i < M; ++i) {
        if (p[i].first == p[i].second) {
            carry[i] = 0;
            continue;
        }
        queue<pii> q;
        q.push(p[i].first);
        int distance[21][21] = {0};
        distance[p[i].first.first][p[i].first.second] = 1;
        while (!q.empty()) {
            pii cur = q.front();
            q.pop();
            for (int j = 0; j < 4; ++j) {
                pii next = {cur.first + x[j], cur.second + y[j]};
                if (isin(next) && !distance[next.first][next.second] &&
                    board[next.first][next.second] != 1) {
                    distance[next.first][next.second] =
                        distance[cur.first][cur.second] + 1;
                    q.push(next);
                }
            }
        }
        if (distance[p[i].second.first][p[i].second.second] == 0) {
            carry[i] = -1;
            continue;
        }
        carry[i] = distance[p[i].second.first][p[i].second.second] - 1;
    }
}
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> M >> F;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            cin >> board[i][j];
        }
    }
    cin >> T.first >> T.second;
    for (int i = 0; i < M; ++i) {
        cin >> p[i].first.first >> p[i].first.second >> p[i].second.first >>
            p[i].second.second;
    }
    gotodest();
    for (int i = 0; i < M; ++i) {
        if (carry[i] == -1) {
            cout << -1;
            return 0;
        }
    }
    for (int i = 0; i < M; ++i) {
        int nowcost = 0;
        pii findresult = findguest(T);
        if (findresult.first == -1) {
            cout << -1;
            return 0;
        }
        T = p[findresult.first].second;
        nowcost = findresult.second + carry[findresult.first];
        if (nowcost > F) {
            cout << -1;
            return 0;
        }
        F += -findresult.second + carry[findresult.first];
    }
    cout << F;
}