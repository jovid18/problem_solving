#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
using pii = pair<int, int>;
const int MAX = 1000;
struct L {
	pii s, f;
	L(int a=0, int b=0, int c=0, int d=0) :s({ a,b }), f({ a,b }) {};
};
vector<int> P(6 * MAX), SCC(6 * MAX), ANS(3 * MAX, -1), G[6 * MAX];
vector<bool> C(6 * MAX);
stack<int> S;
vector<L> V;
vector<pii> p;
int N, id, scn;
int ccw(pii& p1, pii& p2, pii& p3) {
	int s = p1.first * p2.second + p2.first * p3.second + p3.first * p1.second;
	s -= (p1.second * p2.first + p2.second * p3.first + p3.second * p1.first);
	if (s > 0) return 1;
	else if (s == 0) return 0;
	else return -1;
}

bool iscross(L& L1, L& L2) {
	int x = ccw(L1.s, L1.f, L2.s) * ccw(L1.s, L1.f, L2.f);
	int y = ccw(L2.s, L2.f, L1.s) * ccw(L2.s, L2.f, L1.f);
	if (x == 0 && y == 0) {
		if (L1.s > L1.f) swap(L1.s, L1.f);
		if (L2.s > L2.f) swap(L2.s, L2.f);
		return (L2.s <= L1.f && L1.s <= L2.f);
	}
	return (x <= 0 && y <= 0);
}

int dfs(int x) {
	P[x] = ++id;
	S.push(x);
	int parent = P[x];
	for (auto e : G[x]) {
		if (P[e] == 0) {
			parent = min(parent, dfs(e));
		}
		else if (!C[e]) {
			parent = min(parent, P[e]);
		}
	}
	if (parent == P[x]) {
		while (true) {
			int y = S.top();
			S.pop();
			C[y] = true;
			SCC[y] = scn;
			if (y == x) break;
		}
		scn++;
	}
	return parent;
}
int main() {
	cin >> N;
	V.resize(3 * N);
	for (int i = 0;i < 3 * N;++i) {
		cin >> V[i].s.first >> V[i].s.second >> V[i].f.first >> V[i].f.second;
	}
	for (int i = 0;i < N;++i) {
		G[6 * i + 1].push_back(6 * i + 2);
		G[6 * i + 1].push_back(6 * i + 4);
		G[6 * i + 3].push_back(6 * i);
		G[6 * i + 3].push_back(6 * i + 4);
		G[6 * i + 5].push_back(6 * i);
		G[6 * i + 5].push_back(6 * i + 2);
	}
	for (int i = 0;i < 3 * N;++i) {
		for (int j = i + 1;j < 3 * N;++j) {
			if (iscross(V[i], V[j])) {
				G[2 * i].push_back(2 * j + 1);
				G[2 * j].push_back(2 * i + 1);
			}
		}
	}
	for (int i = 0;i < 6 * N;++i) {
		if (!C[i]) dfs(i);
	}
	for (int i = 0;i < 3 * N;++i) {
		if (SCC[2 * i] == SCC[2 * i + 1]) {
			cout << -1;
			return 0;
		}
	}
	p.resize(6 * N);
	for (int i = 0;i < 6 * N;++i) {
		p[i] = { SCC[i],i };
	}
	sort(p.begin(), p.end());
	for (int i = 6 * N - 1;i >= 0;--i) {
		int n = p[i].second;
		if (ANS[n / 2] == -1) ANS[n / 2] = !(n % 2);
	}
	vector<int> ans;
	for (int i = 0;i <3* N;++i) {
		if (ANS[i]) ans.push_back(i+1);
	}
	cout << ans.size() << '\n';
	for (auto e : ans) {
		cout << e << " ";
	}
}