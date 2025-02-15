#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;
vector<int> B, DP1, DP2;
int INF = 1e9;
int rvs(int i) {
	for (int j = 0;j < N;++j) {
		i ^= (1 << j);
	}
	return i;
}
int cnt(int i) {
	int count = 0;
	for (int j = 0;j < N;++j) {
		if(i&(1<<j)) count++;
	}
	return count;
}
int main() {
	cin >> N;
	B.resize(N);
	for (int i = 0;i < N;++i) {
		cin >> B[i];
	}
	if (N == 1) {
		cout << B[0];
		return 0;
	}
	sort(B.begin(), B.end());
	if (N == 2) {
		if (B[0] == B[1]) cout << -1;
		else cout << B[1];
		return 0;
	}
	DP1.assign(1 << N, INF);
	DP2.assign(1 << N, INF);
	DP1[(1 << N) - 1] = 0;
	for (int t = N - 1;t >= 1;--t) {
		for (int i = 0;i < (1 << N);++i) {
			if (DP1[i] == INF) continue;
			if (cnt(i) != t + 1) continue;
			for (int j = 0;j < N;++j) {
				if (!(i & (1 << j))) continue;
				for (int k = j + 1;k < N;++k) {
					if (!(i & (1 << k))) continue;
					if (B[j] == B[k]) continue;
					int mask = rvs(i);
					mask |= (1 << j);
					mask |= (1 << k);
					DP2[mask] = min(DP2[mask], DP1[i] + B[k]);
				}
			}
		}
		if (t == 1) break;
		for (int i = 0;i < (1 << N);++i) {
			if (DP2[i] == INF) continue;
			if (cnt(i) != N-t+1) continue;
			for (int j = 0;j < N;++j) {
				if (!(i & (1 << j))) continue;
				int mask = rvs(i);
				mask |= (1 << j);
				DP1[mask] = min(DP1[mask], DP2[i] + B[j]);
			}
		}
	}
	if (DP2[(1 << N) - 1] == INF) cout << -1;
	else cout << DP2[(1 << N) - 1];
}