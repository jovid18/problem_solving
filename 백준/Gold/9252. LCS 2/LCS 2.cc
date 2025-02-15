#include <iostream>
#include <string>
#include <vector>
using namespace  std;
vector<vector<int>> lcs(1001,vector<int>(1001,0));

int main(){
	string a,b;
	cin>>a>>b;
	int n=a.size();
	int m=b.size();
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			if(a[i-1]==b[j-1]){
				lcs[i][j]=lcs[i-1][j-1]+1;
			}else{
				lcs[i][j]=max(lcs[i-1][j],lcs[i][j-1]);
			}
		}
	}
	int l=lcs[n][m];
	if(l==0){
		cout<<l;
	}
	else{
	cout<<l<<endl;
	string sample;
	sample.resize(l);
	int count=l;
	int i=n;
	int j=m;
	while(count>0){
		if(lcs[i][j]==lcs[i-1][j]){
			i=i-1;
		}else if(lcs[i][j]==lcs[i][j-1]){
			j=j-1;
		}else{
			sample[count-1]=a[i-1];
			i=i-1;
			j=j-1;
			count--;
		}
	}
	cout<<sample;
	}
}
