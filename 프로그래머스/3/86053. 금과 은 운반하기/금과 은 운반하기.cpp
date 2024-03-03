#include <iostream>
#include <string>
#include <vector>
using namespace std;
using ll = long long;

bool solve(int a, int b, vector<int> &g, vector<int> &s, vector<int> &w,
           vector<int> &t, ll time) {
    ll total = 0;
    ll gold = 0;
    ll silver = 0;
    for (int i = 0; i < g.size(); i++) {
        ll cnt = time / (2 * t[i]);
        if (time % (2 * t[i]) >= t[i])
            cnt++;
        ll lmt = min(cnt * w[i], (ll)s[i] + (ll)g[i]);
        total += lmt;
        gold += min(lmt, (ll)g[i]);
        silver += min(lmt, (ll)s[i]);
    }
    if (total >= a + b && gold >= a && silver >= b)
        return true;
    return false;
}
ll solution(int a, int b, vector<int> g, vector<int> s, vector<int> w,
            vector<int> t) {
    ll start = 0;
    ll end = 2000000000000001LL;
    while (start + 1 < end) {
        ll mid = (start + end) / 2;
        if (solve(a, b, g, s, w, t, mid)) {
            end = mid;
        } else {
            start = mid;
        }
    }
    return end;
}