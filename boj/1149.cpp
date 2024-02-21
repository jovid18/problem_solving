#include <iostream>
#include <vector>
using namespace std;
int min(int a, int b) {
    if (a > b) {
        return b;
    } else {
        return a;
    }
}

int main() {
    vector<int> R;
    vector<int> G;
    vector<int> B;
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int r, g, b;
        cin >> r >> g >> b;
        R.push_back(r);
        G.push_back(g);
        B.push_back(b);
    }
    vector<int> RR(N);
    vector<int> GG(N);
    vector<int> BB(N);
    RR[0] = R[0];
    GG[0] = G[0];
    BB[0] = B[0];
    for (int i = 0; i < N; ++i) {
        RR[i] = R[i] + min(GG[i - 1], BB[i - 1]);
        GG[i] = G[i] + min(RR[i - 1], BB[i - 1]);
        BB[i] = B[i] + min(GG[i - 1], RR[i - 1]);
    }
    int a = min(GG[N - 1], BB[N - 1]);
    int b = min(a, RR[N - 1]);
    cout << b;
}
