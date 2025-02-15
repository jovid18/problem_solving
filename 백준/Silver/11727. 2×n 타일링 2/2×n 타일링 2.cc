#include <iostream>
#include <string>
#include <map>
using namespace std;
using ll = long long;
int N;
int DP[1001] = { 0, 1,3 };
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	for (int i = 3;i <= 1000;++i) {
		DP[i] = (DP[i - 1] + 2 * DP[i - 2]) % 10007;
	}
	cin >> N;
	cout << DP[N];
}

