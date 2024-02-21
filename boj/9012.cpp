#include <iostream>
#include <stack>
#include <string>
using namespace std;
int N, L;
string S;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    while (N--) {
        cin >> S;
        bool pass = true;
        stack<char> C;
        for (int i = 0; i < S.size(); ++i) {
            if (S[i] == '(') {
                C.push('(');
            } else {
                if (C.empty() || !C.top() == ')') {
                    pass = false;
                    break;
                } else
                    C.pop();
            }
        }
        if (C.size())
            pass = false;
        if (!pass)
            cout << "NO\n";
        else
            cout << "YES\n";
    }
}