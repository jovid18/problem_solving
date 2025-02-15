#include <iostream>
using namespace std;
const double pi = 3.14159265358979;
int N;
int main(){
	cin>>N;
	cout<<fixed;
	cout.precision(6);
	cout<<pi*N*N<<'\n';
	cout<<2*N*N<<'\n';
}