#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
const double pi = 3.14159265358979;
double a;
int main(){
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	cin>>a;
	cout<<fixed;
	cout.precision(15);
	cout<<(double)0.25*sqrt(3)*a*a;
}