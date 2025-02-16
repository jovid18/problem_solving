#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <cmath>
using namespace std;

using ll = long double;

struct Point {
	ll x, y;
	bool operator< (const Point& a) {
		return y == a.y ? x < a.x : y < a.y;
	}
};
int N, T = 0;;
vector<Point> P, C;
ll ccw(const Point& a, const Point& b, const Point& c)
{
	return a.x * b.y + b.x * c.y + c.x * a.y - b.x * a.y - c.x * b.y - a.x * c.y;
}
ll dist(Point a, Point b)
{
	return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

bool comp(const Point& a, const Point& b) {
	ll c = ccw(P[0], a, b);
	if (c == 0) {
		return dist(P[0], a) < dist(P[0], b);
	}
	return c > 0;
}
stack<int> S;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << fixed;
	cout.precision(2);
	while (cin >> N) {
		if (N == 0)break;
		T++;
		P.resize(N);
		for (int i = 0;i < N;++i) {
			cin >> P[i].x >> P[i].y;
		}
		sort(P.begin(), P.end());
		sort(P.begin() + 1, P.end(), comp);
		S.push(0);
		S.push(1);
		int next = 2;
		while (next < N) {
			while (S.size() >= 2) {
				int first, second;
				second = S.top();
				S.pop();
				first = S.top();
				if (ccw(P[first], P[second], P[next]) > 0) {
					S.push(second);
					break;
				}
			}
			S.push(next++);
		}
		C.clear();
		while (!S.empty()) {
			C.push_back(P[S.top()]);
			S.pop();
		}
		ll ans = 1e9;
		for (int i = 0;i < C.size() - 1;++i) {
			ll subans = 0;
			for (int j = 0;j < C.size();++j) {
				subans = max(subans, abs(ccw(C[i], C[i + 1], C[j]) / sqrt(dist(C[i], C[i + 1]))));
			}
			ans = min(ans, subans);
		}
		ll subans = 0;
		for (int j = 0;j < C.size();++j) {
			subans = max(subans, abs(ccw(C[0], C[C.size() - 1], C[j]) / sqrt(dist(C[0], C[C.size() - 1]))));
		}
		ans = min(ans, subans);
		cout << "Case " << T << ": " << ans+ 0.004999999 << '\n';
	}
}