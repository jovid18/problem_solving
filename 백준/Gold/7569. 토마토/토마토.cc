#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int warehouse[100][100][100];

struct tomato{
	int x;
	int y;
	int z;
	tomato(int a, int b,int c)
    {
		x=a;
		y=b;
		z=c;
    }
};
int n,m,l;
bool check(int x,int y,int z){
	if(0<=x&&x<n&&0<=y&&y<m&&0<=z&&z<l){
		return true;
	}else{
		return false;
	}
}
queue<tomato> ripen;

void BFS(queue<tomato> &ripen,int arr[100][100][100]){
	int max=ripen.size();
	for(int i=0;i<max;++i){
		int x=ripen.front().x;
		int y=ripen.front().y;
		int z=ripen.front().z;
		if(check(x-1,y,z)&&(*(*(*(arr+x-1)+y)+z)==0)){
			arr[x-1][y][z]=1;
			ripen.push(tomato(x-1,y,z));
		}
		if(check(x+1,y,z)&&(*(*(*(arr+x+1)+y)+z)==0)){
			arr[x+1][y][z]=1;
			ripen.push(tomato(x+1,y,z));
		}
		if(check(x,y-1,z)&&(*(*(*(arr+x)+y-1)+z)==0)){
			arr[x][y-1][z]=1;
			ripen.push(tomato(x,y-1,z));
		}
		if(check(x,y+1,z)&&(*(*(*(arr+x)+y+1)+z)==0)){
			arr[x][y+1][z]=1;
			ripen.push(tomato(x,y+1,z));
		}
		if(check(x,y,z+1)&&(*(*(*(arr+x)+y)+z+1)==0)){
			arr[x][y][z+1]=1;
			ripen.push(tomato(x,y,z+1));
		}
		if(check(x,y,z-1)&&(*(*(*(arr+x)+y)+z-1)==0)){
			arr[x][y][z-1]=1;
			ripen.push(tomato(x,y,z-1));
		}
		ripen.pop();
	}
}

int main(){
	int N,M,L;
	cin>>M>>N>>L;
	n=N;
	m=M;
	l=L;
	for(int i=0;i<L;++i){
		for(int j=0;j<N;++j){
			for(int k=0;k<M;++k){
				int num;
				cin>>num;
				if(num==1){
					ripen.push(tomato(j,k,i));
				}
				warehouse[j][k][i]=num;
			}
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
			for(int k=0;k<l;++k){
				if(*(*(*(warehouse+i)+j)+k)==0){
					zerocheck=true;
				}
			}
		}
	}
	if(zerocheck){
		cout<<-1;
	}else{
		cout<<count-1;
	}
	
}