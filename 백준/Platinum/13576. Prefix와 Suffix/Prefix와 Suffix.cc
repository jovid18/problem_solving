#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
using pii = pair<int, int>;
vector<pii> ans;
vector<int> z, zcopy;
string s;
int N;
void get_z(void) {
	int l = 0, r = 0;
	for (int i = 1;i < N;++i) {
		if (i <= r) z[i] = min(r - i + 1, z[i - l]);
		while (i + z[i] < N && s[i + z[i]] == s[z[i]]) z[i]++;
		if (r < i + z[i] - 1) r = i + z[i] - 1, l = i;
	}
	z[0] = N;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> s;
	N = s.size();
	z.assign(N, 0);
	get_z();
	zcopy = z;
	sort(zcopy.begin(), zcopy.end());
	for (int i = 0;i < N;++i) {
		if (i + z[i] == N)
			ans.push_back({ z[i],zcopy.end() - lower_bound(zcopy.begin(),zcopy.end(),z[i]) });
	}
	sort(ans.begin(), ans.end());
	cout << ans.size() << '\n';
	for (auto e : ans) {
		cout << e.first << " " << e.second << '\n';
	}
}