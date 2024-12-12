#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int> A, l, r, c;
int N, M;
using T = pair<int, vector<int> >;
priority_queue<T, vector<T>, greater<T> > pq;
set<vector<int> > visited;
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    A.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    cin >> M;
    l.resize(M);
    r.resize(M);
    c.resize(M);
    for (int i = 0; i < M; i++) {
        cin >> l[i] >> r[i] >> c[i];
        l[i]--;
        r[i]--;
    }
    pq.push({0, A});
    while (pq.size()) {
        auto [cost, arr] = pq.top();
        pq.pop();
        if (visited.count(arr)) {
            continue;
        }
        visited.insert(arr);
        if (is_sorted(arr.begin(), arr.end())) {
            cout << cost << '\n';
            return 0;
        }
        for (int i = 0; i < M; i++) {
            vector<int> newArr = arr;
            swap(newArr[l[i]], newArr[r[i]]);
            pq.push({cost + c[i], newArr});
        }
    }
    cout << -1 << '\n';
}