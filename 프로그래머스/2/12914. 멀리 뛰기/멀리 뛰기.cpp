#include <string>
#include <vector>

using namespace std;
const int MOD = 1234567;
long long DP[2001];
long long solution(int n) {
    DP[1] = 1;
    DP[2] = 2;
    for (int i = 3; i <= n; ++i) {
        DP[i] = (DP[i - 1] + DP[i - 2]) % MOD;
    }
    return DP[n];
}