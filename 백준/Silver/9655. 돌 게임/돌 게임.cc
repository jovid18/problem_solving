#include <iostream>
#include <set>
using namespace std;
int N;
int main(){
	cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
	cin>>N;
	cout<<((N&1) ? "SK":"CY");
}
