#include <iostream>
#include <string>
using namespace  std;
string comb[101][101]={"0"};

string sum(string a, string b){
	int as=a.size();
	int bs=b.size();
	if(as<bs){
		return sum(b,a);
	}
	int cs=max(as,bs);
	string c("0",cs+1);
	for(int i=a.size()-1;i>=0;--i){
		c[i-a.size()+c.size()]=a[i];
	}
	int lend=0;
	for(int i=b.size()-1;i>=0;--i){
		int front=b[i]-'0';
		int back=c[i-b.size()+c.size()]-'0';
		int sum=front+back+lend;
		if(sum<10){
			c[i-b.size()+c.size()]=sum+'0';
			lend=0;
		}else{
			sum-=10;
			c[i-b.size()+c.size()]=sum+'0';
			lend=1;
		}
	}
	for(int i=c.size()-b.size()-1;i>=0;--i){
		if(lend==1){
			int sum=c[i]-'0'+1;
			if(sum<10){
				c[i]=sum+'0';
				lend=0;
			}else{
				sum-=10;
				c[i]=sum+'0';
				lend=1;
			}
		}else{
			break;
		}
	}
	if(c[0]=='0'){
		c=c.substr(1);
	}
	return c;
};

int main(){
	for(int i=0;i<=100;++i){
		comb[i][0]="1";
		comb[i][i]="1";
	}
	for(int i=2; i<=100;++i){
		for(int j=1;j<i;++j){
			comb[i][j]=sum(comb[i-1][j-1],comb[i-1][j]);
		}
	}
	int N,M;
	cin>>N>>M;
	cout<<comb[N][M];
}
