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

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    return 0;
}