#include <iostream>
#include <vector>
using namespace std;
int C, N, M, MAX;
vector<vector<char>> CR;
vector<int> A, B;
vector<bool> visited;
vector<vector<int>> edge;
using pii = pair<int, int>;
bool dfs(int a) {
	visited[a] = true;
	for (auto b : edge[a]) {
		if (B[b] == -1 || (!visited[B[b]] && dfs(B[b]))) {
			A[a] = b;
			B[b] = a;
			return true;
		}
	}
	return false;
}
int x[] = { 0,0,1,1,-1,-1 };
int y[] = { -1,1,-1,1 ,-1,1 };
int tonum(int i, int j) {
	return (j / 2) * N + i;
}
bool in(int i, int j) {
	if (0 <= i && i < N && 0 <= j && j < M && CR[i][j] == '.') {
		return true;
	}
	return false;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> C;
	while (C--) {
		cin >> N >> M;
		int xcount = 0;
		CR.assign(N, vector<char>(M, '0'));
		for (int i = N - 1;i >= 0;--i) {
			for (int j = 0;j < M;++j) {
				cin >> CR[i][j];
				if (CR[i][j] == 'x') xcount++;
			}
		}
		MAX = M * N * 2 / 3;
		edge.clear();
		edge.resize(MAX);
		A.assign(MAX, -1);
		B.assign(MAX, -1);
		for (int i = 0;i < N;++i) {
			for (int j = 0;j < M;j += 2) {
				if (CR[i][j] == 'x') continue;
				int a = tonum(i, j);
				for (int t = 0;t < 6;++t) {
					int xt = i + x[t];
					int yt = j + y[t];
					if (in(xt, yt)) edge[a].push_back(tonum(xt, yt));
				}
			}
		}
		int match = 0;
		visited.assign(MAX, false);
		for (int i = 0;i < MAX; ++i) {
			if (A[i] == -1) {
				visited.assign(MAX, false);
				if (dfs(i)) {
					match++;
				}
			}
		}
		cout << N * M - xcount - match << '\n';
	}
}