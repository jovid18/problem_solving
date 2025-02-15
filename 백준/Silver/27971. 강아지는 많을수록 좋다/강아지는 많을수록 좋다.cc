#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
int N,M,A,B;
bool C[100001];
bool S[100001];
queue <int> Q;
int main(){
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	cin>>N>>M>>A>>B;
	for(int i=0;i<M;++i){
		int a,b;
		cin>>a>>b;
		for(int j=a;j<=b;++j){
			C[j]=true;
		}
	}
	Q.push(0);
	S[0]=true;
	int ans=0;
	while(!Q.empty()){
		int n=Q.size();
		while(n--){
			int front=Q.front();
			if(front==N){
				cout<<ans;
				return 0;
			}
			Q.pop();
			if((front+A<=N)&&!C[front+A]&&!S[front+A]){
				Q.push(front+A);
				S[front+A]=true;
			}
			if((front+B<=N)&&!C[front+B]&&!S[front+B]){
				Q.push(front+B);
				S[front+B]=true;
			}
		}
		ans++;
	}
	cout<<-1;
}