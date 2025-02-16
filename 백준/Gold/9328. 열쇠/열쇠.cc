#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;
int T,h,w;
vector<vector<char>> m;
vector<vector<bool>> c;
queue<pair<int,int>> q;
vector<bool> havekey(26,0);
vector<queue<pair<int,int>>> doorlist(26);
string keylist;
int x[]={1,-1,0,0};
int y[]={0,0,1,-1};
bool in(int x,int y){
	return (x>=0&&x<h&&y>=0&&y<w);
}
int check(char a){
	if(a=='.'){
		return 0;
	}else if(a=='*'){
		return 1;
	}else if(a=='$'){
		return 2;
	}else if('A'<=a&&a<='Z'){
		return 3;
	}else{
		return 4;
	}
}

int main(){
	cin>>T;
	while(T--){
		int dollar=0;
		cin>>h>>w;
		m.assign(h,vector<char> (w,'0'));
		c.assign(h,vector<bool> (w,0));
		havekey.assign(26,0);
		doorlist.clear();
		doorlist.resize(26);
		for(int i=0;i<h;++i){
			for(int j=0;j<w;++j){
				cin>>m[i][j];
			}
		}
		cin>>keylist;
		if(keylist[0]!='0'){
			for(int i=0;i<keylist.size();++i){
				havekey[keylist[i]-'a']=true;
			}
		}
		for(int i=0;i<h;++i){
			for(int j=0;j<w;++j){
				if(i>0&&i<h-1&&j>0&&j<w-1) continue;
				int n=check(m[i][j]);
				if(n==0){
					q.push({i,j});
					c[i][j]=true;
				}else if(n==1){
					continue;
				}else if(n==2){
					q.push({i,j});
					dollar++;
					c[i][j]=true;
				}else if(n==3){
					int num=m[i][j]-'A';
					if(havekey[num]){
						q.push({i,j});
						c[i][j]=true;
					}else{
						doorlist[num].push({i,j});
					}
				}else{
					int num=m[i][j]-'a';
					havekey[num]=true;
					q.push({i,j});
					c[i][j]=true;
					while(!doorlist[num].empty()){
						auto p=doorlist[num].front();
						doorlist[num].pop();
						q.push({p.first,p.second});
						c[p.first][p.second]=true;
					}
				}
			}
		}
		while(!q.empty()){
			auto p=q.front();
			q.pop();
			for(int i=0;i<4;++i){
				int xi=p.first+x[i];
				int yi=p.second+y[i];
				if(!in(xi,yi)) continue;
				if(c[xi][yi]) continue;
				int n=check(m[xi][yi]);
				if(n==0){
					q.push({xi,yi});
					c[xi][yi]=true;
				}else if(n==1){
					continue;
				}else if(n==2){
					q.push({xi,yi});
					dollar++;
					c[xi][yi]=true;
				}else if(n==3){
					int num=m[xi][yi]-'A';
					if(havekey[num]){
						q.push({xi,yi});
						c[xi][yi]=true;
					}else{
						doorlist[num].push({xi,yi});
					}
				}else{
					int num=m[xi][yi]-'a';
					havekey[num]=true;
					q.push({xi,yi});
					c[xi][yi]=true;
					while(!doorlist[num].empty()){
						auto p=doorlist[num].front();
						doorlist[num].pop();
						q.push({p.first,p.second});
						c[p.first][p.second]=true;
					}
				}
			}
		}
		cout<<dollar<<endl;
	}
}
