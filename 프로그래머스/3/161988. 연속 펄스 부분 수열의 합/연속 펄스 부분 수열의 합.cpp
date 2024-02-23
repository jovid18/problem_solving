#include <iostream>
#include <string>
#include <vector>
using namespace std;
using ll = long long;
long long kadane(vector<long long> v) {
    vector<ll> dp(v.size());
    dp[0] = v[0];
    ll ret = dp[0];
    for (int i = 1; i < v.size(); ++i) {
        dp[i] = max(v[i], v[i] + dp[i - 1]);
        ret = max(ret, dp[i]);
    }
    return ret;
}
long long solution(vector<int> sequence) {
    int n = sequence.size();
    long long answer = 0;
    vector<ll> s1(n);
    vector<ll> s2(n);
    for (int i = 0; i < n; ++i) {
        s1[i] = sequence[i];
        s2[i] = sequence[i];
    }
    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) {
            s1[i] *= -1;
        }
        if (i % 2 == 1) {
            s2[i] *= -1;
        }
    }
    return max(kadane(s1), kadane(s2));
}