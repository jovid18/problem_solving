#include <iostream>
#include <queue>
using namespace std;
struct comp {
    bool operator()(int n1, int n2) {
        if (abs(n1) == abs(n2)) return n1 > n2;
        return abs(n1) > abs(n2);
    }
};
priority_queue<int, vector<int>, comp> pq;
int N,x;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    while (N--) {
        cin >> x;
        if (x != 0) pq.push(x);
        else {
            if (pq.empty())cout << 0 << '\n';
            else {
                cout << pq.top() << '\n';
                pq.pop();
            }
        }
    }
}