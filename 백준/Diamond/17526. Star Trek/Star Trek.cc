//convex-hull 구현 코드는 https://github.com/kth-competitive-programming/kactl/blob/main/content/data-structures/LineContainer.h에서 인용했음을 밝힙니다.
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <climits>
using namespace std;
using ll = long long;
const int MAX = 100001;
int N;
ll S[MAX], T[MAX], P[MAX], DP[MAX];
ll B(int i) {
	return T[i] - P[i] * S[i];
}
struct Line {
	mutable ll k, m, p;
	bool operator<(const Line& o) const { return k < o.k; }
	bool operator<(ll x) const { return p < x; }
};
struct LineContainer : multiset<Line, less<>> {
	static const ll inf = LLONG_MAX;
	ll div(ll a, ll b) {
		return a / b - ((a ^ b) < 0 && a % b);
	}
	bool isect(iterator x, iterator y) {
		if (y == end()) return x->p = inf, 0;
		if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
		else x->p = div(y->m - x->m, x->k - y->k);
		return x->p >= y->p;
	}
	void add(ll k, ll m) {
		auto z = insert({ k, m, 0 }), y = z++, x = y;
		while (isect(y, z)) z = erase(z);
		if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
		while ((y = x) != begin() && (--x)->p >= y->p) isect(x, erase(y));
	}
	ll query(ll x) {
		auto l = *lower_bound(x);
		return l.k * x + l.m;
	}
};
LineContainer LC;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 1;i < N;++i) {
		cin >> S[i];
		S[i] += S[i - 1];
	}
	for (int i = 0;i < N - 1;++i) {
		cin >> T[i] >> P[i];
	}
	LC.add(-P[0], -B(0));
	for (int i = 1;i < N;++i) {
		DP[i] = -LC.query(S[i]);
		LC.add(-P[i], -DP[i] - B(i));
	}
	cout << DP[N - 1];
}
