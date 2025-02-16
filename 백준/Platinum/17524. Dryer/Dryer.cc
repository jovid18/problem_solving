#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using pii = pair<int, int>;
int n, k, ans1, ans2 = 0x3f3f3f3f, ans3 = 0x3f3f3f3f, ans21, ans22, ans31, ans32, ans33, T1 = 0, T2 = -1, T3 = -1;
vector<pii> V, C;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> k;
	V.resize(n);
	for (int i = 0;i < n;++i) {
		cin >> V[i].first >> V[i].second;
	}
	sort(V.begin(), V.end());
	for (int i = 0;i < n - 1;++i) {
		if (V[i].first == V[i + 1].first) {
			continue;
		}
		else {
			C.push_back(V[i]);
		}
	}
	C.push_back(V.back());
	if (k >= 1) {
		T1 = C[0].first;
		for (auto e : C) {
			ans1 = max(ans1, (e.first - T1) * e.second);
		}
		ans1 += 30;
	}
	if (k >= 2) {
		T1 = C[0].first;
		for (int i = 1;i < C.size();++i) {
			ans21 = 0;
			ans22 = 0;
			T2 = C[i].first;
			for (auto e : C) {
				if (e.first < T2) {
					ans21 = max(ans21, (e.first - T1) * e.second);
				}
				else {
					if ((e.first - T1) * e.second <= ans21) continue;
					else ans22 = max(ans22, (e.first - T2) * e.second);
				}
			}
			ans2 = min(ans2, ans21 + ans22);
		}
		ans2 += 60;
	}
	if (k >= 3) {
		T1 = C[0].first;
		for (int i = 1;i < C.size();++i) {
			for (int j = i + 1;j < C.size();++j) {
				ans31 = 0;
				ans32 = 0;
				ans33 = 0;
				T2 = C[i].first;
				T3 = C[j].first;
				for (auto e : C) {
					if (e.first < T2) {
						ans31 = max(ans31, (e.first - T1) * e.second);
					}
					else if (e.first < T3) {
						if ((e.first - T1) * e.second <= ans31) continue;
						else ans32 = max(ans32, (e.first - T2) * e.second);
					}
					else {
						if ((e.first - T1) * e.second <= ans31) continue;
						if ((e.first - T2) * e.second <= ans32) continue;
						else ans33 = max(ans33, (e.first - T3) * e.second);
					}
				}
				ans3 = min(ans3, ans31 + ans32 + ans33);
			}
		}
		ans3 += 90;
	}
	cout << min({ ans1, ans2, ans3 });
}
