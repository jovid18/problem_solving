#include <iostream>
#include <cstring>
using namespace std;
int N;
int DP[2001];
bool visited[102];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	DP[0] = 0;
	DP[1] = 1;
	DP[2] = 1;
	DP[3] = 1;
	int maxg = 0;
	for (int i = 4;i <= 2000;++i) {
		memset(visited, 0, sizeof(visited));
		for (int j = 0;j <= (i -1) / 2;++j) {
			int grundynum = DP[i - j - 3] ^ (j >= 3 ? DP[j - 2] : 0);
			visited[grundynum] = true;
		}
		for (int j = 0;j <= 101;++j) {
			if (!visited[j]) {
				DP[i] = j;
				break;
			}
		}
	}
	cin >> N;
	cout << (DP[N] ? 1 : 2);
}