#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>

//https://atcoder.jp/contests/abc394/tasks/abc394_c
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    string s;
    cin >> s;
    stack<char> st;
    for (auto e : s) {
        if (e == 'A') {
            if (st.empty())
                st.push(e);
            else {
                int cnt = 0;
                while (st.size() && st.top() == 'W') {
                    st.pop();
                    cnt++;
                }
                st.push('A');
                while (cnt--) st.push('C');
            }
        } else {
            st.push(e);
        }
    }
    string ans = "";
    while (st.size()) {
        ans += st.top();
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    cout << ans << '\n';
}