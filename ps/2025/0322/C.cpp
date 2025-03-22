#include <bits/stdc++.h>
using namespace std;
#define int long long

// https://atcoder.jp/contests/abc398/tasks/abc398_c
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &i : a) cin >> i;

    unordered_map<int, int> freq;
    for (int i = 0; i < n; i++) freq[a[i]]++;

    int max_val = -1;
    int ans_index = -1;

    for (int i = 0; i < n; i++) {
        if (freq[a[i]] == 1 && a[i] > max_val) {
            max_val = a[i];
            ans_index = i + 1;
        }
    }

    cout << (ans_index == -1 ? -1 : ans_index) << '\n';
}
