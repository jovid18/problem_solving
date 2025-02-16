#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
int K, N;
vector<ll> L;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> K >> N;
	L.resize(K);
	for (int i = 0;i < K;++i) {
		cin >> L[i];
	}
	ll s = 1;
	ll e = *max_element(L.begin(), L.end())+1;
	while (s + 1 < e) {
		ll m = (s + e) / 2;
		ll sum = 0;
		for (auto e : L) sum += e / m;
		if (sum >= N) s = m;
		else e = m;
	}
	cout << s;
}
