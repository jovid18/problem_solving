#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
#define ld long double

ld dist(pii a, pii b) {
    ld dx = a.first - b.first;
    ld dy = a.second - b.second;
    return sqrt(dx * dx + dy * dy);
}

// https://atcoder.jp/contests/abc145/tasks/abc145_c
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int N;
    cin >> N;
    vector<pii> P(N);
    vector<int> perm(N);
    vector<ld> d;
    for (int i = 0; i < N; i++) {
        cin >> P[i].first >> P[i].second;
    }
    iota(perm.begin(), perm.end(), 0);
    do {
        ld sum = 0;
        for (int i = 0; i < N - 1; i++) {
            sum += dist(P[perm[i]], P[perm[i + 1]]);
        }
        d.push_back(sum);
    } while (next_permutation(perm.begin(), perm.end()));
    ld ans = accumulate(d.begin(), d.end(), 0.0) / d.size();
    cout << fixed << setprecision(10) << ans << endl;
}