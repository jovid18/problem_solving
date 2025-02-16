#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main(){
	int N,M;
	cin>>N>>M;
	char chess[N][M]={'a'};
	for(int i=0;i<N;++i){
		for(int j=0;j<M;++j){
			char ch=cin.get();
			if(ch=='\n'){
				ch=cin.get();
			}
			chess[i][j]=ch;
		}
	}
	
	int m=64;
	for(int i=0;i<N-7;++i){
		for(int j=0;j<M-7;++j){
			int x=0;
			for(int a=0;a<8;++a){
				for(int b=0;b<8;++b){
					if(((a+b)%2==1)&&(chess[i+a][j+b]!='W')){
						x++;
					}
					if(((a+b)%2==0)&&(chess[i+a][j+b]!='B')){
						x++;
					}
				}
			}
			int y=0;
			for(int a=0;a<8;++a){
				for(int b=0;b<8;++b){
					if(((a+b)%2==1)&&(chess[i+a][j+b]!='B')){
						y++;
					}
					if(((a+b)%2==0)&&(chess[i+a][j+b]!='W')){
						y++;
					}
				}
			}
			m=min({m,x,y});
		}
	}
	cout<<m<<endl;
	
	return 0;
	
}