#include <iostream>
#include <string>
#include <map>
using namespace std;
int T,N;
map<string, int> P;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> T;
    while (T--) {
        P.clear();
        cin >> N;
        if (N == 0) {
            cout << 0 << '\n';
            continue;
        }
        for (int i = 0;i < N;++i) {
            string a, b;
            cin >> a >> b;
            if (P.find(b) != P.end()) P[b]++;
            else P[b] = 1;
        }
        int ans = 1;
        for (auto e : P) {
            ans *= (e.second+1);
        }
        cout << ans-1 << '\n';
    }
}
