#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using pii = pair<int, int>;
int N;
vector<pii> V;
bool comp(const pii &a, const pii &b) {
    if (a.second == b.second)
        return a.first < b.first;
    return a.second < b.second;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;
    V.resize(N);
    for (int i = 0; i < N; ++i) {
        cin >> V[i].first >> V[i].second;
    }
    sort(V.begin(), V.end(), comp);
    for (auto e : V) {
        cout << e.first << " " << e.second << '\n';
    }
}