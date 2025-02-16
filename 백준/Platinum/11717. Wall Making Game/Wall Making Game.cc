#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int H, W;
int DP[20][20][20][20];
vector<vector<char>> M;
bool valid(int x1, int x2, int y1, int y2) {
	if (x1 > x2 || y1 > y2) return false;
	if (x1 < 0 || H <= x1) return false;
	if (x2 < 0 || H <= x2) return false;
	if (y1 < 0 || W <= y1) return false;
	if (y2 < 0 || W <= y2) return false;
	return true;
}
int solve(int x1, int x2, int y1, int y2) {
	if (!valid(x1, x2, y1, y2)) return 0;
	if (DP[x1][x2][y1][y2] != -1) return DP[x1][x2][y1][y2];
	vector<bool> visited(101);
	for (int i = x1;i <= x2;++i) {
		for (int j = y1;j <= y2;++j) {
			if (M[i][j] == 'X') continue;
			int now = 0;
			now ^= solve(x1, i - 1, y1, j - 1);
			now ^= solve(i + 1, x2, y1, j - 1);
			now ^= solve(x1, i - 1, j + 1, y2);
			now ^= solve(i + 1, x2, j + 1, y2);
			visited[now] = true;
		}
	}
	for (int i = 0;i < 101;++i) {
		if (!visited[i]) {
			return DP[x1][x2][y1][y2] = i;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> H >> W;
	M.assign(H, vector<char>(W, '.'));
	memset(DP, -1, sizeof(DP));
	for (int i = 0;i < H;++i) {
		for (int j = 0;j < W;++j) {
			cin >> M[i][j];
			int& now = DP[i][i][j][j];
			if (M[i][j] == '.') now = 1;
			else now = 0;
		}
	}
	cout << (solve(0, H - 1, 0, W - 1) ? "First" : "Second");
}
