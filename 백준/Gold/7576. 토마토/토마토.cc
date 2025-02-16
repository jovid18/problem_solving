#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int warehouse[1000][1000];

struct tomato{
	int x;
	int y;
	tomato(int a, int b)
    {
		x=a;
		y=b;
    }
};
int n,m;
bool check(int x,int y){
	if(0<=x&&x<n&&0<=y&&y<m){
		return true;
	}else{
		return false;
	}
}
queue<tomato> ripen;

void BFS(queue<tomato> &ripen,int arr[1000][1000]){
	int max=ripen.size();
	for(int i=0;i<max;++i){
		int x=ripen.front().x;
		int y=ripen.front().y;
		if(check(x-1,y)&&(*(*(arr+x-1)+y)==0)){
			arr[x-1][y]=1;
			ripen.push(tomato(x-1,y));
		}
		if(check(x,y-1)&&(*(*(arr+x)+y-1)==0)){
			arr[x][y-1]=1;
			ripen.push(tomato(x,y-1));
		}
		if(check(x+1,y)&&(*(*(arr+x+1)+y)==0)){
			arr[x+1][y]=1;
			ripen.push(tomato(x+1,y));
		}
		if(check(x,y+1)&&(*(*(arr+x)+y+1)==0)){
			arr[x][y+1]=1;
			ripen.push(tomato(x,y+1));
		}
		ripen.pop();
	}
}

int main(){
	int N,M;
	cin>>M>>N;
	n=N;
	m=M;
	for(int i=0;i<N;++i){
		for(int j=0;j<M;++j){
			int num;
			cin>>num;
			if(num==1){
				ripen.push(tomato(i,j));
			}
			warehouse[i][j]=num;
		}
	}
	int count=0;

	while(!ripen.empty()){
		BFS(ripen,warehouse);
		count++;
	}
	int zerocheck=false;;
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			if(*(*(warehouse+i)+j)==0){
				zerocheck=true;
			}
		}
	}
	if(zerocheck){
		cout<<-1;
	}else{
		cout<<count-1;
	}
	
}