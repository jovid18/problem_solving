#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int answer = 0;
bool isPrime(long long  n) {
    if (n == 1 || n == 0) {
        return false;
    }
    for (long long i = 2; i <= sqrt(n); ++i) {
        if (n % i == 0)
            return false;
    }
    return true;
}
int solution(int n, int k) {
    string s = "";
    while (n != 0) {
        s += '0' + (n % k);
        n -= n % k;
        n /= k;
    }
    reverse(s.begin(), s.end());
    s += '0';
    vector<string> num;
    string now = "";
    for (auto e : s) {
        if (e == '0') {
            if(now=="") continue;
            num.push_back(now);
            now = "";
        }
        now += e;
    }
    for (auto e : num) {
        if(e=="") continue;
        long long f = stoll(e);
        if (isPrime(f)) {
            answer++;
        }
    }
    return answer;
}