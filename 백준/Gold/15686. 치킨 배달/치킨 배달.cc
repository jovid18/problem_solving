#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
struct point {
	int a;
	int b;
	point(int c, int d){
		a=c;
		b=d;
	}
};

vector<point> house;
vector<point> chicken;
bool checked[13]={false};
int N,M;
int MAX=1000000000;
void chdis (vector<point> &house,vector<point> &chicken){
	int distance=0;
	for(auto e: house){
		int onedis=100;
		for(int i=0;i<chicken.size();++i){
			if(checked[i]){
				int twodis=abs(e.a-chicken[i].a)+abs(e.b-chicken[i].b);
				if(onedis>twodis){
						onedis=twodis;
				}	
			}
		}	
		distance+=onedis;
	}
	MAX=min(MAX,distance);
}
void dfs(int x,int count,vector<point> &house,vector<point> &chicken){
	if(count==M){
		chdis(house,chicken);
		return;
	}
	for(int i=x;i<chicken.size();++i){
		if(!checked[i]){
			checked[i]=true;
			dfs(i+1,count+1,house,chicken);
			checked[i]=false;	
		}	
	}	
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N>>M;
	for(int i=0;i<N;++i){
		for(int j=0;j<N;++j){
			int a;
			cin>>a;
			if(a==1){
				house.push_back(point(i,j));
			}else if(a==2){
				chicken.push_back(point(i,j));
			}
		}
	}
	dfs(0,0,house, chicken);
	cout<<MAX;
}
