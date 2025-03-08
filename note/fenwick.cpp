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

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    return 0;
}