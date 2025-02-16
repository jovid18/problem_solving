#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> num;
vector<int> checked;
int group[9]={0};
int n,m;
void dfs(int count,vector<int> &num,vector<int>&checked){
	if(count==m){
		for(int i=0;i<m;++i){
			cout<<group[i]<<" ";
 		}
 		cout<<'\n';
 		return;
	}
	for(int i=0;i<n;++i){
		if(count==0){
			checked[i]=true;
			group[count]=num[i];
			dfs(count+1,num,checked);
			checked[i]=false;
		}else if(group[count-1]<=num[i]){
			checked[i]=true;
			group[count]=num[i];
			dfs(count+1,num,checked);
			checked[i]=false;
		}
	}
	
}
int main(){
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	cin>>n>>m;
	num.resize(n);
	checked.resize(n);
	for(int i=0;i<n;++i){
		cin>>num[i];
	}
	sort(num.begin(),num.end());
	dfs(0,num,checked);
}
