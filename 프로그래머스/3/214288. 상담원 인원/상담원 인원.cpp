#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;
vector<pair<int, int>> P[5];
int DP[5][21];
int answer = 0x3f3f3f3f;
int K, N;
void findwaittime(int k, int n) {
    int waittime = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (auto e : P[k]) {
        while (!pq.empty() && pq.top() <= e.first) {
            pq.pop();
        }
        if (pq.size() < n) {
            pq.push(e.first + e.second);
            continue;
        }
        int cur = pq.top();
        pq.pop();
        waittime += cur - e.first;
        pq.push(cur + e.second);
    }
    DP[k][n] = waittime;
}
void sol(int nowconsulting, int remainconsultants, int waittime) {
    if (nowconsulting == K) {
        answer = min(answer, waittime);
        return;
    }
    if (nowconsulting == K - 1) {
        sol(nowconsulting + 1, 0,
            waittime + DP[nowconsulting][remainconsultants]);
        return;
    }
    for (int i = 1; i < remainconsultants; ++i) {
        sol(nowconsulting + 1, remainconsultants - i,
            waittime + DP[nowconsulting][i]);
    }
}
int solution(int k, int n, vector<vector<int>> reqs) {
    K = k;
    N = n;
    for (auto e : reqs) {
        P[e[2] - 1].push_back({e[0], e[1]});
    }
    for (int i = 0; i < k; ++i) {
        sort(P[i].begin(), P[i].end());
    }
    for (int i = 0; i < k; ++i) {
        for (int j = 1; j <= n; ++j) {
            findwaittime(i, j);
            cout << i << " " << j << " " << DP[i][j] << endl;
        }
    }
    sol(0, n, 0);
    return answer;
}