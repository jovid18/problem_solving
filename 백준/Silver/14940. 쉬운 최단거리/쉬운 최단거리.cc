#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
using pii = pair<int, int>;
int n, m;
int M[1001][1001], ans[1001][1001];
bool visited[1001][1001];
int x[4] = { 1,-1,0,0 };
int y[4] = { 0,0,1,-1 };
bool in(int x, int y) {
	if (x < 0 || y < 0 || x >= n || y >= m) return false;
	return true;
}
queue<pii> q;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0;i < n;++i) {
		for (int j = 0;j < m;++j) {
			cin >> M[i][j];
			if (M[i][j] == 2) {
				q.push({ i,j });
				visited[i][j] = true;
			}
		}
	}
	while (!q.empty()) {
		int x0 = q.front().first;
		int y0 = q.front().second;
		q.pop();
		for (int i = 0;i < 4;++i) {
			int xi = x0 + x[i];
			int yi = y0 + y[i];
			if (in(xi, yi) && !visited[xi][yi] && M[xi][yi] ==1) {
				q.push({ xi,yi });
				visited[xi][yi] = true;
				ans[xi][yi] = ans[x0][y0] + 1;
			}
		}
	}
	for (int i = 0;i < n;++i) {
		for (int j = 0;j < m;++j) {
			if (ans[i][j] != 0) cout << ans[i][j] << " ";
			else if (M[i][j] == 1) cout << -1 << " ";
			else cout << 0 << " ";
		}
		cout << '\n';
	}
}
