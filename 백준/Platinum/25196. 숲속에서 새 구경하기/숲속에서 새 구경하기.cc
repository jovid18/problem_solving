#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
ll K[3][3];
ll ans = 1LL << 50;
ll gcd(ll a, ll b) {
	if (b == 0) return a;
	else return gcd(b, a % b);
}
ll lcm(ll a, ll b) {
	return a * b / gcd(a, b);
}
ll achk(ll x) {
	x %= K[0][0];
	if (K[0][1] <= x && x <= K[0][2]) return true;
	return false;
}
ll bchk(ll x) {
	x %= K[1][0];
	if (K[1][1] <= x && x <= K[1][2]) return true;
	return false;
}
ll cchk(ll x) {
	x %= K[2][0];
	if (K[2][1] <= x && x <= K[2][2]) return true;
	return false;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	for (int i = 0;i < 3;++i) {
		for (int j = 0;j < 3;++j) {
			cin >> K[i][j];
		}
	}
	ll LCM = lcm(lcm(K[0][0], K[1][0]), K[2][0]);
	for (ll i = K[0][1];i <= LCM;i += K[0][0]) {
		if (bchk(i) && cchk(i)) ans = min(ans, i);
	}
	for (ll i = K[1][1];i <= LCM;i += K[1][0]) {
		if (achk(i) && cchk(i)) ans = min(ans, i);
	}
	for (ll i = K[2][1];i <= LCM;i += K[2][0]) {
		if (achk(i) && bchk(i)) ans = min(ans, i);
	}
	if (ans == (1LL << 50)) cout << -1;
	else cout << ans;
}