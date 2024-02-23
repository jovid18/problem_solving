#include <algorithm>
#include <string>
#include <vector>
using namespace std;
using ll = long long;

long long  solution(int n, vector<int> times) {
    sort(times.begin(), times.end());
    ll s = 0;
    ll f = (ll)n * times.back();
    while (s != f) {
        ll m = (s + f) / 2;
        ll now = 0;
        for (auto e : times) {
            now += m / e;
        }
        if (now >= n) {
            f = m;
        } else {
            s = m + 1;
        }
    }
    return s;
}