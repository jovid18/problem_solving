#include <iostream>
#include <string>
#include <cctype>
using namespace std;
string s;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> s;
	for (int i = 0;i < s.size();++i) {
		if (s[i] == toupper(s[i])) s[i] = tolower(s[i]);
		else s[i] = toupper(s[i]);
	}
	cout << s;
}