#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
int N;
string S;
queue <int> Q;
int main(){
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	cin>>N>>S;
	int l=0;
	int r=0;
	int g=0;
	for(int i=0;i<N;++i){
		if(S[i]=='('){
			l++;
		}else if(S[i]==')'){
			r++;
		}else{
			g++;
		}
	}
	int nl=N/2-l;
	int nr=N/2-r;
	for(int i=0;i<N&&nl>0;++i){
		if(S[i]=='G'){
			S[i]='(';
			nl--;
		}
	}
	for(int i=0;i<N&&nr>0;++i){
		if(S[i]=='G'){
			S[i]=')';
			nr--;
		}
	}
	cout<<S;
}