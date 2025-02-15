//해당 코드는 https://m.blog.naver.com/kks227/221411526404의 게시물을 공부하고 작성한 코드임을 명시합니다.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int MAX_DEPTH = 18;
const int MAX_ST = 1 << MAX_DEPTH;
const int MAX_Q = 10001;
const int MAX_R = 100001;
const int MAX_N = MAX_ST + MAX_Q * MAX_DEPTH;
int T, N, M, X1, X2, Y1, Y2;
struct Node {
	int v, s, f, n, l, r;
	Node() :Node(-1, -1, -1) {}
	Node(int s0, int f0, int n0) :v(0), s(s0), f(f0), n(n0), l(-1), r(-1) {}
};
struct PST {
	int TN, cnt, root[MAX_Q];
	Node node[MAX_N];
	PST() :TN(0), cnt(0) {
		fill(root, root + MAX_Q, -1);
		root[TN++] = initialize(0, MAX_ST / 2);
	}
	int initialize(int s, int f) {
		Node& cur = node[cnt] = Node(s, f, cnt);
		cnt++;
		if (s + 1 < f) {
			int m = (s + f) / 2;
			cur.l = initialize(s, m);
			cur.r = initialize(m, f);
		}
		return cur.n;
	}
	void addN(int y, int v = 1) {
		root[TN] = addN(node[root[TN - 1]], y, v, 0, MAX_ST / 2);
		TN++;
	}
	int addN(Node& prevroot, int y, int v, int s, int f) {
		if (f <= y || y < s) return prevroot.n;
		Node& cur = node[cnt] = Node(s, f, cnt);
		cnt++;
		if (s + 1 == f) cur.v = prevroot.v + v;
		else {
			int m = (s + f) / 2;
			cur.l = addN(node[prevroot.l], y, v, s, m);
			cur.r = addN(node[prevroot.r], y, v, m, f);
			cur.v = node[cur.l].v + node[cur.r].v;
		}
		return cur.n;
	}
	int sum(int tn, int s, int f) {
		return sum(node[root[tn]], s, f);
	}
	int sum(Node& cur, int s, int f) {
		if (f <= cur.s || cur.f <= s) return 0;
		if (s <= cur.s && cur.f <= f) return cur.v;
		return sum(node[cur.l], s, f) + sum(node[cur.r], s, f);
	}
};
bool comp(const pii& a, const pii& b) {
	return a.first < b.first;
}
vector<pii> P;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> T;
	while (T--) {
		cin >> N >> M;
		P.resize(N);
		for (int i = 0;i < N;++i) {
			cin >> P[i].first >> P[i].second;
		}
		sort(P.begin(), P.end());
		PST* pst = new PST();
		for (int i = 0;i < N;++i) {
			pst->addN(P[i].second);
		}
		ll ans = 0;
		for (int i = 0;i < M;++i) {
			cin >> X1 >> X2 >> Y1 >> Y2;
			Y2++;
			auto xs = lower_bound(P.begin(), P.end(), pii{ X1,0 }, comp) - P.begin();
			auto xf = upper_bound(P.begin(), P.end(), pii{ X2,0 }, comp) - P.begin();
			ans += pst->sum(xf, Y1, Y2);
			if (xs != 0)ans -= pst->sum(xs, Y1, Y2);
		}
		cout << ans << '\n';
		delete pst;
	}
}