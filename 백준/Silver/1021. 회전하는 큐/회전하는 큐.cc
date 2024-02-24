#include <bits/stdc++.h>
using namespace std;
#define int long long
deque<int> dq;
int N, M, ans;
void solve(deque<int> &dq, int M) {
    auto left = dq;
    int left_cnt = 0;
    while (left.front() != M) {
        left.push_back(left.front());
        left.pop_front();
        left_cnt++;
    }
    left.pop_front();
    auto right = dq;
    int right_cnt = 0;
    while (right.front() != M) {
        right.push_front(right.back());
        right.pop_back();
        right_cnt++;
    }
    right.pop_front();
    if (left_cnt < right_cnt) {
        dq = left;
        ans += left_cnt;
    } else {
        dq = right;
        ans += right_cnt;
    }
}
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        dq.push_back(i);
    for (int i = 0; i < M; i++) {
        int x;
        cin >> x;
        solve(dq, x);
    }
    cout << ans;
}