#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
using namespace std;
int N, C, M;
vector<int> D;
vector<int> L[10001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(0, 2e9);
	cin >> N >> C;
	D.resize(N+1);
	for (int i = 1;i <= N;++i) {
		cin >> D[i];
		if (L[D[i]].empty()) L[D[i]].push_back(-1);
		L[D[i]].push_back(i);
	}
	cin >> M;
	while (M--) {
		int a, b, ans = -1;
		cin >> a >> b;
		int count = 30;
		while (count--) {
			int randi = dis(gen) % (b - a + 1) + a;
			int randc = D[randi];
			int num = upper_bound(L[randc].begin(), L[randc].end(), b) - lower_bound(L[randc].begin(), L[randc].end(), a);
			if (num > (b - a + 1) / 2) {
				ans = randc;
				break;
			}
		}
		if (ans <= 0) cout << "no\n";
		else cout << "yes " << ans << '\n';
	}
}