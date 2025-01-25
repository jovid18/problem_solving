#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>

// editorial
int n;
int a[12];  // input
int s[12];  // bucket
int val;    // xor값
unordered_set<int> st;

void dfs(int idx, int sz) {
    // idx: 지금 a[idx] (즉 A_idx)을 어느 '버킷'에 넣을지 결정할 차례
    // sz : 현재까지 만들어진 버킷의 개수
    for (int i = 0; i <= sz; ++i) {
        // s[i]에 a[idx]를 넣는다.
        // s[i]에 추가를 하기 전 xor값에서 잠깐 빼준다.
        val ^= s[i];
        // s[i]에 a[idx]를 추가한다.
        s[i] += a[idx];
        // s[i]에 추가를 한 후 xor값을 갱신
        val ^= s[i];
        if (idx == n - 1) {
            // 어떤 버킷인지는 몰라도, 마지막 a[n-1]까지 넣었으면 st에 추가
            st.insert(val);
        } else {
            if (i < sz)
                // 기존에 존재했던 버킷 s[0]~s[sz-1]에 넣는 경우
                // sz는 변하지 않음
                dfs(idx + 1, sz);
            else
                // 새로운 버킷에 a[idx]를 넣는 경우
                // sz가 1 증가
                dfs(idx + 1, sz + 1);
        }
        val ^= s[i];
        s[i] -= a[idx];
        val ^= s[i];
    }
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    dfs(0, 0);
    cout << st.size() << '\n';
}