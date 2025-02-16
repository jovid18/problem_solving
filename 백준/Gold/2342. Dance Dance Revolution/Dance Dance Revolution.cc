#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
struct DDR{
	int first;
	int second;
	int power;
	DDR(int a=0, int b=0, int c=1000000){
		if(a>b){
			swap(a,b);
			first=a;
			second=b;
			power=c;
		}
	}
};
int power(int l, int r, int hope, int leg){
	if(leg==0){
		if(r==hope) return 1000000;
		if(l==hope){
			return 1;
		}else if(l==0){
			return 2;
		}else if(abs(l-hope)==2){
			return 4;
		}else{
			return 3;
		}
	}else{
		if(l==hope) return 1000000;
		if(r==hope){
			return 1;
		}else if(r==0){
			return 2;
		}else if(abs(r-hope)==2){
			return 4;
		}else{
			return 3;
		}
	}
}

int index(int a, int b){
	if(a>b){
		swap(a,b);
	}
	if(a==0){
		if(b==1) return 0;
		if(b==2) return 1;
		if(b==3) return 2;
		if(b==4) return 3;
	}else if(a==1){
		if(b==2) return 4;
		if(b==3) return 5;
		if(b==4) return 6;
	}else if(a==2){
		if(b==3) return 7;
		if(b==4) return 8;
	}
	return 9;
}
vector<vector<DDR>> dp(10);
vector<int> com;
int main(){
	int a;
	while(cin>>a&&a!=0){
		com.push_back(a);
	}
	int N=com.size();
	if(N==0){
		cout<<0;
		return 0;
	}
	for(int i=0;i<10;++i){
		dp[i].resize(N);
		for(int j=0;j<N;++j){
			dp[i][j].first=0;
			dp[i][j].second=0;
			dp[i][j].power=1000000;
		}
	}
	
	dp[index(0,com[0])][0].first=0;
	dp[index(0,com[0])][0].second=com[0];
	dp[index(0,com[0])][0].power=2;
	
	for(int i=0;i<N-1;++i){
		for(int j=0;j<10;++j){
			if(dp[j][i].power==1000000) continue;
			int p1=power(dp[j][i].first,dp[j][i].second,com[i+1],0);
			if(dp[j][i].power+p1<=dp[index(com[i+1],dp[j][i].second)][i+1].power){
				dp[index(com[i+1],dp[j][i].second)][i+1].first=min(com[i+1],dp[j][i].second);
				dp[index(com[i+1],dp[j][i].second)][i+1].second=max(com[i+1],dp[j][i].second);
				dp[index(com[i+1],dp[j][i].second)][i+1].power=dp[j][i].power+p1;
			}
			int p2=power(dp[j][i].first,dp[j][i].second,com[i+1],1);
			if(dp[j][i].power+p2<=dp[index(dp[j][i].first,com[i+1])][i+1].power){
				dp[index(dp[j][i].first,com[i+1])][i+1].first=min(com[i+1],dp[j][i].first);
				dp[index(dp[j][i].first,com[i+1])][i+1].second=max(com[i+1],dp[j][i].first);
				dp[index(dp[j][i].first,com[i+1])][i+1].power=dp[j][i].power+p2;
			}
		}
	}
	int answer=1000000;
	for(int i=0;i<10;++i){
		answer=min(answer,dp[i][N-1].power);
	}
	cout<<answer;
	
}