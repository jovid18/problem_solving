#include <iostream>
using namespace std;
int group[9]={0};
int n,m;
void dfs(int count){
	if(count==m){
		for(int i=0;i<m;++i){
			cout<<group[i]<<" ";
 		}
 		cout<<endl;
 		return;
	}
	for(int i=1;i<=n;++i){
		if(count==0){
			group[count]=i;
			dfs(count+1);
		}else if(group[count-1]<=i){
			group[count]=i;
			dfs(count+1);
		}
	}
	
}
int main(){
	cin>>n>>m;
	dfs(0);
}