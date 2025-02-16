#include <iostream>
#include <vector>
using namespace std;
int N, M, B;
vector<int> H;
pair<int, int> ans;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M >> B;
	H.resize(N * M);
	for (int i = 0;i < N * M;++i) {
		cin >> H[i];
	}
	ans = { 1e9,-1 };
	for (int h = 0;h <= 256;++h) {
		int u = 0, o = 0;
		for (auto e : H) {
			if (e < h) u += h - e;
			else if (e > h) o += e - h;
		}
		if (o + B >= u) {
			if (ans.first >= 2 * o + u) {
				ans = { 2 * o + u, h };
			}
		}
	}
	cout << ans.first << " " << ans.second;
}