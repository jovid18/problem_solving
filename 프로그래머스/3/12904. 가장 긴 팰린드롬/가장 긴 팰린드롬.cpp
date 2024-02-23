#include <iostream>
#include <string>
using namespace std;
int DP[2500][2500];
int solution(string s) {
    int answer = 0;
    int n = s.size();
    for (int i = 0; i < n; ++i) {
        DP[i][i] = 1;
        answer = max(answer, DP[i][i]);
    }
    for (int i = 0; i < n - 1; ++i) {
        if (s[i] == s[i + 1])
            DP[i][i + 1] = 2;
        answer = max(answer, DP[i][i + 1]);
    }
    for (int k = 2; k < n; ++k) {
        for (int i = 0; i + k < n; ++i) {
            if (s[i] == s[i + k] && DP[i + 1][i + k - 1] > 0) {
                DP[i][i + k] = DP[i + 1][i + k - 1] + 2;
                answer = max(answer, DP[i][i + k]);
            }
        }
    }

    return answer;
}