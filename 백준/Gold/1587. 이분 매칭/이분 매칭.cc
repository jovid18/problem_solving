#include <iostream>
using namespace std;
int A, B, M, a, b;
bool chk;
int main(){
	cin >> A >> B >> M;
	while (M--) {
		cin>>a>>b;
		if (a % 2 == 1 && b % 2 == 1) chk = 1;
	}
	M = A / 2 + B / 2;
	if (A % 2 == 1 && B % 2 == 1 && chk) M++;
	cout << M;
}