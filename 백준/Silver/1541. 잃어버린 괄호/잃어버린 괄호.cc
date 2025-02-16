#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;
vector<char> op;
vector<int> num, chk;
string s;
int main() {
	cin >> s;
	for (int i = 0;i < s.size();++i) {
		if (s[i] == '+' || s[i] == '-') {
			op.push_back(s[i]);
			chk.push_back(i);
		}
	}
	if (chk.size() == 0) {
		cout << stoi(s);
		return 0;
	}
	num.push_back(stoi(s.substr(0, chk[0])));
	for (int i = 0;i + 1 < chk.size();++i) {
		num.push_back(stoi(s.substr(chk[i], chk[i + 1] - i)));
	}
	num.push_back(stoi(s.substr(chk.back(), s.size() - chk.back())));
	for (auto& e : num) {
		e = abs(e);
	}
	for (int i = 1;i<op.size();++i) {
		if (op[i - 1] == '-') op[i] = '-';
	}
	int ans = num[0];
	for (int i = 1;i < num.size();++i) {
		if (op[i - 1] == '+') {
			ans += num[i];
		}else {
			ans -= num[i];
		}
	}
	cout << ans;
}