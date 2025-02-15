#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
using pss = pair<string, string>;
vector<pss> C, D;
vector<int> A;
vector<int> B;
vector<bool> visited;
vector<vector<int>> edge;
int T, c, d, v;
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
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> T;
	while (T--) {
		cin >> c >> d >> v;
		C.clear();
		D.clear();
		for (int i = 0;i < v;++i) {
			string G, B;
			cin >> G >> B;
			if (G[0] == 'C') {
				C.push_back({ G,B });
			}
			else {
				D.push_back({ G,B });
			}
		}
		edge.clear();
		edge.resize(C.size());
		A.assign(C.size(), -1);
		B.assign(C.size(), -1);
		for (int i = 0;i < C.size();++i) {
			for (int j = 0;j < D.size();++j) {
				if (C[i].first == D[j].second || C[i].second == D[j].first) edge[i].push_back(j);
			}
		}
		int match = 0;
		visited.assign(C.size(), false);
		for (int i = 0;i < C.size(); ++i) {
			if (A[i] == -1) {
				visited.assign(C.size(), false);
				if (dfs(i)) {
					match++;
				}
			}
		}
		cout << v - match << '\n';
	}
}
