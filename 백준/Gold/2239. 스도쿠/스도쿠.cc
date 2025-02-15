#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> sdoku(9,vector<int> (9,0));
vector<vector<bool>> checked(9,vector<bool> (9,false));
vector<vector<int>> answer;
bool checking(int x, int y, int n){
	for(int i=0;i<9;++i){
		if(sdoku[i][y]==n){
			return false;
		}
	}
	for(int i=0;i<9;++i){
		if(sdoku[x][i]==n){
			return false;
		}
	}
	int x1=(x/3)*3;
	int y1=(y/3)*3;
	for(int i=0;i<3;++i){
		for(int j=0;j<3;++j){
			if(sdoku[x1+i][y1+j]==n){
				return false;
			}
		}
	}
	return true;
}

void DFS(int count){
	if(count==81){
		for(auto e:sdoku){
			for(auto f:e){
				cout<<f;
			}
			cout<<endl;
		}
		exit(0);
	}
	int x=count/9;
	int y=count%9;
	if(sdoku[x][y]!=0){
		DFS(count+1);
	}else{
		for(int i=1;i<=9;++i){
			if(checking(x,y,i)){
				sdoku[x][y]=i;
				DFS(count+1);
				sdoku[x][y]=0;
			}
		}
	}
}


int main(){
	for(int i=0;i<9;++i){
		for(int j=0;j<9;++j){
			char a;
			cin>>a;
			sdoku[i][j]=a-'0';
		}
	} 
	DFS(0);
	
}