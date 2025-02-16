#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAX = 1200001;

vector<int> spf(MAX);
void computeSpf() {
    for (int i = 1; i < MAX; i++) spf[i] = i;
    for (int i = 2; i * i < MAX; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j < MAX; j += i) {
                if (spf[j] == j) spf[j] = i;
            }
        }
    }
}

vector<vector<pair<int, int>>> factorizeMemo(MAX);
vector<pair<int, int>> factorize(int x) {
    if (factorizeMemo[x].size() != 0) return factorizeMemo[x];
    vector<pair<int, int>> res;
    while (x > 1) {
        int p = spf[x];
        int cnt = 0;
        while (x % p == 0) {
            cnt++;
            x /= p;
        }
        res.push_back({p, cnt});
    }
    return res;
}

vector<vector<int>> divisorsMemo(MAX);
void genDivisors(int idx, int cur, const vector<pair<int, int>> &factors, vector<int> &divs) {
    if (idx == factors.size()) {
        divs.push_back(cur);
        return;
    }
    int p = factors[idx].first;
    int cnt = factors[idx].second;
    for (int i = 0; i <= cnt; i++) {
        genDivisors(idx + 1, cur, factors, divs);
        cur *= p;
    }
}

// https://atcoder.jp/contests/abc393/tasks/abc393_e
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    computeSpf();

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    vector<int> f(MAX, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        f[a[i]]++;
    }
    vector<int> cnt(MAX, 0);
    for (int d = 1; d < MAX; d++) {
        for (int j = d; j < MAX; j += d) {
            cnt[d] += f[j];
        }
    }
    for (int i = 0; i < n; i++) {
        vector<pair<int, int>> factors = factorize(a[i]);
        if (divisorsMemo[a[i]].empty()) {
            vector<int> divs;
            genDivisors(0, 1, factors, divs);
            sort(divs.begin(), divs.end(), greater<int>());
            divisorsMemo[a[i]] = divs;
        }
        for (int d : divisorsMemo[a[i]]) {
            if (cnt[d] >= k) {
                cout << d << "\n";
                break;
            }
        }
    }

    return 0;
}
