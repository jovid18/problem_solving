#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
vector<int> A,B,L,R,num,ans;
bool prime[2001] = { false };
vector<bool> visited;
vector<vector<int>> edge;
int N;
bool dfs(int a,int x){
	visited[a]=true;
	for(auto b:edge[a]){
		if(b==x) continue;
		if(B[b] == -1 || (!visited[B[b]] && dfs(B[b],x))){
            A[a] = b;
            B[b] = a;
            return true;
        }
	}
	return false;
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N;
	num.resize(N);
	for(int i=0;i<N;++i){
		cin>>num[i];
	}
	edge.resize(N);
	for(int i=0;i<N;++i){
		if((num[i]+num[0])%2==0){
			L.push_back(num[i]);
		}else{
			R.push_back(num[i]);
		}
	}
	
	prime[0] = prime[1] = true;
	for (int i = 2; i < sqrt(2000); i++){
		if (prime[i] == false){
			for (int j = 2*i; j <= 2000; j += i){
				prime[j] = true;
			}
		}
	}
	for(int i=0;i<L.size();++i){
		for(int j=0;j<R.size();++j){
			if(!prime[L[i]+R[j]]){
				edge[i].push_back(j);
			}
		}
	}
	for(auto e:edge[0]){
		A.assign(L.size(),-1);
		B.assign(R.size(),-1);
		visited.assign(L.size(),false);
		int match=1;
		for(int j=1;j<L.size(); j++){
			if(A[j] == -1){
				visited.assign(L.size(),false);
				if(dfs(j,e)) {
					match++;
				}
			}
		}
		if(match==(N/2)){
			ans.push_back(R[e]);
		}
	}
	if(ans.size()==0){
		cout<<-1;
		return 0;
	}
	sort(ans.begin(),ans.end());
	for(auto e: ans){
		cout<<e<<" ";
	}
}