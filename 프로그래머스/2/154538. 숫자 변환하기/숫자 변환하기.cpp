#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;
const int MAX = 1000000;
queue<pair<int, int>> Q;
bool checked[1000001];
int solution(int x, int y, int n) {
    if (x > y)
        return -1;
    if (x == y)
        return 0;
    Q.push({x, 0});
    checked[x] = true;
    while (!Q.empty()) {
        auto [num, cnt] = Q.front();
        Q.pop();
        if (num == y)
            return cnt;
        if (num + n <= MAX) {
            if (!checked[num + n]) {
                Q.push({num + n, cnt + 1});
                checked[num + n] = true;
            }
        }
        if (2 * num <= MAX) {
            if (!checked[2 * num]) {
                Q.push({2 * num, cnt + 1});
                checked[num * 2] = true;
            }
        }
        if (3 * num <= MAX) {
            if (!checked[3 * num]) {
                Q.push({3 * num, cnt + 1});
                checked[num * 3] = true;
            }
        }
    }
    return -1;
}