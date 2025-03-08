#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<int> v;

// x 미만(< x)인 원소 개수
int countLessThan(int x) { return lower_bound(v.begin(), v.end(), x) - v.begin(); }

// x 이하(≤ x)인 원소 개수
int countLessEqual(int x) { return upper_bound(v.begin(), v.end(), x) - v.begin(); }

// x 초과(> x)인 원소 개수
int countGreaterThan(int x) { return v.end() - upper_bound(v.begin(), v.end(), x); }

// x 이상(≥ x)인 원소 개수
int countGreaterEqual(int x) { return v.end() - lower_bound(v.begin(), v.end(), x); }

// true인 구간의 최대 길이와 그 구간의 시작과 끝
void countLTS(const vector<bool> &v) {
    int n = v.size();
    int maxLen = 0;
    int l, r;
    int curLen = 0;
    for (int i = 0; i < n; i++) {
        if (v[i]) {
            curLen++;
            if (maxLen < curLen) {
                maxLen = curLen;
                l = i - curLen + 1;
                r = i;
            }
        } else {
            curLen = 0;
        }
    }
    if (maxLen == 0) {
        // 전부 false인 경우 maxLen == 0
        cout << 0 << '\n';
        return;
    } else {
        // [l, r]이 가장 긴 구간
        cout << l << ' ' << r << '\n';
    }
}

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
    return 0;
}