#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
int N; 
ll M;
vector<int> V;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	V.resize(N);
	for (auto& e : V) {
		cin >> e;
	}
	ll s = -1,f = 2e9 + 1;
	while (s + 1 < f) {
		ll m = (s + f) / 2;
		ll sum = 0;
		for (auto e : V) sum += max((ll)0, e - m);
		if (sum >= M) s = m;
		else f = m;
	}
	cout << s;
}
