#include <iostream>
#include <vector>
#include <string>
using namespace std;
const int max_v = 30001;
int N, Q, pv;
int sz[max_v], dep[max_v], par[max_v], top[max_v], in[max_v], out[max_v];
vector<int> g[max_v];
vector<int> inp[max_v];
vector<int> pen;
struct Query {
	string S;
	int A, B;
};
vector<Query> q;
struct UnionFind {
	vector<int> par, siz;
	UnionFind(int n) : par(n, -1), siz(n, 1) {}
	int root(int x) {
		if (par[x] == -1) return x;
		else return par[x] = root(par[x]);
	}

	bool issame(int x, int y) {
		return root(x) == root(y);
	}

	bool unite(int x, int y) {
		x = root(x);
		y = root(y);
		if (x == y) return false;
		if (siz[x] < siz[y]) swap(x, y);
		par[y] = x;
		siz[x] += siz[y];
		return true;
	}
};
struct Seg {
	int tree[1 << 17];
	int sz = 1 << 16;
	void update(int x, int v) {
		x |= sz;
		tree[x] = v;
		while (x >>= 1) {
			tree[x] = tree[x << 1] + tree[x << 1 | 1];
		}
	}
	int get(int x) {
		return tree[sz | x];
	}
	int sum(int l, int r) {
		l |= sz, r |= sz;
		int ret = 0;
		while (l <= r) {
			if (l & 1) ret += tree[l++];
			if (~r & 1) ret += tree[r--];
			l >>= 1, r >>= 1;
		}
		return ret;
	}
}seg;

void dfs(int v = 1, int p = 0) {
	for (auto e : inp[v]) {
		if (e == p) continue;
		g[v].push_back(e);
		dfs(e, v);
	}
}
void dfs1(int v = 1) {
	sz[v] = 1;
	for (auto& e : g[v]) {
		dep[e] = dep[v] + 1;
		par[e] = v;
		dfs1(e);
		sz[v] += sz[e];
		if (sz[e] > sz[g[v][0]]) swap(e, g[v][0]);
	}
}
void dfs2(int v = 1) {
	in[v] = ++pv; out[pv] = v;
	for (auto e : g[v]) {
		top[e] = e == g[v][0] ? top[v] : e;
		dfs2(e);
	}
}
void update(int v, int p) {
	seg.update(in[v], p);
}
int query(int a, int b) {
	int ret = 0;
	while (top[a] ^ top[b]) {
		if (dep[top[a]] < dep[top[b]]) swap(a, b);
		int st = top[a];
		ret += seg.sum(in[st], in[a]);
		a = par[st];
	}
	if (dep[a] > dep[b]) swap(a, b);
	ret += seg.sum(in[a], in[b]);
	return ret;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	UnionFind uf(N + 1);
	pen.resize(N + 1);
	for (int i = 1;i <= N;++i) {
		cin >> pen[i];
	}
	cin >> Q;
	q.resize(Q);
	for (int i = 0;i < Q;++i) {
		cin >> q[i].S >> q[i].A >> q[i].B;
		if (q[i].S == "bridge") {
			if (uf.unite(q[i].A, q[i].B)) {
				inp[q[i].A].push_back(q[i].B);
				inp[q[i].B].push_back(q[i].A);
			}
		}
	}
	for (int i = 1;i <= N;++i) {
		if (uf.unite(1, i)) {
			inp[1].push_back(i);
			inp[i].push_back(1);
		}
	}
	dfs();
	dfs1();
	dfs2();
	for (int i = 1;i <= N;++i) {
		update(i, pen[i]);
		uf.par[i] = -1;
		uf.siz[i] = 1;
	}
	for (Query e : q) {
		if (e.S == "bridge") {
			if (uf.unite(e.A, e.B)) {
				cout << "yes\n";
			}
			else {
				cout << "no\n";
			}
		}
		else if (e.S == "penguins") {
			update(e.A, e.B);
		}
		else if (e.S == "excursion") {
			if (uf.issame(e.A, e.B)) {
				cout << query(e.A, e.B) << '\n';
			}
			else {
				cout << "impossible\n";
			}
		}
	}
}