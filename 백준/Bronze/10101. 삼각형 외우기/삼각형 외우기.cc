#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> A(3,0);
int main(){
	cin>>A[0]>>A[1]>>A[2];
	sort(A.begin(),A.end());
	int sum=0;
	for(auto e:A){
		sum+=e;
	}
	if(sum!=180){
		cout<<"Error";
		return 0;
	}
	if(A[0]==A[1]&&A[1]==A[2]){
		cout<<"Equilateral";
		return 0;
	}
	if(A[0]==A[1]||A[1]==A[2]){
		cout<<"Isosceles";
		return 0;
	}
	cout<<"Scalene";
	
}