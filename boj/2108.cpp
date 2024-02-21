#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
int N, sum;
int C[8001];
vector<int> V;
int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    V.resize(N);
    for (int i = 0; i < N; ++i) {
        cin >> V[i];
        sum += V[i];
        C[V[i] + 4000]++;
    }
    sort(V.begin(), V.end());
    int avg = round((double)sum / (double)N);
    cout << avg << '\n';
    cout << V[(N - 1) / 2] << '\n';
    int maxcnt = 0;
    ;
    for (int i = 0; i < 8001; ++i) {
        maxcnt = max(maxcnt, C[i]);
    }
    vector<int> M;
    for (int i = 0; i < 8001; ++i) {
        if (C[i] == maxcnt)
            M.push_back(i - 4000);
    }
    if (M.size() == 1)
        cout << M[0] << '\n';
    else
        cout << M[1] << '\n';
    cout << V.back() - V.front();
}