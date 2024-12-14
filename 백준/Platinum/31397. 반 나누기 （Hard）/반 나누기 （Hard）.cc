#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
using pii = pair<ld, ld>;
int N;
vector<ld> Dist;
vector<pii> v;
ld totalLength, totalArea;
ld getDist(pii a, pii b) { return sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second)); }
pii getPoint(ld d) {
    for (int i = 0; i < N; i++) {
        ld len = getDist(v[i], v[(i + 1) % N]);
        if (d < len) {
            ld dx = v[(i + 1) % N].first - v[i].first;
            ld dy = v[(i + 1) % N].second - v[i].second;
            return {v[i].first + dx * d / len, v[i].second + dy * d / len};
        }
        d -= len;
    }
    return {0, 0};
}
int getIdx(ld d) {
    int l = 0, r = N;
    while (l + 1 < r) {
        int mid = (l + r) / 2;
        if (d < Dist[mid])
            r = mid;
        else
            l = mid;
    }
    return l;
}
ld getArea(pii a, pii b, pii c) {
    ld area = (a.first * b.second + b.first * c.second + c.first * a.second - a.first * c.second - b.first * a.second - c.first * b.second) / 2;
    return abs(area);
}
ld getAreaDiff(ld d) {
    pii p1 = getPoint(d);
    pii p2 = getPoint(d + totalLength / 2);
    int p1Idx = getIdx(d);
    int p2Idx = getIdx(d + totalLength / 2);
    ld S = 0;
    for (int i = p1Idx + 1; i < p2Idx; i++) {
        S += getArea(p1, v[i], v[i + 1]);
    }
    S += getArea(p1, v[p2Idx], p2);
    return totalArea - 2 * S;
}

void printRatio(ld d) {
    pii p = getPoint(d);
    int idx = getIdx(d);
    ld d0 = getDist(v[idx], v[((idx + 1) % N)]);
    ld d1 = getDist(v[idx], p);
    cout << fixed << setprecision(20) << idx + 1 << ' ' << (d1 / d0) << '\n';
    return;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    v.resize(N);
    for (auto &i : v) cin >> i.first >> i.second;
    Dist.push_back(0);
    for (int i = 0; i < N; i++) {
        totalLength += getDist(v[i], v[(i + 1) % N]);
        Dist.push_back(totalLength);
    }
    for (int i = 1; i < N - 1; i++) {
        totalArea += getArea(v[0], v[i], v[i + 1]);
    }
    ld l = 0, r = totalLength / 2;
    cout << fixed << setprecision(20);
    for (int i = 0; i < 10000; i++) {
        ld m = (l + r) / 2;
        if (l == m || r == m) break;
        if (getAreaDiff(m) * getAreaDiff(l) > 0)
            l = m;
        else
            r = m;
    }
    cout << "YES\n";
    printRatio(l);
    printRatio(l + totalLength / 2);
}