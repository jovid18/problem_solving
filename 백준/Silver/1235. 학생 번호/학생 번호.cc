#include <iostream>
#include <string>
#include <vector>
using namespace std;
int N;
vector<string> S;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	S.resize(N);
	for (int i = 0;i < N;++i) {
		cin >> S[i];
	}
	int ans = 1;
	int siz = S[0].length();
	for (int i = 0;i < N;++i) {
		for (int j = i + 1;j < N;++j) {
			for (int k = siz - 1;k >= 0;--k) {
				if (S[i][k] == S[j][k]) {
					continue;
				}
				else {
					ans = max(ans, siz - k);
					break;
				}
			}
		}
	}
	cout << ans;
}
