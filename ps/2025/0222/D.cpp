#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>

// https://atcoder.jp/contests/abc394/tasks/abc394_d
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    string s;
    cin >> s;
    stack<char> st;
    for (auto e : s) {
        if (e == '(' || e == '[' || e == '<')
            st.push(e);
        else {
            if (st.empty()) {
                cout << "No";
                return 0;
            }
            if (e == ')' && st.top() == '(')
                st.pop();
            else if (e == ']' && st.top() == '[')
                st.pop();
            else if (e == '>' && st.top() == '<')
                st.pop();
        }
    }
    if (st.empty())
        cout << "Yes";
    else
        cout << "No";
}