#include <iostream>
using namespace std;

long long init = 6;
long long N;
int main()
{
    cin >> N;
    for (int i = 11;i <= N;++i) {
        init *= i;
    }
    cout << init;
}   
