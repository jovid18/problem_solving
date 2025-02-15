#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int N;
using Board=vector<vector<int>>;
Board board;

void push(vector<int> &v){
	int n=v.size();
	v.erase(remove_if(v.begin(), v.end(), [](auto x) -> bool { return x == 0; }), v.end());
	if(v.empty()) return;
	for(int i=0;i<v.size()-1;++i){
		if(v[i]==v[i+1]){
			v[i]+=v[i+1];
			v[i+1]=0;
			++i;
		}
	}
	v.erase(remove_if(v.begin(), v.end(), [](auto x) -> bool { return x == 0; }), v.end());
	int s=n-v.size();
	for(int i=0;i<s;++i){
		v.push_back(0);
	}
}

Board commad(Board b,int c){
	int n=b.size();
	if(c==0){
		for(int i=0;i<n;++i){
			vector<int> v;
			for(int j=0;j<n;++j){
				v.push_back(b[j][i]);
			}
			push(v);
			for(int j=0;j<n;++j){
				b[j][i]=v[j];
			}
		}
	}else if(c==1){
		for(int i=0;i<n;++i){
			vector<int> v;
			for(int j=n-1;j>=0;--j){
			v.push_back(b[i][j]);
			}
			push(v);
			for(int j=n-1;j>=0;--j){
				b[i][j]=v[n-j-1];
			}
		}
	}else if(c==2){
		for(int i=0;i<n;++i){
			vector<int> v;
			for(int j=n-1;j>=0;--j){
			v.push_back(b[j][i]);
			}
			push(v);
			for(int j=n-1;j>=0;--j){
				b[j][i]=v[n-1-j];
			}
		}
	}else{
		for(int i=0;i<n;++i){
			vector<int> v;
			for(int j=0;j<n;++j){
				v.push_back(b[i][j]);
			}
			push(v);
			for(int j=0;j<n;++j){
				b[i][j]=v[j];
			}
		}
	}
	return b;
}
int findmax(Board b){
	int m=0;
	for(auto e: b){
		for(auto f:e){
			m=max(m,f);
		}
	}
	return m;
}
int Max=0;
void DFS(Board b,int n){
	if(n==5){
		Max=max(Max,findmax(b));
		return ;
	}
	for(int i=0;i<=3;++i){
		Board s=commad(b,i);
		DFS(s,n+1);
	}
}
int main(){
	cin>>N;
	board.resize(N);
	for(int i=0;i<N;++i){
		board[i].resize(N);
		for(int j=0;j<N;++j){
			cin>>board[i][j];
		}
	}
	DFS(board,0);
	cout<<Max;
}