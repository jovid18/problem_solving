#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int MAX = 1e5 + 1;
vector<int> G[MAX];
vector<pii> VQ;
unordered_map<ll, int> S;
int in[MAX], out[MAX], par[MAX];
int cnt[4 * MAX], seg[4 * MAX];
int N, Q, pv, ans;
ll hashing(ll a, ll b) {
	return a * 1e5 + b;
}
void dfs(int e, int p) {
	in[e] = ++pv;
	par[e] = p;
	for (int n : G[e]) {
		if (n == p) continue;
		dfs(n, e);
	}
	out[e] = pv;
}
void update(int s, int f, int n, int l, int r, int diff) {
	if (l > r) return;
	if (f < l || r < s) return;
	if (l <= s && f <= r) cnt[n] += diff;
	else {
		int m = (s + f) / 2;
		update(s, m, 2 * n, l, r, diff);
		update(m + 1, f, 2 * n + 1, l, r, diff);
	}
	if (cnt[n]) seg[n] = f - s + 1;
	else {
		if (s == f) seg[n] = 0;
		else seg[n] = seg[2 * n] + seg[2 * n + 1];
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 1;i < N;++i) {
		int a, b;
		char x, y;
		cin >> a >> x >> y >> b;
		G[a].push_back(b);
		G[b].push_back(a);
		S[hashing(a, b)] = 0;
		S[hashing(b, a)] = 0;
		if (x == '-' && y == '-') {
		}
		else if (x == '-' && y == '>') {
			VQ.push_back({ a,b });
		}
		else if (x == '<' && y == '-') {
			VQ.push_back({ b,a });
		}
	}
	dfs(1, 0);
	for (pii e : VQ) {
		S[hashing(e.first, e.second)] = 1;
		S[hashing(e.second, e.first)] = -1;
		if (par[e.second] == e.first) {
			update(1, N, 1, in[e.second], out[e.second], 1);
		}
		else {
			update(1, N, 1, 1, in[e.first] - 1, 1);
			update(1, N, 1, out[e.first] + 1, N, 1);
		}
	}
	cin >> Q;
	while (Q--) {
		int a, b;
		char x, y;
		cin >> a >> x >> y >> b;
		if (S[hashing(b, a)] == 1) {
			if (par[a] == b) {
				update(1, N, 1, in[a], out[a], -1);
			}
			else {
				update(1, N, 1, 1, in[b] - 1, -1);
				update(1, N, 1, out[b] + 1, N, -1);
			}
		}
		else if (S[hashing(a, b)] == 1) {
			if (par[b] == a) {
				update(1, N, 1, in[b], out[b], -1);
			}
			else {
				update(1, N, 1, 1, in[a] - 1, -1);
				update(1, N, 1, out[a] + 1, N, -1);
			}
		}
		S[hashing(a, b)] = 0;
		S[hashing(b, a)] = 0;
		if (x == '-' && y == '-') {

		}
		else if (x == '-' && y == '>') {
			S[hashing(a, b)] = 1;
			S[hashing(b, a)] = -1;
			if (par[b] == a) {
				update(1, N, 1, in[b], out[b], 1);
			}
			else {
				update(1, N, 1, 1, in[a] - 1, 1);
				update(1, N, 1, out[a] + 1, N, 1);
			}
		}
		else if (x == '<' && y == '-') {
			S[hashing(b, a)] = 1;
			S[hashing(a, b)] = -1;
			if (par[a] == b) {
				update(1, N, 1, in[a], out[a], 1);
			}
			else {
				update(1, N, 1, 1, in[b] - 1, 1);
				update(1, N, 1, out[b] + 1, N, 1);
			}
		}
		cout << N - seg[1] << '\n';
	}

}