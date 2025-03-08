#include <bits/stdc++.h>
using namespace std;
#define int long long

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

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &i : v) cin >> i;
    cout << countInversions(v);
}