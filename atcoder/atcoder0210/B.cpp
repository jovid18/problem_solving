#include <bits/stdc++.h>
using namespace std;
#define int long long
int Q;
vector<int> A;
int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> Q;
  while (Q--) {
    int a, b;
    cin >> a >> b;
    if (a == 1) {
      A.push_back(b);
    } else {
      cout << A[A.size() - b] << '\n';
    }
  }
}