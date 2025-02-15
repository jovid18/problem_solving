#include <iostream>
#include <string>
#include <map>
using namespace std;
int N, M;
map<string, string> P;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    for (int i = 0;i < N;++i) {
        string a, b;
        cin >> a >> b;
        P[a] = b;
    }
    for (int i = 0;i < M;++i) {
        string a;
        cin >> a;
        cout << P[a] << '\n';
    }
}
