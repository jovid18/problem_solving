#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <vector>
using namespace std;
string str;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	while (true) {
		getline(cin, str);
		if (str.size() == 1 && str[0] == '.') break;
		stack<char> C;
		bool ok = true;
		for (int i = 0;i < str.size();++i) {
			if (str[i] == '[') {
				C.push(str[i]);
			}
			else if (str[i] == '(') {
				C.push(str[i]);
			}
			else if (str[i] == ')') {
				if (C.empty() || C.top() != '(') {
					ok = false;
					break;
				}
				else C.pop();
			}
			else if (str[i] == ']') {
				if (C.empty() || C.top() != '[') {
					ok = false;
					break;
				}
				else C.pop();
			}
		}
		if (!C.empty()) ok = false;
		if (ok) cout << "yes\n";
		else cout << "no\n";
	}

}