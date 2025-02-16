#include <iostream>
#include <deque>
#include <string>
using namespace std;
int N, X;
string cmd;
deque<int> dq;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	while (N--) {
		cin >> cmd;
		if (cmd == "push_front") {
			cin >> X;
			dq.push_front(X);
		}
		else if (cmd == "push_back") {
			cin >> X;
			dq.push_back(X);
		}
		else if (cmd == "pop_front") {
			if (dq.empty()) {
				cout << -1 << '\n';
			}
			else {
				cout << dq.front() << '\n';
				dq.pop_front();
			}
		}
		else if (cmd == "pop_back") {
			if (dq.empty()) {
				cout << -1 << '\n';
			}
			else {
				cout << dq.back() << '\n';
				dq.pop_back();
			}
		}
		else if (cmd == "size") {
			cout << dq.size() << '\n';
		}
		else if (cmd == "empty") {
			cout << dq.empty() << '\n';
		}
		else if (cmd == "front") {
			if (dq.empty()) {
				cout << -1<<'\n';
			}
			else {
				cout << dq.front() << '\n';
			}
		}
		else if (cmd == "back") {
			if (dq.empty()) {
				cout << -1 << '\n';
			}
			else {
				cout << dq.back() << '\n';
			}
		}
	}
}
