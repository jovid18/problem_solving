#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, M, x;
vector<int> A, B;
int DP[10][101][101][3];
const int MOD = 8;
int idx(int i) {
	return i % MOD;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	A.resize(N);
	for (int i = 0;i < N;++i) {
		cin >> A[i];
	}
	cin >> M;
	B.resize(M);
	for (int i = 0;i < M;++i) {
		cin >> B[i];
	}

	int ans = 0;
	sort(B.begin(), B.end(), greater<>());
	for (int i = 0;i <= N;++i) {
		for (int j = 0;j <= M;++j) {
			for (int k = 0;k <= M - j;++k) {
				int& zero = DP[idx(i)][j][k][0];
				zero = 0;
				if (i - 2 >= 0) zero = max({ zero, DP[idx(i - 2)][j][k][0], DP[idx(i - 2)][j][k][1] });
				if (i - 1 >= 0 && k - 1 >= 0) zero = max({ zero, DP[idx(i - 1)][j][k - 1][0], DP[idx(i - 1)][j][k - 1][1] });
				if (i - 1 >= 0) zero = max({ zero, DP[idx(i - 1)][j][k][2] });
				if (i - 1 >= 0) zero += A[i - 1];
				int& one = DP[idx(i)][j][k][1];
				one = 0;
				if (i - 1 >= 0 && j - 1 >= 0) one = max({ one, DP[idx(i - 1)][j - 1][k][0] ,DP[idx(i - 1)][j - 1][k][1] });
				if (j - 1 >= 0 && k - 1 >= 0) one = max({ one, DP[idx(i)][j - 1][k - 1][0], DP[idx(i)][j - 1][k - 1][1] });
				if (j - 1 >= 0) one = max({ one,DP[idx(i)][j - 1][k][2] });
				if (j - 1 >= 0) one += B[j - 1];
				int& two = DP[idx(i)][j][k][2];
				two = 0;
				if (i - 1 >= 0) two = max({ two,DP[idx(i - 1)][j][k][0],DP[idx(i - 1)][j][k][2] });
				if (j - 1 >= 0) two = max({ two,DP[idx(i)][j - 1][k][1],DP[idx(i)][j - 1][k][2] });
				ans = max({ ans,zero,one,two });
			}
		}
	}
	cout << ans;
}