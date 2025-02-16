#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
using pii = pair<int, int>;
queue<pii> q;
char M[101][101];
int N;
bool V1[101][101],V2[101][101];
int S1, S2;
int x[] = { 1,-1,0,0 };
int y[] = { 0,0,-1,1 };
bool in(int x, int y) {
	if (x < 0 || y < 0 || x >= N || y >= N) return false;
	return true;
}
void bfs1(void) {

}
int main() {
	cin >> N;
	for (int i = 0;i < N;++i) {
		for (int j = 0;j < N;++j) {
			cin >> M[i][j];
		}
	}
	for (int i = 0;i < N;++i) {
		for (int j = 0;j < N;++j) {
			if (V1[i][j]) continue;
			S1++;
			V1[i][j] = true;
			q.push({ i,j });
			char c = M[i][j];
			while (!q.empty()) {
				auto x0 = q.front().first;
				auto y0 = q.front().second;
				q.pop();
				for (int i = 0;i < 4;++i) {
					int xi = x0 + x[i];
					int yi = y0 + y[i];
					if (in(xi, yi) && !V1[xi][yi] && M[xi][yi] == c) {
						V1[xi][yi] = 1;
						q.push({ xi,yi });
					}
				}
			}
		}
	}
	for (int i = 0;i < N;++i) {
		for (int j = 0;j < N;++j) {
			if (M[i][j] == 'G') M[i][j] = 'R';
		}
	}
	for (int i = 0;i < N;++i) {
		for (int j = 0;j < N;++j) {
			if (V2[i][j]) continue;
			S2++;
			V2[i][j] = true;
			q.push({ i,j });
			char c = M[i][j];
			while (!q.empty()) {
				auto x0 = q.front().first;
				auto y0 = q.front().second;
				q.pop();
				for (int i = 0;i < 4;++i) {
					int xi = x0 + x[i];
					int yi = y0 + y[i];
					if (in(xi, yi) && !V2[xi][yi] && M[xi][yi] == c) {
						V2[xi][yi] = 1;
						q.push({ xi,yi });
					}
				}
			}
		}
	}
	cout << S1 << " " << S2;
}