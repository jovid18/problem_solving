#include <iostream>
#include <vector>
using namespace std;
vector<pair<int,int>> T(4000000,{0,0});
int N;
void change(int s,int f,int n,int d,int c){
	if(s==f) {
		T[n].first+=c;
		T[n].second+=c;
		return;
	}
	int m=(s+f)/2;
	if(d<=m) {
		T[n].first+=c;
		change(s,m,2*n,d,c);
	}else{
		T[n].second+=c;
		change(m+1,f,2*n+1,d,c);
	}
}
int query(int s,int f,int n,int r){
	if(s==f){
		T[n].first--;
		T[n].second--;
		return s;
	}
	int m=(s+f)/2;
	if(r<=T[n].first){
		T[n].first--;
		return query(s,m,2*n,r);
	}else{
		T[n].second--;
		return query(m+1,f,2*n+1,r-T[n].first);
	}
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N;
	for(int i=0;i<N;++i){
		int a,b,c;
		cin>>a;
		if(a==1){
			cin>>b;
			cout<<query(1,1000000,1,b)<<'\n';
		}else{
			cin>>b>>c;
			change(1,1000000,1,b,c);
		}
	}
}
