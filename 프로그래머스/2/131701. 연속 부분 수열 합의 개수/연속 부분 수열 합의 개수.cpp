#include <iostream>
#include <string>
#include <vector>
using namespace std;
int DP[2001][2001];
int checked[1000001];
int solution(vector<int> elements) {
    int answer = 0;
    int N = elements.size();
    for (int i = 0; i < 2 * N; ++i) {
        DP[i][i] = elements[i % N];
        if (checked[DP[i][i]] == 0) {
            checked[DP[i][i]] = 1;
            answer++;
        }
    }
    for (int i = 1; i < N; ++i) {
        for (int j = 0; j < 2 * N - i; ++j) {
            if (j == 0) {
                DP[0][i] = DP[0][i - 1] + DP[i][i];
                if (checked[DP[0][i]] == 0) {
                    checked[DP[0][i]] = 1;
                    answer++;
                }
            } else {
                DP[j][j + i] = DP[j][j + i - 1] + DP[j + i][j + i];
                if (checked[DP[j][j + i]] == 0) {
                    checked[DP[j][j + i]] = 1;
                    answer++;
                }
            }
        }
    }
    return answer;
}