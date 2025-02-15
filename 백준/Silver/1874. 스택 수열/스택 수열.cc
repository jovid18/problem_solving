#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
int N;
vector<int> V;
vector<char> C;
stack<int> S;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	V.resize(N);
	for (int i = 0;i < N;++i) {
		cin >> V[i];
	}
	int now = 0;
	for (int i = 1;i <= N;++i) {
		S.push(i);
		C.push_back('+');
		while (!S.empty()&&S.top() == V[now]) {
			S.pop();
			now++;
			C.push_back('-');
		}
	}
	if (!S.empty()) {
		cout << "NO";
		return 0;
	}
	for (auto e : C) {
		cout << e << "\n";
	}
}
