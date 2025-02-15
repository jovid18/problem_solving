#include <iostream>
#include <string>
using namespace std;
string s;
int c[26];
int main(){
    cin >> s;
    for (auto e : s) {
        c[e - 'a']++;
    }
    for (int i = 0;i < 26;++i) {
        cout << c[i] << " ";
    }
}
