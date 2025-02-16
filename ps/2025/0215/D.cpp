#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>

// https://atcoder.jp/contests/abc393/tasks/abc393_d
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    string s;
    cin >> n >> s;
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '1') cnt++;
    }
    int ans = 0;
    if (cnt % 2 == 1) {
        // 홀수 케이스
        int mid = cnt / 2 + 1;
        int mid_idx = -1;
        {
            int cnt = 0;
            for (int i = 0; i < n; ++i) {
                if (s[i] == '0') continue;
                if (s[i] == '1') cnt++;
                if (cnt == mid) {
                    mid_idx = i;
                    break;
                }
            }
        }
        {
            int cnt = 0;
            for (int i = 0; i < n; ++i) {
                if (s[i] == '0') continue;
                if (s[i] == '1') cnt++;
                if (cnt < mid) {
                    ans += mid_idx - (mid - cnt) - i;
                } else {
                    ans += i - mid_idx - (cnt - mid);
                }
            }
        }
    } else {
        // 짝수 케이스
        int mid1 = cnt / 2;
        int mid2 = mid1 + 1;
        int ans1 = 0;
        int ans2 = 0;
        {
            int mid_idx = -1;
            int cnt = 0;
            for (int i = 0; i < n; ++i) {
                if (s[i] == '0') continue;
                if (s[i] == '1') cnt++;
                if (cnt == mid1) {
                    mid_idx = i;
                    break;
                }
            }
            cnt = 0;
            for (int i = 0; i < n; ++i) {
                if (s[i] == '0') continue;
                if (s[i] == '1') cnt++;
                if (cnt < mid1) {
                    ans1 += mid_idx - (mid1 - cnt) - i;
                } else {
                    ans1 += i - mid_idx - (cnt - mid1);
                }
            }
        }
        {
            int mid_idx = -1;
            int cnt = 0;
            for (int i = 0; i < n; ++i) {
                if (s[i] == '0') continue;
                if (s[i] == '1') cnt++;
                if (cnt == mid2) {
                    mid_idx = i;
                    break;
                }
            }
            cnt = 0;
            for (int i = 0; i < n; ++i) {
                if (s[i] == '0') continue;
                if (s[i] == '1') cnt++;
                if (cnt < mid2) {
                    ans2 += mid_idx - (mid2 - cnt) - i;
                } else {
                    ans2 += i - mid_idx - (cnt - mid2);
                }
            }
        }
        ans = min(ans1, ans2);
    }
    cout << ans;
}