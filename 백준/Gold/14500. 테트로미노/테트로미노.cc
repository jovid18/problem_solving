#include <iostream>
#include <vector>
#define up {-1,0}
#define up2 {-2,0}
#define down {1,0}
#define down2 {2,0}
#define left {0,-1}
#define left2 {0,-2}
#define right {0,1}
#define right2 {0,2}
#define downright {1,1}
#define downleft {1,-1}
using namespace std;
using pii=pair<int,int>;
int N,M;
int P[500][500];
pii T[19][3]={
	{left,right,right2},{up,down,down2},
	{right,down,downright},
	{up,down,downright},{down,right,right2},{left,down,down2},{left2,left,up},
	{up2,up,left},{up,right,right2},{right,down,down2},{left2,left,down},
	{up,right,downright},{right,down,downleft},
	{up,left,downleft},{left,down,downright},
	{down,right,left},{up,right,down},{up,left,down},{up,right,left}
};
bool out(int x, int y){
	if(x<0||y<0||x>=N||y>=M) return true;
	return false;
}
int main(){
	cin>>N>>M;
	for(int i=0;i<N;++i){
		for(int j=0;j<M;++j){
			cin>>P[i][j];
		}
	}
	int ans=0;
	for(int i=0;i<N;++i){
		for(int j=0;j<M;++j){
			if(out(i,j)) continue;
			for(int t=0;t<19;++t){
				int now=P[i][j];
				int cnt=0;
				for(;cnt<3;++cnt){
					int xi=i+T[t][cnt].first;
					int yi=j+T[t][cnt].second;
					if(out(xi,yi)) break;
					now+=P[xi][yi];
				}
				if(cnt==3) ans=max(ans,now);
			}
		}
	}
	cout<<ans;
}