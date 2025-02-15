#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using pii = pair<int, int>;
char B[600][600];
bool visited[600][600];
int x[4] = { 1,-1,0,0 };
int y[4] = { 0,0,1,-1 };
int N, M;
queue<pii> q;
bool in(int x, int y) {
	if (x < 0 || x >= N || y < 0 || y >= M) return false;
	return true;
}
int main()
{
	cin >> N >> M;
	for (int i = 0;i < N;++i) {
		for (int j = 0;j < M;++j) {
			cin >> B[i][j];
			if (B[i][j] == 'I') {
				q.push({ i, j });
				visited[i][j] = true;
			}
		}
	}
	int ans = 0;
	while (!q.empty()) {
		int x0 = q.front().first;
		int y0 = q.front().second;
		q.pop();
		for (int i = 0;i < 4;++i) {
			int xi = x0 + x[i];
			int yi = y0 + y[i];
			if (in(xi, yi) && !visited[xi][yi] && B[xi][yi] != 'X') {
				visited[xi][yi] = true;
				q.push({ xi,yi });
				if (B[xi][yi] == 'P') ans++;
			}
		}
	}
	if (!ans) cout << "TT";
	else cout << ans;

}
