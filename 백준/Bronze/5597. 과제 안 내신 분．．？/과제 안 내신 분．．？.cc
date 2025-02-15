#include <iostream>
using namespace std;
bool S[31];
int s;
int main(){
    for (int i = 0;i < 28;++i) {
        cin >> s;
        S[s] = true;
    }
    for (int i = 1;i <= 30;++i) {
        if (!S[i]) cout << i << '\n';
    }
}