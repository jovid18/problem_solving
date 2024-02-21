#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
queue<int> Q;
int N, K;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> K;
    for (int i = 1; i <= N; ++i) {
        Q.push(i);
    }
    bool first = true;
    cout << '<';
    while (!Q.empty()) {
        for (int i = 1; i < K; ++i) {
            int a = Q.front();
            Q.pop();
            Q.push(a);
        }
        if (first) {
            cout << Q.front();
            first = false;
        } else {
            cout << ", " << Q.front();
        }
        Q.pop();
    }
    cout << '>';
}