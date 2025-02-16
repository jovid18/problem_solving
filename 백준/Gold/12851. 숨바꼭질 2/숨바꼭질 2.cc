#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
bool finish=false;
int s,f;
int Time=0;
queue<int> process;
int num[100001]={0};
bool check[100001]={false};

void DFS(){
	int temp[100001]={0};
	vector<int> add;
	int size=process.size();
	for(int i=0;i<size;++i){
		int x=process.front();
		if(x-1>=0){
			if(!check[x-1]){
				process.push(x-1);
				check[x-1]=true;
			} 
			if(x-1==s){
				finish=true;
			}
			temp[x-1]+=num[x];
			add.push_back(x-1);
		}
		if(x+1<=100000){
			if(!check[x+1]){
				process.push(x+1);
				check[x+1]=true;
			} 
			if(x+1==s){
				finish=true;
			}
			temp[x+1]+=num[x];
			add.push_back(x+1);
		}
		if(x%2==0){
			if(!check[x/2]){
				process.push(x/2);
				check[x/2]=true;
			} 
			if(x/2==s){
				finish=true;
			}
			temp[x/2]+=num[x];
			add.push_back(x/2);
		}
		process.pop();
	}
	sort(add.begin(),add.end());
	add.erase(unique(add.begin(),add.end()),add.end());
	for(int i=0;i<add.size();++i){
		if(num[add[i]]==0){
			num[add[i]]=temp[add[i]];
		}else{
			num[add[i]]*=temp[add[i]];
		}
	}
}
int main(){
	cin>>s>>f;
	if(s==f){
		cout<<0<<endl<<1;
		return 0;
	}
	process.push(f);
	check[f]=true;
	num[f]=1;
	while(!finish){
		DFS();
		Time++;
	}
	cout<<Time<<endl;
	cout<<num[s];
}