#include <iostream>
#include <vector>
using namespace std;
const int MAX = 101;
const int INF = 1e9;
int N, M;
int adj[MAX][MAX];
int dist[MAX][MAX];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0;i < M;++i) {
		int a, b;
		cin >> a >> b;
		adj[a][b] = 1;
		adj[b][a] = 1;
	}
	for (int i = 1;i <= N;++i) {
		for (int j = 1;j <= N;++j) {
			if (i == j) dist[i][j] = 0;
			else if (adj[i][j]) dist[i][j] = adj[i][j];
			else dist[i][j] = INF;
		}
	}
	for (int k = 1;k <= N;++k) {
		for (int i = 1;i <= N;++i) {
			for (int j = 1;j <= N;++j) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
	int tot = INF, ans = 0;
	for (int i = 1;i <= N;++i) {
		int sum = 0;
		for (int j = 1;j <= N;++j) {

			sum += dist[i][j];
		}
		if (tot > sum) {
			tot = sum;
			ans = i;
		}
	}
	cout << ans;
}
