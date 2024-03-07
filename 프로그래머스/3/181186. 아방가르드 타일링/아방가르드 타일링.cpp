#include <string>
#include <vector>

using namespace std;
const long long MOD = 1000000007;
long long DP[100001];
int solution(int n) {
    for (int i = 0; i <= n; i++) {
        if (i == 0) {
            DP[i] = 1;
        } else if (i == 1)
            DP[i] = 1;
        else if (i == 2)
            DP[i] = 3;
        else if (i == 3)
            DP[i] = 10;
        else if (i == 4)
            DP[i] = 23;
        else if (i == 5)
            DP[i] = 62;
        else
            DP[i] = (DP[i - 1] + 2 * DP[i - 2] + 6 * DP[i - 3] + DP[i - 4] -
                     DP[i - 6] + MOD) %
                    MOD;
    }
    return DP[n];
}