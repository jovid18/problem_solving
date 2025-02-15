#include <iostream>
#include <vector>
using namespace std;
int R,C;
int Min=1e9;
pair<int,int> Minp;
vector<vector<int>> M;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>R>>C;
	Minp={0,1};
	M.assign(R,vector<int>(C,0));
	for(int i=0;i<R;++i){
		for(int j=0;j<C;++j){
			cin>>M[i][j];
			if((i+j)%2){
				if(Min>M[i][j]){
					Min=M[i][j];
					Minp={i,j};
				}
			}
		}
	}
	if(R%2){
		for(int i=1;i<=R;++i){
			if(i%2){
				for(int j=1;j<C;++j){
					cout<<'R';
				}
				if(i!=R) cout<<'D';
			}else{
				for(int j=1;j<C;++j){
					cout<<'L';
				}
				cout<<'D';
			}
		}
	}else if(C%2){
		for(int i=1;i<=C;++i){
			if(i%2){
				for(int j=1;j<R;++j){
					cout<<'D';
				}
				if(i!=C) cout<<'R';
			}else{
				for(int j=1;j<R;++j){
					cout<<'U';
				}
				cout<<'R';
			}
		}
	}else{
		for(int ri=0;ri<(R/2);++ri){
			if(ri==(Minp.first)/2){
				for(int j=0;j<C-1;++j){
					if(j%2){
						if(j<Minp.second){
							cout<<"UR";
						}else if(j==Minp.second){
							cout<<"R";
						}else{
							cout<<"DR";
						}
					}else{
						if(j<Minp.second){
							cout<<"DR";
						}else if(j==Minp.second){
							cout<<"R";
						}else{
							cout<<"UR";
						}
					}
				}
				if(ri!=(R/2)-1){ 
					if(Minp.second==C-1){
						cout<<"D";
					}else{
						cout<<"DD";
					}
				}
				else{
					if(Minp.second==C-1){
						
					}else{
						cout<<"D";
					}
				}
			}else if(ri<(Minp.first)/2){
				for(int j=1;j<C;++j){
					cout<<"R";
				}
				cout<<"D";
				for(int j=1;j<C;++j){
					cout<<"L";
				}
				cout<<"D";
			}else{
				for(int j=1;j<C;++j){
					cout<<"L";
				}
				cout<<"D";
				for(int j=1;j<C;++j){
					cout<<"R";
				}
				if(ri!=(R/2)-1) cout<<"D";
			}
		}
	}
}
