#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
int V, E;
const int VMAX = 2001;
const int CYC = 1000;
int S, T;
int INF = 1e9;
int CMIN = 0;
vector<int> adj[VMAX];
int c[VMAX][VMAX];
int f[VMAX][VMAX];
int d[VMAX][VMAX];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	while (cin >> V >> E) {
		S = 1;
		T = V + CYC;
		CMIN = 0;
		memset(c, 0, sizeof(c));
		memset(f, 0, sizeof(f));
		memset(d, 0, sizeof(d));
		for (int i = 1;i <= VMAX - 1;++i) {
			adj[i].clear();
		}
		for (int i = 1;i <= V;++i) {
			c[i][i + CYC] = 1;
			adj[i].push_back(i + CYC);
			adj[i + CYC].push_back(i);
			if (i == 1 || i == V) c[i][i + CYC] = 2;
		}
		while (E--) {
			int from, to, cost;
			cin >> from >> to >> cost;
			c[from + CYC][to] = 1;
			d[from + CYC][to] = cost;
			d[to][from + CYC] -= cost;
			adj[from + CYC].push_back(to);
			adj[to].push_back(from + CYC);
		}
		while (1) {
			int prev[VMAX], dist[VMAX];
			fill(prev, prev + VMAX, -1);
			fill(dist, dist + VMAX, INF);
			bool inq[VMAX]{};
			queue<int> q;
			dist[S] = 0;
			inq[S] = true;
			q.push(S);
			while (!q.empty()) {
				int now = q.front();
				q.pop();
				inq[now] = false;
				for (auto next : adj[now]) {
					if (c[now][next] > f[now][next] && dist[next] > dist[now] + d[now][next]) {
						dist[next] = dist[now] + d[now][next];
						prev[next] = now;
						if (!inq[next]) {
							q.push(next);
							inq[next] = true;
						}
					}
				}
			}
			if (prev[T] == -1) break;
			int flow = INF;
			for (int i = T;i != S;i = prev[i]) flow = min(flow, c[prev[i]][i] - f[prev[i]][i]);
			for (int i = T;i != S;i = prev[i]) {
				CMIN += flow * d[prev[i]][i];
				f[prev[i]][i] += flow;
				f[i][prev[i]] -= flow;
			}
		}
		cout << CMIN << '\n';
	}
}
