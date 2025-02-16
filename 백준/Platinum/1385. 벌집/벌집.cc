#include <iostream>
#include <vector>
#include <queue>
using namespace std;
queue<pair<int,int>> process;
int mx[]={0,1,1,0,-1,-1};
int my[]={1,0,-1,-1,0,1};
int c[6]={1,1,1,1,2,1};
vector<vector<int>> comb(2000,vector<int> (2000,0));
vector<pair<int,int>> position(1000001,{0,0});
int s,f;
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	comb[1000][1000]={1};
	position[1]={1000,1000};
	comb[999][1000]={2};
	position[2]={999,1000};
	int x=999;
	int y=1000;
	int mod=0;
	for(int i=3;i<=1000000;){
		for(int j=0;j<c[mod]&&i<=1000000;++j){
			x+=mx[mod];
			y+=my[mod];
			comb[x][y]=i;
			position[i]={x,y};
			i++;
		}
		c[mod]++;
		mod++;
		if(mod==6) mod=0;
	}
	cin>>s>>f;
	auto start=position[s];
	auto finish=position[f];
	auto a=-finish.first+start.first;
	auto b=-finish.second+start.second;
	pair<int,int> diff={a,b};
	pair <int,int> zero={0,0};
	cout<<s<<" ";
	while(diff!=zero){
	while(diff.first*diff.second<0){
		if(diff.first<0){
			diff.first++;
			start.first++;
			diff.second--;
			start.second--;
			cout<<comb[start.first][start.second]<<" ";
		}else{
			diff.first--;
			start.first--;
			diff.second++;
			start.second++;
			cout<<comb[start.first][start.second]<<" ";
		}
	}
	while(diff.first!=0){
		if(diff.first<0){
			diff.first++;
			start.first++;
			cout<<comb[start.first][start.second]<<" ";
		}else{
			diff.first--;
			start.first--;
			cout<<comb[start.first][start.second]<<" ";
		}
	}
	while(diff.second!=0){
		if(diff.second<0){
			diff.second++;
			start.second++;
			cout<<comb[start.first][start.second]<<" ";
		}else{
			diff.second--;
			start.second--;
			cout<<comb[start.first][start.second]<<" ";
		}
	}
	}
	

	
}