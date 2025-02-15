#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using pii = pair<int, int>;
int N;
vector<pii> V;
vector<int> L[100001];
int DP[100001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	V.resize(N);
	for (int i = 0;i < N;++i) {
		cin >> V[i].first;
		V[i].second = i + 1;
	}
	sort(V.begin(), V.end());
	L[1].push_back(V[0].second);
	int idx = 1;
	for (int i = 1;i < N;++i) {
		if (V[i - 1].first != V[i].first) idx++;
		L[idx].push_back(V[i].second);
	}
	N = idx;
	int ans = 0;
	for(int i=2;i<=N;++i){
		int idx=0;
		for(int j=0;j<L[i].size();++j){
			int idx=lower_bound(L[i-1].begin(),L[i-1].end(),L[i][j])-L[i-1].begin();
			ans=max(ans,idx+(int)L[i].size()-j);
		}
	}
	for (int i = 1;i <= N;++i) {
		if (i == 1) {
			DP[i] = L[i].size();
			ans = max(ans, DP[i]);
			continue;
		}
		int ls = L[i - 1][0], lf = L[i - 1][L[i - 1].size() - 1], rs = L[i][0], rf = L[i][L[i].size() - 1];
		if (lf < rs) DP[i] = DP[i - 1] + L[i].size();
		else if (rs < ls)	DP[i] = L[i].size();
		else DP[i] = L[i].size() + (lower_bound(L[i - 1].begin(), L[i - 1].end(), rs) - L[i - 1].begin());
		ans = max(ans, DP[i]);
		if (lf < rf) ans = max(ans, DP[i - 1] + (int)L[i].size() - (int)(lower_bound(L[i].begin(), L[i].end(), lf) - L[i].begin()));
	}
	cout << V.size() - ans;
}