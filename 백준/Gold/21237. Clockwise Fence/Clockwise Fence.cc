#include <bits/stdc++.h>
using namespace std;
#define int long long
int N;
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    while (N--) {
        string s;
        cin >> s;
        int xMax = 0, xMin = 0, yMax = 0, yMin = 0, xNow = 0, yNow = 0;
        for (auto c : s) {
            if (c == 'N') yNow++;
            if (c == 'S') yNow--;
            if (c == 'E') xNow++;
            if (c == 'W') xNow--;
            xMax = max(xMax, xNow);
            xMin = min(xMin, xNow);
            yMax = max(yMax, yNow);
            yMin = min(yMin, yNow);
        }
        int Ncnt = 0;
        xNow = 0, yNow = 0;
        for (auto c : s) {
            if (c == 'N') yNow++;
            if (c == 'S') yNow--;
            if (c == 'E') xNow++;
            if (c == 'W') xNow--;
            if (xNow == xMax && (c == 'N' || c == 'S')) {
                cout << (c == 'S' ? "CW" : "CCW") << '\n';
                break;
            }
        }
    }
}