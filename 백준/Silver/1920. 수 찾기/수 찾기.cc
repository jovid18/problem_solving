#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N,M;
vector<int> A;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    A.resize(N);
    for (int i = 0;i < N;++i) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    cin >> M;
    while (M--) {
        int x;
        cin >> x;
        auto iter = lower_bound(A.begin(), A.end(), x);
        if (iter != A.end()&&(*iter)==x) cout << 1 << '\n';
        else cout << 0 << '\n';
    }
}