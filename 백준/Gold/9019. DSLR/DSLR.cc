#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
using namespace std;
using pic=pair<int,char>;
int T;
int A,B;
vector<pic> G[10000];
bool visited[10000];
void find(int A,int B){
	memset(visited,0,sizeof(visited));
	queue<pair<int,string>> q;
	q.push({A,""});
	visited[A]=true;
	while(!q.empty()){
		int N=q.front().first;
		string str=q.front().second;
		q.pop();
		if(N==B){
			cout<<str<<'\n';
			return;
		}
		for(auto e:G[N]){
			if(visited[e.first]) continue;
			visited[e.first]=true;
			q.push({e.first,str+e.second});
		}
	}
}
int main(){
	for(int i=0;i<10000;++i){
		G[i].push_back({(2*i)%10000,'D'});
		G[i].push_back({(i+9999)%10000,'S'});
		G[i].push_back({10*i%10000+i/1000,'L'});
		G[i].push_back({i/10+1000*(i%10),'R'});
	}
	cin>>T;
	while(T--){
		cin>>A>>B;
		find(A,B);
	}
}
