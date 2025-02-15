#include <iostream>
#include <stack>
#include <iomanip>
#include <vector>
using namespace std;
using ld = long double;
using pll = pair<ld, ld>;
int N;
stack<pll> S;
vector<pll> V;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	cout << fixed << setprecision(3);
	V.resize(N);
	for (int i = 0;i < N;++i) {
		cin >> V[i].first >> V[i].second;
	}
	for (int j = 0;j < N;++j) {
		ld xj = V[j].first;
		ld rj = V[j].second;
		while (!S.empty()) {
			ld xi = S.top().first;
			ld ri = S.top().second;
			ld xd = xi - xj;
			rj = min(rj, xd * xd / (4 * ri));
			if (S.top().second <= rj) S.pop();
			else break;
		}
		cout << rj << '\n';
		S.push({ xj,rj });
	}
}
