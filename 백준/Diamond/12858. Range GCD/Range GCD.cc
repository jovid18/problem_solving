#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;
const int MAX = 100001;
using ll = long long;
ll GCD(ll a, ll b) {
	if (a == 0) return b;
	if (b == 0) return a;
	return gcd(a, b);
}
int N, Q;
struct LazySeg {
	ll T[4 * MAX];
	ll L[4 * MAX];
	void update_L(int s, int f, int n) {
		if (L[n] != 0) {
			T[n] += L[n] * (f - s + 1);
			if (s != f) {
				L[2 * n] += L[n];
				L[2 * n + 1] += L[n];
			}
			L[n] = 0;
		}
	}
	void update(int s, int f, int n, int l, int r, ll diff) {
		update_L(s, f, n);
		if (f < l || r < s) return;
		if (l <= s && f <= r) {
			T[n] += (f - s + 1) * diff;
			if (s != f) {
				L[2 * n] += diff;
				L[2 * n + 1] += diff;
			}
			return;
		}
		int m = (s + f) / 2;
		update(s, m, 2 * n, l, r, diff);
		update(m + 1, f, 2 * n + 1, l, r, diff);
		T[n] = T[2 * n] + T[2 * n + 1];
	}
	ll query(int s, int f, int n, int x) {
		update_L(s, f, n);
		if (f < x || x < s) return 0;
		if (x <= s && f <= x) {
			return T[n];
		}
		int m = (s + f) / 2;
		return query(s, m, 2 * n, x) + query(m + 1, f, 2 * n + 1, x);
	}
}LS;
struct Seg {
	ll T[4 * MAX];
	void update(int s, int f, int n, int l, int r, ll v) {
		if (f < l || r < s) return;
		if (l <= s && f <= r) {
			T[n] = v;
			return;
		}
		int m = (s + f) / 2;
		update(s, m, 2 * n, l, r, v);
		update(m + 1, f, 2 * n + 1, l, r, v);
		T[n] = GCD(T[2 * n], T[2 * n + 1]);
	}
	ll query(int s, int f, int n, int x) {
		if (f < x || x < s) return 0;
		if (x <= s && f <= x) return T[n];
		int m = (s + f) / 2;
		return GCD(query(s, m, 2 * n, x), query(m + 1, f, 2 * n + 1, x));
	}
	ll query(int s, int f, int n, int l, int r) {
		if (f < l || r < s) return 0;
		if (l <= s && f <= r) return T[n];
		int m = (s + f) / 2;
		return GCD(query(s, m, 2 * n, l, r), query(m + 1, f, 2 * n + 1, l, r));
	}
}S;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 1;i <= N;++i) {
		ll x;
		cin >> x;
		LS.update(1, N, 1, i, i, x);
	}
	for (int i = 1;i < N;++i) {
		ll now = LS.query(1, N, 1, i) - LS.query(1, N, 1, i + 1);
		S.update(1, N, 1, i, i, abs(now));
	}
	cin >> Q;
	while (Q--) {
		int t, a, b;
		cin >> t >> a >> b;
		if (t == 0) {
			ll now = S.query(1, N, 1, a, b - 1);
			now = GCD(now, LS.query(1, N, 1, a));
			cout << now << '\n';
		}
		else {
			LS.update(1, N, 1, a, b, t);
			ll now = LS.query(1, N, 1, a - 1) - LS.query(1, N, 1, a);
			S.update(1, N, 1, a - 1, a - 1, abs(now));
			now = LS.query(1, N, 1, b) - LS.query(1, N, 1, b + 1);
			S.update(1, N, 1, b, b, abs(now));
		}
	}
}
