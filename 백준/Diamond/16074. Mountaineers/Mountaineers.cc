#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 100001;
using pii = pair<int, int>;
struct Edge {
	int w, u, v;
};
struct unionfind {
	vector<int> par;
	vector<int> siz;
	unionfind(int n) : par(n), siz(n, 1) {
		for (int i = 0;i < n;++i) {
			par[i] = i;
		}
	}
	int root(int x) {
		if (par[x] == x) {
			return x;
		}
		else {
			return par[x] = root(par[x]);
		}
	}
	bool issame(int x, int y) {
		return root(x) == root(y);
	}
	bool unite(int x, int y) {
		x = root(x);
		y = root(y);
		if (x == y) {
			return false;
		}
		if (siz[x] < siz[y]) swap(x, y);
		par[y] = x;
		siz[x] += siz[y];
		return true;
	}
	int size(int x) {
		return siz[root(x)];
	}
};
bool comp(const Edge& a, const Edge& b) {
	return a.w < b.w;
}
int m, n, q, r;
int M[501][501];
vector<Edge> E;
vector<pii> Query;
int lo[MAX], hi[MAX];
vector<vector<int>> G;
int hashing(int i, int j) {
	return n * (j - 1) + i;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> m >> n >> q;
	for (int j = 1;j <= m;++j) {
		for (int i = 1;i <= n;++i) {
			cin >> M[i][j];
		}
	}
	for (int j = 1;j <= m;++j) {
		for (int i = 1;i < n;++i) {
			int idx1 = hashing(i, j);
			int idx2 = hashing(i + 1, j);
			E.push_back({ max(M[i][j],M[i + 1][j]),idx1,idx2 });
		}
	}
	for (int i = 1;i <= n;++i) {
		for (int j = 1;j < m;++j) {
			int idx1 = hashing(i, j);
			int idx2 = hashing(i, j + 1);
			E.push_back({ max(M[i][j],M[i][j + 1]),idx1,idx2 });
		}
	}
	sort(E.begin(), E.end(), comp);
	Query.resize(q + 1);
	for (int i = 1;i <= q;++i) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		swap(x1, y1);
		swap(x2, y2);
		int idx1 = hashing(x1, y1);
		int idx2 = hashing(x2, y2);
		Query[i] = { idx1,idx2 };
	}
	for (int i = 1;i <= q;++i) {
		lo[i] = 0;
		hi[i] = E.size() - 1;
	}
	G.resize(E.size());
	while (1) {
		bool flag = false;
		for (auto& e : G) e.clear();
		for (int i = 1;i <= q;++i) {
			if (lo[i] != hi[i]) {
				flag = true;
				int m = (lo[i] + hi[i]) / 2;
				G[m].push_back(i);
			}
		}
		if (!flag) break;
		unionfind uf(500 * 500 + 1);
		for (int i = 0;i < E.size();++i) {
			Edge edge = E[i];
			uf.unite(edge.u, edge.v);
			for (auto e : G[i]) {
				int a = uf.root(Query[e].first);
				int b = uf.root(Query[e].second);
				if (a == b) {
					hi[e] = i;
				}
				else lo[e] = i + 1;
			}
		}
	}
	for (int i = 1; i <= q; ++i) {
		if (Query[i].first == Query[i].second) {
			int hash = Query[i].first;
			cout << M[(hash - 1) % n + 1][(hash - 1) / n + 1]<<'\n';
		}
		else cout << E[hi[i]].w << '\n';
	}
}