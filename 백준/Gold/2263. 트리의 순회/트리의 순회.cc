#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> in;
vector<int> po;

void pre(int a, int b, int c,int d){
	int size=b-a+1;
	int root=po[d];
	int flag;
	for(int i=a;i<=b;++i){
		if(in[i]==root){
			flag=i;
			break;
		}
	}
	cout<<root<<" ";
	if(flag!=a){
		pre(a,flag-1,c,c-a+flag-1);
	}
	if(flag!=b){
		pre(flag+1,b,c-a+flag,d-1);
	}
	
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N;
	in.resize(N);
	po.resize(N);
	for(int i=0;i<N;++i){
		cin>>in[i];
	}
	for(int i=0;i<N;++i){
		cin>>po[i];
	}
	pre(0,N-1,0,N-1);
	
}