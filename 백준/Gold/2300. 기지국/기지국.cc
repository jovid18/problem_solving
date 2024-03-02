#include <bits/stdc++.h>
using namespace std;
#define int long long
#define xx first
#define yy second
using pii = pair<int, int>;
int N;
vector<pii> V, OV;
bool comp(const pii &a, const pii &b) {
    if (a.xx == b.xx)
        return a.yy > b.yy;
    return a.xx < b.xx;
}
int DP[10001];
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    memset(DP, 0x3f, sizeof(DP));
    cin >> N;
    V.resize(N);
    for (auto &e : V) {
        cin >> e.xx >> e.yy;
        if (e.yy < 0)
            e.yy *= -1;
    }
    sort(V.begin(), V.end(), comp);
    OV.push_back({-1, -1});
    for (int i = 0; i < V.size(); ++i) {
        if (i == 0) {
            OV.push_back(V[i]);
            continue;
        }
        if (V[i - 1].xx != V[i].xx) {
            OV.push_back(V[i]);
        }
    }
    N = OV.size() - 1;
    DP[0] = 0;
    for (int i = 1; i <= N; ++i) {
        int MAXY = 0;
        for (int j = i; j >= 1; --j) {
            MAXY = max(MAXY, OV[j].yy);
            int now = DP[j - 1] + max(OV[i].xx - OV[j].xx, 2 * MAXY);
            DP[i] = min(DP[i], now);
        }
    }
    cout << DP[N];
}