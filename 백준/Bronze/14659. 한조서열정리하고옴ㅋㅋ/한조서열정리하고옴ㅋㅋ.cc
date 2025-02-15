#include <iostream>
#include <vector>
using namespace std;
int N;
vector<int> V;
int main()
{
	cin >> N;
	V.resize(N);
	for (auto &e : V) {
		cin >> e;
	}
	int now = 0;
	int ans = 0;
	int len = 0;
	for (int i = 1;i < V.size();++i) {
		if (V[now]>V[i]) {
			len++;
			ans = max(ans, len);
		}
		else {
			now = i;
			len = 0;
		}
	}
	cout << ans;
}