#include <iostream>
#include <vector>
using namespace std;
vector<int> adj[100];
bool visited[100][100];
int N;
int ans[100][100];
void dfs(int x, int i) {
	for (auto e : adj[i]) {
		if (visited[x][e]) continue;
		visited[x][e] = true;
		ans[x][e] = 1;
		dfs(x, e);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 0;i < N;++i) {
		for (int j = 0;j < N;++j) {
			int x;
			cin >> x;
			if (x) adj[i].push_back(j);
		}
	}
	for (int i = 0;i < N;++i) {
		dfs(i, i);
	}
	for (int i = 0;i < N;++i) {
		for (int j = 0;j < N;++j) {
			cout << ans[i][j] << " ";
		}
		cout << '\n';
	}
}