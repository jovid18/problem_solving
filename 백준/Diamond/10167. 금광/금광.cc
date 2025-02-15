//본코드는 https://m.blog.naver.com/PostView.naver?isHttpsRedirect=true&blogId=edenooo&logNo=221415337560의 게시물을 공부하고 작성한 코드임을 명시합니다.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
const int MAX = 3001;
ll W[MAX][MAX];
struct Point {
	ll x, y, w;
};
struct DNC {
	ll sum, lmax, rmax, tmax;
};
DNC seg[4 * MAX];
DNC update(int i, ll v, int n, int l, int r) {
	if (r < i || i < l) return seg[n];
	if (l == i && i == r) {
		seg[n].sum += v;
		seg[n].lmax += v;
		seg[n].rmax += v;
		seg[n].tmax += v;
		return seg[n];
	}
	int m = (l + r) / 2;
	DNC L = update(i, v, 2 * n, l, m);
	DNC R = update(i, v, 2 * n + 1, m + 1, r);
	seg[n].sum = L.sum + R.sum;
	seg[n].lmax = max(L.lmax, L.sum + R.lmax);
	seg[n].rmax = max(R.rmax, R.sum + L.rmax);
	seg[n].tmax = max({ L.tmax, R.tmax,L.rmax + R.lmax });
	return seg[n];
}
vector<Point> V;
vector<ll> X, Y;
vector<pll> byY[MAX];
int N;
int main() {
	cin >> N;
	V.resize(N);
	for (int i = 0;i < N;++i) {
		cin >> V[i].x >> V[i].y >> V[i].w;
		X.push_back(V[i].x);
		Y.push_back(V[i].y);
	}
	sort(X.begin(), X.end());
	sort(Y.begin(), Y.end());
	X.erase(unique(X.begin(), X.end()), X.end());
	Y.erase(unique(Y.begin(), Y.end()), Y.end());
	for (auto& e : V) {
		e.x = lower_bound(X.begin(), X.end(), e.x) - X.begin();
		e.y = lower_bound(Y.begin(), Y.end(), e.y) - Y.begin();
	}
	for (auto e : V) {
		W[e.x][e.y] = e.w;
		byY[e.y].push_back({ e.x, e.w });
	}
	ll ans = 0;
	for (int u = 0; u < N; ++u) {
		for (int i = 0;i < 4 * MAX;++i) {
			seg[i].sum = 0;
			seg[i].lmax = 0;
			seg[i].rmax = 0;
			seg[i].tmax = 0;
		}
		for (int d = u;d < N;++d) {
			for (auto e : byY[d]) {
				int x = e.first, w = e.second;
				update(x, w, 1, 0, N - 1);
			}
			ans = max(ans, seg[1].tmax);
		}
	}
	cout << ans;
}
