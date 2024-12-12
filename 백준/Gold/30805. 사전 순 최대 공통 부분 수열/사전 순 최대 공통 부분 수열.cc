#include <bits/stdc++.h>
using namespace std;
#define int long long
int N, M;
vector<int> A, B, ANS;
int Aidx = 0, Bidx = 0;
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    A.resize(N);
    for (auto &e : A) {
        cin >> e;
    }
    cin >> M;
    B.resize(M);
    for (auto &e : B) {
        cin >> e;
    }
    for (int k = 100; k >= 1; --k) {
        int Acnt = 0, Bcnt = 0;
        for (int i = Aidx; i < N; ++i) {
            if (A[i] == k) {
                ++Acnt;
            }
        }
        for (int i = Bidx; i < M; ++i) {
            if (B[i] == k) {
                ++Bcnt;
            }
        }
        int minCnt = min(Acnt, Bcnt);
        if (minCnt == 0) continue;
        Acnt = 0;
        Bcnt = 0;
        for (int i = Aidx; i < N; ++i) {
            if (A[i] == k) {
                Acnt++;
                if (Acnt == minCnt) {
                    Aidx = i + 1;
                    break;
                }
            }
        }
        for (int i = Bidx; i < M; ++i) {
            if (B[i] == k) {
                Bcnt++;
                if (Bcnt == minCnt) {
                    Bidx = i + 1;
                    break;
                }
            }
        }
        for (int i = 0; i < minCnt; ++i) {
            ANS.push_back(k);
        }
    }
    cout << ANS.size();
    if (ANS.size() == 0) return 0;
    cout << '\n';
    for (auto e : ANS) {
        cout << e << ' ';
    }
}