#include <iostream>
using namespace std;
double ans, x;
int main() {
	for (int i = 0;i < 5;++i) {
		cin >> x;
		x = max(x, (double)40);
		ans += x;
	}
	cout << ans / 5;
}