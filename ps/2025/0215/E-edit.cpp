#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// https://atcoder.jp/contests/abc393/tasks/abc393_e
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (auto& a : A) cin >> a;
    // A의 원소 중 최댓값
    int M = *max_element(begin(A), end(A));
    // s[d] = A의 원소 중 d의 개수
    // t[d] = A의 원소 중 d의 배수의 개수
    // u[d] = A[i] = d일때의 정답
    vector<int> s(M + 1), t(M + 1), u(M + 1);
    for (auto& a : A) s[a]++;
    // 시간복잡도: O(M * sqrt(M))
    for (int d = 1; d <= M; d++) {
        for (int n = d; n <= M; n += d) {
            t[d] += s[n];
        }
    }
    // 시간복잡도: O(M * sqrt(M))
    for (int d = 1; d <= M; d++) {
        if (t[d] < K) continue;
        // t[d] >= K
        for (int n = d; n <= M; n += d) {
            u[n] = max(u[n], d);
        }
    }
    for (auto& a : A) cout << u[a] << "\n";
}