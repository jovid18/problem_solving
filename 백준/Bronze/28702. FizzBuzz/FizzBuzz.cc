#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    vector<string> v(3);
    for (auto &e : v) {
        cin >> e;
    }
    int num = 0;
    for (int i = 0; i < 3; i++) {
        if (v[i] != "Fizz" && v[i] != "Buzz" && v[i] != "FizzBuzz") {
            num += stoi(v[i]) + 3 - i;
            break;
        }
    }
    if (num % 3 == 0 && num % 5 == 0) {
        cout << "FizzBuzz\n";
    } else if (num % 3 == 0) {
        cout << "Fizz\n";
    } else if (num % 5 == 0) {
        cout << "Buzz\n";
    } else {
        cout << num << "\n";
    }
}