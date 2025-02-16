#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
int N, M, ans = 0x3f3f3f3f;
bool B[10];
vector<pair<string, int>> V;
int main()
{
	cin >> N >> M;
	for (int i = 0;i < M;++i) {
		int x;
		cin >> x;
		B[x] = true;
	}
	for (int i = 0;i <= 1000000;++i) {
		string s = to_string(i);
		bool err = false;
		for (auto c : s) {
			if (B[c - '0']) {
				err = true;
				break;
			}
		}
		if (err) continue;
		V.push_back({s,i});
	}
	ans = min(ans, abs(N - 100));
	for (auto e : V) {
		ans = min(ans, (int)e.first.size() + abs(e.second - N));
	}
	cout << ans;
}
