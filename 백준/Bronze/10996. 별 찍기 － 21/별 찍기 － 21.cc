#include <iostream>
using namespace std;
int N;
int main()
{
	cin >> N;
	for (int i = 0;i < 2 * N;++i) {
		for (int j = 0;j < N;++j) {
			if (i % 2) {
				if (j % 2) {
					cout << '*';
				}
				else {
					cout << ' ';
				}
			}
			else {
				if (j % 2) {
					cout << ' ';
				}
				else {
					cout << '*';
				}
			}

		}
		cout << '\n';
	}
}