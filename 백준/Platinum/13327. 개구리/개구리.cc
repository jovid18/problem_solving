#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;
#define xx first
#define yy second
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;
struct Line {
	pii s, f;
};
using Graph = vector<vector<pii>>;
Graph G;
vector<int> mind;
int n, m, u, v, logs, jump;
vector<Line> D, U, L;
vector<pii> V;
int s, f;
int dist(pii a, pii b) {
	return (a.xx - b.xx) * (a.xx - b.xx) + (a.yy - b.yy) * (a.yy - b.yy);
}
int minD(Line& a, Line& b) {
	if (a.s > a.f) swap(a.s, a.f);
	if (b.s > b.f) swap(b.s, b.f);
	int ret = INF;
	bool av = (a.s.xx == a.f.xx);
	bool bv = (b.s.xx == b.f.xx);
	if (av && bv) {
		if (a.f.yy < b.s.yy || a.s.yy>b.f.yy) ret = min(dist(a.s, b.f), dist(a.f, b.s));
		else ret = (a.s.xx - b.s.xx) * (a.s.xx - b.s.xx);
	}
	else if (!av && !bv) {
		if (a.f.xx < b.s.xx || a.s.xx>b.f.xx) ret = min(dist(a.s, b.f), dist(a.f, b.s));
		else ret = (a.s.yy - b.s.yy) * (a.s.yy - b.s.yy);
	}
	else if (av && !bv) {
		int mx = a.s.xx;
		int my = b.s.yy;
		int dx = 0, dy = 0;
		if (mx < b.s.xx || b.f.yy < mx) dx = min(abs(mx - b.s.xx), abs(b.f.xx - mx));
		if (my < a.s.yy || a.f.yy < my) dy = min(abs(my - a.s.yy), abs(a.f.yy - my));
		ret = dx * dx + dy * dy;
	}
	else {
		int mx = b.s.xx;
		int my = a.s.yy;
		int dx = 0, dy = 0;
		if (mx < a.s.xx || a.f.xx < mx) dx = min(abs(mx - a.s.xx), abs(a.f.xx - mx));
		if (my < b.s.yy || b.f.yy < my) dy = min(abs(my - b.s.yy), abs(b.f.yy - my));
		ret = dx * dx + dy * dy;
	}
	if (ret <= jump) return ret;
	else return INF;
}
void dijkstra(int s) {
	priority_queue<pair<int, int>> pq;
	pq.push({ 0,s });
	mind[s] = 0;
	while (!pq.empty())
	{
		int dist = -pq.top().first;
		int now = pq.top().second;
		pq.pop();
		if (mind[now] < dist) continue;

		for (int i = 0; i < G[now].size(); i++)
		{
			int cost = dist + G[now][i].second;
			if (cost < mind[G[now][i].first])
			{
				mind[G[now][i].first] = cost;
				pq.push(make_pair(-cost, G[now][i].first));
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m >> u >> v >> logs >> jump;
	V.resize(u);
	for (int i = 0;i < u;++i) {
		cin >> V[i].xx >> V[i].yy;
	}
	for (int i = 0;i < u - 1;++i) {
		D.push_back({ {V[i].xx,V[i].yy},{V[i + 1].xx,V[i + 1].yy} });
	}
	V.resize(v);
	for (int i = 0;i < v;++i) {
		cin >> V[i].xx >> V[i].yy;
	}
	for (int i = 0;i < v - 1;++i) {
		U.push_back({ { V[i].xx,V[i].yy},{V[i + 1].xx,V[i + 1].yy} });
	}
	L.resize(logs);
	for (auto& e : L) {
		cin >> e.s.xx >> e.s.yy >> e.f.xx >> e.f.yy;
	}
	G.resize(logs + 2);
	int sf = INF;
	for (auto e : U) {
		for (auto f : D) {
			sf = min(sf, minD(e, f));
		}
	}
	s = logs;
	f = logs + 1;
	G[s].push_back({ f,sf });
	G[f].push_back({ s,sf });
	for (int i = 0;i < logs;++i) {
		int sl = INF;
		int fl = INF;
		for (auto e : D) sl = min(sl, minD(e, L[i]));
		for (auto e : U) fl = min(fl, minD(e, L[i]));
		G[s].push_back({ i,sl });
		G[i].push_back({ s,sl });
		G[f].push_back({ i,fl });
		G[i].push_back({ f,fl });
	}
	for (int i = 0;i < logs;++i) {
		for (int j = i + 1;j < logs;++j) {
			int lilj = minD(L[i], L[j]);
			G[i].push_back({ j, lilj });
			G[j].push_back({ i, lilj });
		}
	}
	s = logs;
	f = logs + 1;
	mind.assign(logs + 2, INF);
	dijkstra(s);
	if (mind[f] >= INF) cout << -1;
	else cout << mind[f];
}