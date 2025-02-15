#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
const int INF = 0x3f3f3f3f;
int T, N, M;
struct mk {
	int s, p, o;
};
vector<mk> V;
bool compbyp(const mk& a, const mk& b) {
	return a.p < b.p;
}
int DP[101][10001];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> T;
	while (T--) {
		cin >> N >> M;
		V.resize(M);
		for (int i = 0;i < M;++i) {
			cin >> V[i].s >> V[i].p >> V[i].o;
		}
		memset(DP, INF, sizeof(DP));
		sort(V.begin(), V.end(), compbyp);
		DP[0][0] = 0;
		for (int i = 0;i < M;++i) {
			for (int j = 0;j <= N;++j) {
				if (DP[i][j] == INF) continue;
				DP[i + 1][j] = min(DP[i][j], DP[i + 1][j]);
				int maxbuy = min(V[i].s, N - j);
				DP[i + 1][j + maxbuy] = min(DP[i + 1][j + maxbuy], DP[i][j] + maxbuy * V[i].p + V[i].o);
			}
		}
		cout << DP[M][N] << '\n';
	}
}
