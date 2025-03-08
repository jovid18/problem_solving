#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>

struct FT {
    vector<int> s;
    FT(int n) : s(n) {}
    // a[pos] += dif
    void update(int pos, int dif) {
        for (; pos < s.size(); pos |= pos + 1) {
            s[pos] += dif;
        }
    }
    // sum of values in [0, pos)
    int query(int pos) {
        int res = 0;
        for (; pos > 0; pos &= pos - 1) {
            res += s[pos - 1];
        }
        return res;
    }
    // min pos such that sum of in [0, pos) > sum
    int lower_bound(int sum) {
        // return n if no sum is >= sum, or -1 if empty sum is.
        if (sum <= 0) return -1;
        int pos = 0;
        for (int pw = 1 << 25; pw; pw >>= 1) {
            if (pos + pw <= s.size() && s[pos + pw - 1] < sum) {
                pos += pw;
                sum -= s[pos - 1];
            }
        }
        return pos;
    }
};

int countInversions(vector<int> v) {
    vector<int> temp(v.size());
    function<int(int, int)> mergeSortAndCount = [&](int left, int right) {
        if (left >= right) return 0LL;
        int mid = left + (right - left) / 2, inv_count = 0;
        inv_count += mergeSortAndCount(left, mid);
        inv_count += mergeSortAndCount(mid + 1, right);
        int i = left, j = mid + 1, k = left;
        while (i <= mid && j <= right) {
            if (v[i] <= v[j])
                temp[k++] = v[i++];
            else {
                temp[k++] = v[j++];
                inv_count += (mid - i + 1);
            }
        }
        while (i <= mid) temp[k++] = v[i++];
        while (j <= right) temp[k++] = v[j++];
        for (int x = left; x <= right; x++) v[x] = temp[x];
        return inv_count;
    };
    return mergeSortAndCount(0, v.size() - 1);
}

// https://atcoder.jp/contests/abc396/tasks/abc396_f
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int inv = countInversions(a);
    vector<vector<int>> val(m);
    for (int i = 0; i < n; ++i) {
        val[a[i]].push_back(i);
    }
    // ft1: T 미만 기록
    // ft2: T 이상 기록
    FT ft1(n), ft2(n);
    for (int i = 0; i < n; ++i) {
        ft1.update(i, 1);
    }
    int cross = 0, lost = 0;
    vector<int> res(m + 1);
    res[m] = inv;
    auto rangeQuery = [&](FT &fen, int l, int r) {
        if (l > r) return 0LL;
        return fen.query(r + 1) - fen.query(l);
    };
    for (int T = m - 1; T >= 0; T--) {
        // ft1 -> ft2
        for (auto i : val[T]) {
            cross += rangeQuery(ft1, 0, i - 1) - rangeQuery(ft2, i + 1, n - 1);
            lost += rangeQuery(ft1, i + 1, n - 1) - rangeQuery(ft2, 0, i - 1);
            ft1.update(i, -1);
            ft2.update(i, 1);
        }
        res[T] = inv + cross - lost;
    }
    for (int k = 0; k < m; k++) {
        cout << res[m - k] << "\n";
    }
}