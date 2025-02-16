#include <iostream>

#include <vector>

#include <string>

#include <algorithm>

using namespace std;

using pii = pair<int, int>;

vector<pii> P;

int dist(const pii& a, const pii& b) {

	return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);}

bool compx(const pii& a, const pii& b) {

	if (a.first == b.first) {

		return a.second <= b.second;

	}

	return a.first < b.first;

}

bool compy(const pii& a, const pii& b) {

	if (a.second == b.second) {

		return a.first < b.first;

	}

	return a.second < b.second;

}

int search(int left, int right) {

	if (right - left <= 2) {

		int ans = 2e9;

		for (int i = left; i <= right;++i) {

			for (int j = i + 1;j <= right;++j) {

				ans = min(ans, dist(P[i], P[j]));

			}

		}

		return ans;

	}

	int mid = (left + right) / 2;

	int distl = search(left, mid);

	int distr = search(mid + 1, right);

	int ans = min(distl, distr);

	vector<pii> V;

	for (int i = left;i <= right;++i) {

		int diffx = P[i].first - P[mid].first;

		if (diffx * diffx < ans) V.push_back(P[i]);

	}

	sort(V.begin(), V.end(), compy);

	for (int i = 0;i < V.size();++i) {

		for (int j = i + 1;j < V.size();++j) {

			int diffy = V[j].second - V[i].second;

			if (diffy * diffy < ans) {

				ans = min(ans, dist(V[i], V[j]));

			}

			else {

				break;

			}

		}

	}

	return ans;

}

int main() {

	ios_base::sync_with_stdio(false);

	cin.tie(0);

	cout.tie(0);

	int N;

	cin >> N;

	P.resize(N);

	for (int i = 0; i < N;++i) {

		cin >> P[i].first >> P[i].second;

	}

	sort(P.begin(), P.end());

	cout << search(0, N - 1);

}