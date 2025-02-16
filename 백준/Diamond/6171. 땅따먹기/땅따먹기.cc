#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
const int MAX = 50001;
ll DP[MAX];
int N;
vector<pll> V, WH;
struct L {
	ll a, b;
	double c_x;
	L(ll av, ll bv, double cv = 0) :a(av), b(bv), c_x(cv) {}
};
double cross(const L& L1, const L& L2) {
	return (L2.b - L1.b) / (L1.a - L2.a);
}
int BS(vector<L>& LS, ll value) {
	int low = 0, high = LS.size() - 1, pos = 0;
	while (low <= high) {
		int mid = (low + high) / 2;
		if (LS[mid].c_x < value) {
			pos = mid;
			low = mid + 1;
		}
		else high = mid - 1;
	}
	return pos;
}
vector<L> LS;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	V.resize(N);
	for (int i = 0;i < N;++i) {
		cin >> V[i].first >> V[i].second;
	}
	sort(V.begin(), V.end());
	ll PM = V.back().second;
	WH.push_back(V.back());
	for (int i = N - 2; i >= 0; --i) {
		if (V[i].second > PM) {
			WH.push_back(V[i]);
			PM = V[i].second;
		}
	}
	reverse(WH.begin(), WH.end());
	N = WH.size();
	DP[0] = 0;
	for (int i = 1;i <= N;++i) {
		L now(WH[i-1].second, DP[i - 1]);
		while (LS.size() >= 1) {
			now.c_x = cross(now, LS.back());
			if (now.c_x <= LS.back().c_x) { LS.pop_back(); }
			else break;
		}
		LS.push_back(now);
		int index = BS(LS, WH[i-1].first);
		DP[i] = LS[index].a * WH[i-1].first + LS[index].b;
	}
	cout << DP[N];
}