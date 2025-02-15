#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
const double pi = 3.14159265358979;
double D,H,W;
int main(){
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	cin>>D>>H>>W;
	int h=H*sqrt(D*D/(W*W+H*H));
	int d=W*sqrt(D*D/(W*W+H*H));
	cout<<h<<" "<<d;
}