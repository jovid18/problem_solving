#include <stack>
#include <string>
#include <vector>
using namespace std;

int solution(string s) {
    int answer = 0;

    int n = s.size();
    s += s;
    stack<char> st;
    for (int i = 0; i < n; ++i) {
        bool is_valid = true;
        for (int j = 0; j < n; ++j) {
            if (s[i + j] == '(' || s[i + j] == '[' || s[i + j] == '{') {
                st.push(s[i + j]);
            } else {
                if (st.empty()) {
                    is_valid = false;
                    break;
                }
                if (s[i + j] == ')' && st.top() == '(') {
                    st.pop();
                } else if (s[i + j] == ']' && st.top() == '[') {
                    st.pop();
                } else if (s[i + j] == '}' && st.top() == '{') {
                    st.pop();
                } else {
                    is_valid = false;
                    break;
                }
            }
        }
        if (is_valid && st.empty()) {
            ++answer;
        }
        while (!st.empty()) {
            st.pop();
        }
    }

    return answer;
}