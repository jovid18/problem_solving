#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    priority_queue<unsigned long long, vector<unsigned long long>,
                   greater<unsigned long long>>
        minheap;
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        unsigned long long a;
        cin >> a;
        if (a == 0) {
            if (minheap.empty()) {
                cout << 0 << '\n';
            } else {
                cout << minheap.top() << '\n';
                minheap.pop();
            }
        } else {
            minheap.push(a);
        }
    }

    return 0;
}
