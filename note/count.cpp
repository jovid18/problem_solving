#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<int> v;

// x 미만(< x)인 원소 개수
int countLessThan(int x) { return lower_bound(v.begin(), v.end(), x) - v.begin(); }

// x 이하(≤ x)인 원소 개수
int countLessEqual(int x) { return upper_bound(v.begin(), v.end(), x) - v.begin(); }

// x 초과(> x)인 원소 개수
int countGreaterThan(int x) { return v.end() - upper_bound(v.begin(), v.end(), x); }

// x 이상(≥ x)인 원소 개수
int countGreaterEqual(int x) { return v.end() - lower_bound(v.begin(), v.end(), x); }

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    return 0;
}