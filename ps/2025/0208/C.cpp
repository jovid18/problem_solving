#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> p(n + 1), q(n + 1);
    // i번째 사람이 바라보는 사람
    for (int i = 1; i <= n; i++) cin >> p[i];
    // i번째 사람의 등번호
    for (int i = 1; i <= n; i++) cin >> q[i];
    // 등번호가 i인 사람의 번호
    map<int, int> blobToNum;
    for (int i = 1; i <= n; i++) {
        blobToNum[q[i]] = i;
    }
    // i번재 사람이 바라보고 있는 사람
    map<int, int> stareToNum;
    for (int i = 1; i <= n; i++) {
        stareToNum[i] = p[i];
    }

    for (int i = 1; i <= n; i++) {
        int man = blobToNum[i];
        int stare = stareToNum[man];
        cout << q[stare] << ' ';
    }
}