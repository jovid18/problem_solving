//https://dasu.tistory.com/16의 글을 공부하고 작성한 코드임을 명시합니다.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using pii = pair<int, int>;
const int MAX = 500003;
const int INF = 2e9;
int N, U, D, S;
vector<pii> M[MAX];
int upseg[4 * MAX], downseg[4 * MAX];
int query(int* arr, int s, int f, int n, int l, int r) {
	if (f < l || r < s) return -INF;
	if (l <= s && f <= r) return arr[n];
	int m = (s + f) / 2;
	return max(query(arr, s, m, 2 * n, l, r), query(arr, m + 1, f, 2 * n + 1, l, r));
}
void update(int* arr, int s, int f, int n, int i, int d) {
	if (s == f) {
		arr[n] = d;
		return;
	}
	int m = (s + f) / 2;
	if (i <= m) update(arr, s, m, 2 * n, i, d);
	else update(arr, m + 1, f, 2 * n + 1, i, d);
	arr[n] = max(arr[n * 2], arr[n * 2 + 1]);
}
void update(int x, int v) {
	update(upseg, 1, 500001, 1, x, v + D * x);
	update(downseg, 1, 500001, 1, x, v - U * x);
}
int totalquery(int a) {
	return max(query(upseg, 1, 500001, 1, 1, a) - D * a, query(downseg, 1, 500001, 1, a, 500001) + U * a);
}
void solve(int i) {
	if (M[i].size() == 0) return;
	sort(M[i].begin(), M[i].end());
	int siz = M[i].size();
	vector<int> Up(siz), Down(siz);
	for (int j = 0;j < siz;++j) {
		int now = totalquery(M[i][j].first);
		Up[j] = now;
		Down[j] = now;
	}
	for (int j = 0;j < siz;++j) {
		if (j != 0) Up[j] = max(Up[j], Up[j - 1] - D * (M[i][j].first - M[i][j - 1].first));
		Up[j] += M[i][j].second;
	}
	for (int j = siz - 1;j >= 0;--j) {
		if (j != siz - 1) Down[j] = max(Down[j], Down[j + 1] - U * (M[i][j + 1].first - M[i][j].first));
		Down[j] += M[i][j].second;
	}
	for (int j = 0;j < siz;++j) {
		update(M[i][j].first, max(Up[j], Down[j]));
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> U >> D >> S;
	for (int i = 0;i < N;++i) {
		int a, b, c;
		cin >> a >> b >> c;
		M[a].push_back({ b,c });
	}

	fill(upseg, upseg + 4 * MAX, -INF);
	fill(downseg, downseg + 4 * MAX, -INF);
	update(S, 0);
	for (int i = 1;i <= 500000;++i) {
		solve(i);
	}
	cout << totalquery(S);
}
