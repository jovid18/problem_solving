#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int group[9]={0};
vector<int> num;
int n,m;
vector<vector<int>> answer(1);
int flag=0;
void DFS(int count,vector<vector<int>> &answer,vector<int> num){
	if(count==m){
		for(int i=0;i<m;++i){
			answer[flag].push_back(group[i]);
		}
		flag++;
		answer.resize(flag+1);
		return;
	}
	for(int i=0;i<n;++i){
		if(count==0){
			group[count]=num[i];
			DFS(count+1,answer,num);
		}else if(group[count-1]<=num[i]){
			group[count]=num[i];
			DFS(count+1,answer,num);
		}
	}
	
}
int main(){
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	cin>>n>>m;
	for(int i=0;i<n;++i){
		int a;
		cin>>a;
		num.push_back(a);
	}
	sort(num.begin(),num.end());
	DFS(0,answer,num);
	answer.erase(answer.end() - 1);
	sort(answer.begin(),answer.end());
	answer.erase(unique(answer.begin(),answer.end()),answer.end());
	for(auto e: answer){
		for(auto f: e){
			cout<<f<<" ";
		}
		cout<<'\n';
	}
	
}