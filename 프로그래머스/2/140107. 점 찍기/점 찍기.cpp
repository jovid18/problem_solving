#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
using ll = long long;
long long solution2(ll k, ll d) {
    long long answer = 0;
    for (ll a = 0; a * k <= d; ++a) {
        answer += 1LL + (ll)floor(sqrt(d * d - (a * k) * (a * k))) / k;
    }
    return answer;
}
long long solution(int k, int d) { return solution2(k, d); }
