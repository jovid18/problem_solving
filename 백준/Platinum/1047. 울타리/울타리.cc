#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
int N;
struct T {
	int x, y, w, idx;
};
vector<T> V;
bool byx(const T& a, const T& b) {
	if (a.x == b.x) return a.y < b.y;
	return a.x < b.x;
}
bool byy(const T& a, const T& b) {
	if (a.y == b.y) return a.x < b.x;
	return a.y < b.y;
}
bool byw(const T& a, const T& b) {
	return a.w > b.w;
}
bool byidx(const T& a, const T& b) {
	return a.idx < b.idx;
}
int minx, maxx, miny, maxy;
int In(int x, int y) {
	if (minx < x && x < maxx && miny < y && y < maxy) return -1;
	else if (x < minx || maxx < x || y < miny || maxy < y) return 1;
	else return 0;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	V.resize(N);
	for (int i = 0;i < N;++i) {
		auto& e = V[i];
		cin >> e.x >> e.y >> e.w;
		e.idx = i;
	}
	int ans = 50;
	for (int idx1 = 0;idx1 < N;++idx1) {
		for (int idx2 = idx1;idx2 < N;++idx2) {
			for (int idx3 = idx2;idx3 < N;++idx3) {
				for (int idx4 = idx3;idx4 < N;++idx4) {
					minx = min({ V[idx1].x,V[idx2].x ,V[idx3].x ,V[idx4].x });
					maxx = max({ V[idx1].x,V[idx2].x ,V[idx3].x ,V[idx4].x });
					miny = min({ V[idx1].y,V[idx2].y ,V[idx3].y ,V[idx4].y });
					maxy = max({ V[idx1].y,V[idx2].y ,V[idx3].y ,V[idx4].y });
					vector<T> in, out;
					for (int i = 0;i < N;++i) {
						int chk = In(V[i].x, V[i].y);
						if (chk == -1) in.push_back(V[i]);
						else if (chk == 0) continue;
						else out.push_back(V[i]);
					}
					int need = 2 * (maxx - minx + maxy - miny);
					int cutn = 0;
					int rest = 0;
					for (auto e : out) {
						rest += e.w;
					}
					cutn += out.size();
					if (rest >= need) {
						ans = min(ans, cutn);
						continue;
					}
					sort(in.begin(), in.end(), byw);
					for (auto e : in) {
						rest += e.w;
						cutn++;
						if (rest >= need) break;
					}
					if (rest >= need) ans = min(ans, cutn);

				}
			}
		}
	}
	cout << ans;
}