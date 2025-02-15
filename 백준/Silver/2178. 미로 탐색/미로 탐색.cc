#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using pii = pair<int, int>;
int N, M;
bool B[101][101], V[1001][1001];
int D[101][101];
int x[4] = { 1,-1,0,0 };
int y[4] = { 0,0,1,-1 };
bool in(int x, int y) {
	if (x < 0 || y < 0 || x >= N || y >= M) return false;
	return true;
}
queue<pii> q;
int main() {
	cin >> N >> M;
	for (int i = 0;i < N;++i) {
		for (int j = 0;j < M;++j) {
			char x;
			cin >> x;
			B[i][j] = x-'0';
		}
	}
	V[0][0] = 1;
	D[0][0] = 1;
	q.push({ 0,0 });
	while (!q.empty()) {
		int x0 = q.front().first;
		int y0 = q.front().second;
		q.pop();
		for (int i = 0;i < 4;++i) {
			int xi = x0 + x[i];
			int yi = y0 + y[i];
			if (in(xi, yi) && B[xi][yi] && !V[xi][yi]) {
				V[xi][yi] = true;
				q.push({ xi,yi });
				D[xi][yi] = D[x0][y0] + 1;
			}
		}
	}
	cout << D[N - 1][M - 1];
}
