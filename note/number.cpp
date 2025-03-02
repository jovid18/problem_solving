#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
#define pii pair<int, int>

const int MOD = 1e9 + 7;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int lcm(int a, int b) { return a / gcd(a, b) * b; }

// 약수 구하기
vector<int> get_divisor(int n) {
    vector<int> divisor;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            divisor.push_back(i);
            if (i * i != n) divisor.push_back(n / i);
        }
    }
    return divisor;
}

// 소인수분해
vector<int> prime_factorization(int n) {
    vector<int> prime_factor;
    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            prime_factor.push_back(i);
            n /= i;
        }
    }
    if (n > 1) prime_factor.push_back(n);
    return prime_factor;
}

// 에라토스테네스의 체
vector<bool> prime_number(int n) {
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) {
            for (int j = 2; j * i <= n; j++) is_prime[i * j] = false;
        }
    }
    return is_prime;
}

// 고속 거듭제곱
int fast_pow(int a, int b) {
    int ret = 1;
    while (b) {
        if (b & 1) ret = ret * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return ret;
}

// 역원 구하기 a^-1 mod p = a^(p-2) mod p
int inverse(int a) { return fast_pow(a, MOD - 2); }

// nCk
int comb(int n, int k) {
    int num = 1, den = 1;
    for (int i = 0; i < k; i++) {
        num = num * (n - i) % MOD;
        den = den * (i + 1) % MOD;
    }
    return num * inverse(den) % MOD;
}

// nHk
int homo(int n, int k) { return comb(n + k - 1, k); }

// a * i + b가 [x, y] 범위 내에 존재하는 i의 개수를 구하는 함수
int cnt(int a, int b, int x, int y) {
    if (a == 0) {
        if (b >= x && b <= y) return -1;
        return 0;
    }
    int minI = ceil((ld)(x - b) / a);
    int maxI = floor((ld)(y - b) / a);
    if (minI > maxI) return 0;
    return maxI - minI + 1;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    return 0;
}