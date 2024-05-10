#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;
queue<pair<int, int>> Q;
int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int t = 0;
    int now_weights = 0;
    reverse(truck_weights.begin(), truck_weights.end());
    for (;; ++t) {
        while (!Q.empty()) {
            auto [f, s] = Q.front();
            if (t - s >= bridge_length) {
                Q.pop();
                now_weights -= f;
            } else {
                break;
            }
        }
        if (Q.empty() && truck_weights.empty()) {
            break;
        }
        if (!truck_weights.empty()) {
            int truck_now = truck_weights.back();
            if (now_weights + truck_now <= weight) {
                truck_weights.pop_back();
                now_weights += truck_now;
                Q.push({truck_now, t});
            }
        }
    }
    return t + 1;
}