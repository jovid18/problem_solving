#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
using ll = long long;
ll W, n;
ll S[500001];
int DP[500002];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> W >> n;
	ll lo = -1, hi = W - 1;
	for (int i = 1;i <= n;++i) {
		cin >> S[i];
		S[i] += S[i - 1];
	}
	while (lo + 1 < hi) {
		memset(DP, 0, sizeof(DP));
		ll mid = (lo + hi) / 2;
		int l = 0, r = 0;
		vector<pair<ll, ll>> lr;
		lr.resize(n + 1);
		for (int i = 1;i <= n;++i) {
			while (S[i] - S[l] > W) l++;
			while (S[i] - S[r] >= W - mid) r++;
			lr[i] = { l + 1,r };
		}
		DP[1] = 1;
		for (int i = 1;i <= n;++i) {
			if (lr[i].first <= lr[i].second && DP[lr[i].second] - DP[lr[i].first - 1] > 0) DP[i + 1] = 1;
			DP[i + 1] += DP[i];
		}
		if (DP[n + 1] - DP[n]) hi = mid;
		else lo = mid;
	}
	cout << hi * hi;
}