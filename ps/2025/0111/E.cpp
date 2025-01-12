#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> A(N);
    for (auto &e : A) cin >> e;

    map<int, int> freq;
    for (auto &e : A) {
        freq[e]++;
    }
    int ans = 0;
    for (int i = N - 1; i >= 0; i--) {
        int val = A[i];
        auto itVal = freq.find(val);
        if (itVal == freq.end()) {
            continue;
        }
        if (itVal->second == 0) {
            freq.erase(itVal);
            continue;
        }

        int half = val / 2;
        auto it2 = freq.upper_bound(half);
        if (it2 == freq.begin()) {
            continue;
        }
        it2--;

        if (it2->second == 0) {
            freq.erase(it2);
            continue;
        }

        itVal->second--;
        if (itVal->second == 0) {
            freq.erase(itVal);
        }
        auto tmpIt = it2;
        tmpIt->second--;
        if (tmpIt->second == 0) {
            freq.erase(tmpIt);
        }

        ans++;
    }

    cout << ans << "\n";
}
