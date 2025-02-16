#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
const int MAXV = 25003;
const ll INF = 1LL << 32;
int N, M, C, S, T, ANS, idx;
vector<pil> G[MAXV];
vector<int> RG[MAXV];
int CM[MAXV];
ll d[MAXV];
vector<pair<ll, pair<int, int>>> CMT;
vector<vector<pair<int, int>>> CMTR;

void dijkstra(int s) {
	priority_queue<pair<ll, int>> pq;
	pq.push({ 0,s });
	d[s] = 0;
	while (!pq.empty()) {
		ll dist = -pq.top().first;
		int now = pq.top().second;
		pq.pop();
		if (d[now] < dist) continue;
		for (auto e : G[now]) {
			ll cost = dist + e.second;
			if (cost < d[e.first]) {
				d[e.first] = cost;
				pq.push({ -cost,e.first });
			}
		}
	}
}
struct Edge {
	int u, v;
	int cap, flow;
	Edge() {}
	Edge(int u, int v, int cap) : u(u), v(v), cap(cap), flow(0) {}
};

struct Dinic {
	int N;
	vector<Edge> E;
	vector<vector<int>> g;
	vector<int> d, pt;
	Dinic(int N) : N(N), E(0), g(N), d(N), pt(N) {}
	void AddEdge(int u, int v, int cap) {
		if (u != v) {
			E.push_back(Edge(u, v, cap));
			g[u].push_back(E.size() - 1);
			E.push_back(Edge(v, u, 0));
			g[v].push_back(E.size() - 1);
		}
	}
	bool BFS(int S, int T) {
		queue<int> q({ S });
		fill(d.begin(), d.end(), N + 1);
		d[S] = 0;
		while (!q.empty()) {
			int u = q.front();
			q.pop();
			if (u == T) break;
			for (int k : g[u]) {
				Edge& e = E[k];
				if (e.flow<e.cap && d[e.v]>d[e.u] + 1) {
					d[e.v] = d[e.u] + 1;
					q.push(e.v);
				}
			}
		}
		return d[T] != N + 1;
	}
	int DFS(int u, int T, int flow = -1) {
		if (u == T || flow == 0) return flow;
		for (int& i = pt[u];i < g[u].size();++i) {
			Edge& e = E[g[u][i]];
			Edge& oe = E[g[u][i] ^ 1];
			if (d[e.v] == d[e.u] + 1) {
				int amt = e.cap - e.flow;
				if (flow != -1 && amt > flow) amt = flow;
				if (int pushed = DFS(e.v, T, amt)) {
					e.flow += pushed;
					oe.flow -= pushed;
					return pushed;
				}
			}
		}
		return 0;
	}
	int MaxFlow(int S, int T) {
		int total = 0;
		while (BFS(S, T)) {
			fill(pt.begin(), pt.end(), 0);
			while (int flow = DFS(S, T)) {
				total += flow;
			}
		}
		return total;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M >> C;
	T=N+1;
	for (int i = 1;i <= M;++i) {
		ll x, y, w;
		cin >> x >> y >> w;
		G[x].push_back({ y,w });
		G[y].push_back({ x,w });
	}
	for (int i = 0;i < C;++i) {
		int x;
		cin >> x;
		CM[x]++;
	}
	if(C==0){
		cout<<0;
		return 0;
	}
	fill(d, d + MAXV, INF);
	dijkstra(1);
	for (int i = 1;i <= N;++i) {
		for (auto e : G[i]) {
			if (d[e.first] - d[i] == e.second) RG[i].push_back(e.first);
		}
	}
	for (int i = 1;i <= N;++i) {
		if (CM[i] > 0) CMT.push_back({ d[i],{i,CM[i]} });
	}
	sort(CMT.begin(), CMT.end());
	CMTR.resize(1);
	CMTR[0].push_back({ CMT[0].second.first,CMT[0].second.second });
	for (int i = 1;i < CMT.size();++i) {
		if (CMT[i].first != CMT[i - 1].first) {
			idx++;
			CMTR.resize(idx + 1);
		}
		CMTR[idx].push_back({ CMT[i].second.first,CMT[i].second.second });
	}
	for (auto e : CMTR) {
		Dinic* dinic = new Dinic(MAXV-1);
		dinic->AddEdge(S, 1, C+1);
		for (int i = 1;i <= N;++i) {
			for (auto f : RG[i]) {
				dinic->AddEdge(i, f, 1);
			}
		}
		for (auto f : e) {
			dinic->AddEdge(f.first, T, f.second);
		}
		ANS += dinic->MaxFlow(S, T);
		delete dinic;
	}
	cout << ANS;
}