#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int T;
int a,b,x;
int gcd(int a, int b){
    if(a<b) swap(a,b);
    if(b==0) return a;
    else return gcd(b, a%b);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>T;
    while(T--){
        cin>>a>>b;
        while(1){
            if(b%a==0){
                cout<<b/a<<'\n';
                break;
            }else
                x=b/a+1;
            a=a*x-b;
            b=b*x;
        }
    }
}
