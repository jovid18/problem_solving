#include <bits/stdc++.h>
using namespace std;
#define int long long
int N, M;
pair<int, int> min19, min09;
vector<int> P;
vector<pair<int, int>> Q, R;
bool comp1(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first)
        return a.second > b.second;
    return a.first < b.first;
}
bool comp2(pair<int, int> a, pair<int, int> b) { return a.second > b.second; }
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    P.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> P[i];
        Q.push_back({P[i], i});
        R.push_back({P[i], i});
    }
    cin >> M;
    if (N == 1) {
        cout << 0;
        return 0;
    }
    sort(Q.begin(), Q.end(), comp1);
    sort(R.begin(), R.end(), comp2);
    min09 = Q.front();
    if (Q.front().second == 0) {
        if (Q[1].first > M) {
            cout << 0;
            return 0;
        }
        min19 = Q[1];
    } else {
        min19 = Q.front();
    }
    string s = "";
    while (true) {
        if (s.empty() && M >= min19.first) {
            s += to_string(min19.second);
            M -= min19.first;
        } else if (M >= min09.first) {
            s += to_string(min09.second);
            M -= min09.first;
        } else {
            break;
        }
    }
    for (int i = 0; i < s.size(); i++) {
        if (i == 0) {
            for (auto e : R) {
                if (M + min19.first >= e.first && e.second != 0) {
                    s[i] = '0' + e.second;
                    M -= e.first - min19.first;
                    break;
                }
            }
        } else {
            for (auto e : R) {
                if (M + min09.first >= e.first) {
                    s[i] = '0' + e.second;
                    M -= e.first - min09.first;
                    break;
                }
            }
        }
    }
    cout << s;
}