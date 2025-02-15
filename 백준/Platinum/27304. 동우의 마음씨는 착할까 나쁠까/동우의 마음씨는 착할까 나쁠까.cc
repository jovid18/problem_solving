#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
const int MAX = 500001;
int N;
vector<pair<int, ll>> G[MAX];
int cnt[MAX];
ll sum[MAX];
ll ans[MAX];
void dfs1(int n, int p = 0) {
	int siz = 1;
	ll wgt = 0;
	for (auto e : G[n]) {
		if (e.first == p) continue;
		dfs1(e.first, n);
		siz += cnt[e.first];
		wgt += sum[e.first] + e.second * cnt[e.first];
	}
	cnt[n] = siz;
	sum[n] = wgt;
}
void dfs2(int n, int p = 0) {
	for (auto e : G[n]) {
		if (e.first == p) continue;
		ans[e.first] = ans[n] + e.second * (N - 2 * cnt[e.first]);
		dfs2(e.first, n);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 0;i < N - 1;++i) {
		int a, b, c;
		cin >> a >> b >> c;
		G[a].push_back({ b,c });
		G[b].push_back({ a,c });
	}
	dfs1(1);
	ans[1] = sum[1];
	dfs2(1);
	ll Min = 1LL << 60;
	ll Max = -Min;
	for (int i = 1;i <= N;++i) {
		Min = min(Min, ans[i]);
		Max = max(Max, ans[i]);
	}
	cout << Min << " " << Max;
}