#include <iostream>
#include <string>
#include <map>
using namespace std;
using ll = long long;
int N, M;
ll S[100001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	for (int i = 1;i <= N;++i) {
		cin >> S[i];
		S[i] += S[i - 1];
	}
	while (M--) {
		int a, b;
		cin >> a >> b;
		cout<<S[b] - S[a - 1]<<'\n';
	}
}
