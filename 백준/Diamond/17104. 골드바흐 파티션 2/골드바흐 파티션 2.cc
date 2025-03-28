#include <complex>
#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;
using cpx = complex<double>;
using vec = vector<cpx>;
const double PI = acos(-1);
const int MAX = 1e6 + 1;
bool prime[MAX];
vector<int> P, N;
vec v(MAX / 2 + 1), u(MAX / 2 + 1);
int T, S = MAX;
void seive() {
	prime[0] = prime[1] = true;
	for (int i = 2; i < sqrt(MAX); i++) {
		if (prime[i] == false) {
			for (int j = 2 * i; j <= MAX; j += i) {
				prime[j] = true;
			}
		}
	}
}
void FFT(vec& v, bool inv) {
	int n = v.size();
	for (int i = 1, j = 0;i < n;++i) {
		int bit = n / 2;
		while (j >= bit) {
			j -= bit;
			bit /= 2;
		}
		j += bit;
		if (i < j) swap(v[i], v[j]);
	}
	for (int k = 1;k < n;k *= 2) {
		double angle = (inv ? PI / k : -PI / k);
		cpx w(cos(angle), sin(angle));
		for (int i = 0;i < n;i += 2 * k) {
			cpx z(1, 0);
			for (int j = 0;j < k;++j) {
				cpx even = v[i + j];
				cpx odd = v[i + j + k];
				v[i + j] = even + z * odd;
				v[i + j + k] = even - z * odd;
				z *= w;
			}
		}
	}
	if (inv) for (int i = 0;i < n;++i) v[i] /= n;
}
vector<int> mul(vec& v, vec& u) {
	int n = 2;
	while (n < v.size() + u.size()) n *= 2;
	v.resize(n);
	FFT(v, false);
	u.resize(n);
	FFT(u, false);
	for (int i = 0;i < n;++i) v[i] *= u[i];
	FFT(v, true);
	vector<int> w(v.size());
	for (int i = 0;i < S;++i) w[i] = round(v[i].real());
	return w;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	seive();
	for (int i = 3;i <= MAX - 1;++i) {
		if (!prime[i]) P.push_back((i - 1) / 2);
	}
	for (auto p : P) {
		v[p] = cpx(1, 0);
		u[p] = cpx(1, 0);
	}
	vector<int> ans = mul(v, u);
	cin >> T;
	int x;
	while (T--) {
		cin >> x;
		if (x == 4) cout << 1 << '\n';
		else {
			int y = (x - 2) / 2;
			if (!prime[x / 2]) cout << 1 + (ans[y] - 1) / 2 << '\n';
			else cout << ans[y] / 2 << '\n';
		}
	}
}
