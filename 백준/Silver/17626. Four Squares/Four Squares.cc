#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
using ll = long long;
int N;
int DP[50001];
vector<int> sq;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	for (int i = 1;i <= sqrt(50000);++i) {
		sq.push_back(i*i);
	}
	for (int i = 1;i <= 50000;++i) {
		DP[i] = 10000;
	}
	for (int i = 0;i <= 50000;++i) {
		for (auto j : sq) {
			if (i + j > 50000) break;
			DP[i + j] = min(DP[i + j], DP[i] + 1);
		}
	}
	cin >> N;
	cout << DP[N];
}

