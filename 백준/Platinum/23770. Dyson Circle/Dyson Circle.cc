#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
template <class T>
struct Point
{
	typedef Point P;
	explicit Point(T x = 0, T y = 0) : x(x), y(y) {}
	T x, y;
	T cross(P p) const { return x * p.y - y * p.x; }
	T cross(P a, P b) const { return (a - *this).cross(b - *this); }
	bool operator==(P p) const { return tie(x, y) == tie(p.x, p.y); }
	bool operator<(P p) const { return tie(x, y) < tie(p.x, p.y); }
	P operator-(P p) const { return P(x - p.x, y - p.y); }
};
typedef Point<ll> P;
vector<P> convexHull(vector<P> pts)
{
	if (pts.size() <= 1)
		return pts;
	sort(pts.begin(), pts.end());
	vector<P> h(pts.size() + 1);
	int s = 0, t = 0;
	for (int it = 2; it--; s = --t, reverse(pts.begin(), pts.end()))
		for (P p : pts)
		{
			while (t >= s + 2 && h[t - 2].cross(h[t - 1], p) <= 0) t--;
			h[t++] = p;
		}
	return { h.begin(), h.begin() + t - (t == 2 && h[0] == h[1]) };
}
int N, ans;
vector<P> V;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	V.resize(N);
	ll xmax = -1e7, ymax = -1e7, xmin = 1e7, ymin = 1e7;
	bool isLine = true;
	for (int i = 0; i < N; ++i)
	{
		cin >> V[i].x >> V[i].y;
		xmax = max(xmax, V[i].x);
		xmin = min(xmin, V[i].x);
		ymax = max(ymax, V[i].y);
		ymin = min(ymin, V[i].y);
		if (isLine && i >= 2)
		{
			int x1 = V[i - 2].x, x2 = V[i - 1].x, x3 = V[i].x, y1 = V[i - 2].y, y2 = V[i - 1].y, y3 = V[i].y;
			if ((y1 - y2) * (x2 - x3) == (y2 - y3) * (x1 - x2)) continue;
			isLine = false;
		}
	}
	if (N == 1){
		cout << 4;
		return 0;
	}
	if (isLine){
		if (xmax - xmin > ymax - ymin) ans += 2 * (xmax - xmin + 1) + 2;
		else if (xmax - xmin == ymax - ymin)  ans += 2 * (xmax - xmin + 1) + 3;
		else ans += 2 * (ymax - ymin + 1) + 2;
		cout << ans;
	}else{
		
		auto CV = convexHull(V);
        for (auto e :CV){
			if (e.x == xmax)ans++;
			if (e.x == xmin)ans++;
			if (e.y == ymax)ans++;
			if (e.y == ymin)ans++;
		}
		for (int i = 0; i + 1 < CV.size(); ++i)
		{
			auto bef = CV[i];
			auto aft = CV[i + 1];
			if (bef.x == aft.x) ans += abs(bef.y - aft.y) - 1;
			else if (bef.y == aft.y) ans += abs(bef.x - aft.x) - 1;
			else ans += max(abs(bef.x - aft.x), abs(bef.y - aft.y));
		}
		auto bef = CV.front();
		auto aft = CV.back();
		if (bef.x == aft.x)ans += abs(bef.y - aft.y) - 1;
		else if (bef.y == aft.y)	ans += abs(bef.x - aft.x) - 1;
		else ans += max(abs(bef.x - aft.x), abs(bef.y - aft.y));
		cout << ans;
	} 
}