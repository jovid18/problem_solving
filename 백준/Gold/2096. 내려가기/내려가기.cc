#include <iostream>
using namespace std;

int main(){
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int N;
	cin>>N;
	int max1, max2, max3, min1, min2, min3;
	cin>>max1>>max2>>max3;
	min1=max1;
	min2=max2;
	min3=max3;
	for(int i=1;i<N;++i){
		int a1,b1,c1,a2,b2,c2;
		cin>>a1>>b1>>c1;
		a2=a1;
		b2=b1;
		c2=c1;
		a1+=max(max1,max2);
		b1+=max(max(max1,max2),max3);
		c1+=max(max2,max3);
		a2+=min(min1,min2);
		b2+=min(min(min1,min2),min3);
		c2+=min(min2,min3);
		max1=a1;
		max2=b1;
		max3=c1;
		min1=a2;
		min2=b2;
		min3=c2;
	}
	cout<<max(max(max1,max2),max3)<<" "<<min(min(min1,min2),min3);
	
	
}