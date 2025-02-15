#include <iostream>
using namespace std;
int D,P,Q;
int main(){
	cin>>D>>P>>Q;
	if(P<Q) swap(P,Q);
	int t=D/P;
	int ans=2e9;
	if(D%P==0){
		ans=D;
		cout<<ans;
		return 0;
	}
	for(int i=t+1;i>=0;--i){
		if(i*P>=D){
			ans=min(ans,i*P);
			continue;
		}
		int s=(D-i*P)/Q;
		if((D-i*P)%Q==0){
			ans=D;
			break;
		}
		if(ans==i*P+(s+1)*Q) break;
		ans=min(ans,i*P+(s+1)*Q);
	}
	cout<<ans;
}