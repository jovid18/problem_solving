#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
const double pi = 3.14159265358979;
double K,D1,D2;

int main(){
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	cin>>K>>D1>>D2;
	cout<<K*K-(D1-D2)*(D1-D2)/4;
}