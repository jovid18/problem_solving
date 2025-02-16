#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;
vector<vector<bool>> p;
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
vector<int> r;
string S;
int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	cin>>S;
	int n=S.size();
	p.assign(n,vector<bool> (n,false));
	for(int k=0;k<n;++k){
		p[k][k]=true;
		pq.push({k+1,k+1});
	}
	for(int k=0;k<n-1;++k){
		if(S[k]==S[k+1]){
			p[k+1][k]=true;
			pq.push({k+2,k+1});
		} 
	}
	for(int k=2;k<n;++k){
		for(int l=0;l<n-k;++l){
			if(p[k+l-1][l+1]&&(S[k+l]==S[l])){
				p[k+l][l]=true;
				pq.push({k+l+1,l+1});
			}
		}
	}
	r.assign(n+1,2501);
	r[0]=0;
	while(!pq.empty()){
		auto pair=pq.top();
		pq.pop();
		r[pair.first]=min(r[pair.first],r[pair.second-1]+1);
	}
	cout<<r[n];
	
}