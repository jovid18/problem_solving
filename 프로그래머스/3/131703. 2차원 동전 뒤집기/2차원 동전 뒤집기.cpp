#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<vector<bool>> B, T;
int N;
vector<vector<bool>> solve(vector<vector<bool>> beginning, int horizontal,
                           int vertical) {
    auto ret = beginning;
    for (int i = 0; i < N; ++i) {
        if (horizontal & (1 << i)) {
            for (int j = 0; j < N; ++j) {
                ret[i][j] = !ret[i][j];
            }
        }
    }
    for (int i = 0; i < N; ++i) {
        if (vertical & (1 << i)) {
            for (int j = 0; j < N; ++j) {
                ret[j][i] = !ret[j][i];
            }
        }
    }
    return ret;
}
int solution(vector<vector<int>> beginning, vector<vector<int>> target) {
    int answer = 0;
    N = beginning.size();
    for (int i = 0; i < N; i++) {
        vector<bool> temp;
        for (int j = 0; j < N; j++) {
            temp.push_back(beginning[i][j]);
        }
        B.push_back(temp);
    }
    for (int i = 0; i < N; i++) {
        vector<bool> temp;
        for (int j = 0; j < N; j++) {
            temp.push_back(target[i][j]);
        }
        T.push_back(temp);
    }
    int ans = 1e9;
    for (int i = 0; i < (1 << N); i++) {
        for (int j = 0; j < (1 << N); j++) {
            auto temp = solve(B, i, j);
            if (temp == T) {
                cout << i << " " << j << endl;
                ans = min(ans, __builtin_popcount(i) + __builtin_popcount(j));
            }
        }
    }

    return ans == 1e9 ? -1 : ans;
}