#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
int T;
ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}
ll lcm(ll a, ll b) {
	return (a * b / gcd(a, b));
}
ll M, N, X, Y;
int main()
{
	cin >> T;
	while (T--) {
		cin >> M >> N >> X >> Y;
		ll ans = -1;
		ll MAX = lcm(M, N);
		for (ll i = X;i <= MAX;i += M) {
			int subY = i % N;
			if (subY == 0) subY += N;
			if (subY == Y) {
				ans = i;
				break;
			}
		}
		cout << ans << '\n';
	}
}
