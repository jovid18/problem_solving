#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> A;
vector<int> B;
vector<bool> visited;
vector<vector<int>> edge;
const int MAX = 1001;
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
int T, n, m;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> T;
	while (T--) {
		cin >> n >> m;
		edge.clear();
		edge.resize(MAX);
		A.assign(MAX, -1);
		B.assign(MAX, -1);
		while (m--) {
			int u, v;
			cin >> u >> v;
			edge[u].push_back(v);
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
		cout << match << '\n';
	}
}