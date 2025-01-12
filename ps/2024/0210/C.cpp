#include <bits/stdc++.h>
using namespace std;
#define int long long
int N;
map<int, int> m;
int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> N;
  m[N] = 1;
  int ans = 0;
  while (!m.empty()) {
    auto iter = m.rbegin();
    int x = iter->first;
    int y = iter->second;
    int a, b;
    if (x % 2 == 0) {
      a = x / 2;
      b = x / 2;
    } else {
      a = x / 2;
      b = (x + 1) / 2;
    }
    if (a > 1) {
      if (m.find(a) != m.end()) {
        m[a] = m[a] + y;
      } else {
        m[a] = y;
      }
    }
    if (b > 1) {
      if (m.find(b) != m.end()) {
        m[b] = m[b] + y;
      } else {
        m[b] = y;
      }
    }
    m.erase(x);
    ans += x * y;
  }
  cout << ans;
}