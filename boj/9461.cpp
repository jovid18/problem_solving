#include <iostream>
#include <map>
#include <string>
using namespace std;
using ll = long long;
int T, N;
ll DP[101] = {0, 1, 1, 1, 2, 2, 3, 4, 5, 7, 9};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for (int i = 11; i <= 100; ++i) {
        DP[i] = DP[i - 2] + DP[i - 3];
    }
    cin >> T;
    while (T--) {
        cin >> N;
        cout << DP[N] << '\n';
    }
}
