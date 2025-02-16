#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
using pii = pair<int, int>;
int N, M, ans = 1e9;
vector<int> G[101];
queue<pii> q;
bool visited[101];
bool nodice[101];
int main()
{
	for (int i = 1;i <= 100;++i) {
		for (int j = 1;j <= 6;++j) {
			if (i + j > 100) break;
			G[i].push_back(i + j);
		}
	}
	cin >> N >> M;
	for (int i = 0;i < N + M;++i) {
		int a, b;
		cin >> a >> b;
		G[a].clear();
		G[a].push_back(b);
		nodice[a] = true;
	}
	q.push({ 1,0 });
	visited[1] = true;
	while (!q.empty()) {
		int now = q.front().first;
		int nth = q.front().second;
		q.pop();
		if (now == 100) {
			ans = min(ans, nth);
			break;
		}
		for (auto e : G[now]) {
			if (visited[e]) continue;
			visited[e] = true;
			if (nodice[e]) q.push({ G[e][0],nth + 1 });
			else q.push({ e,nth + 1 });
		}
	}
	cout << ans;
}
