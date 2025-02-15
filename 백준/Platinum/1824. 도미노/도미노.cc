#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

bool agroup(int a,int M, int N){
		if(M%2==1){
			if(a%2==1){
				return true;
			}else{
				return false;
			}
		}else{
			int b=(a-1)/M;
			int c=b%2;
			if(c==0){
				if(a%2==1){
					return true;
				}else{
					return false;
				}
			}else{
				if(a%2==1){
					return false;
				}else{
					return true;
				}
			}
		}
	}
vector<int> A;
vector<int> B;
vector<bool> dominocheck;
vector<vector<int>> dominolist;

bool dfs(int a){
	dominocheck[a]=true;
	for(int b: dominolist[a]){
		if(B[b]==-1||(!dominocheck[B[b]]&&dfs(B[b]))){
			A[a]=b;
			B[b]=a;
			return true;
		}
	}
	return false;
}


int main(void){
	int N,M;
	cin>>N;
	cin>>M;
	
	int MAX=M*N/2;
	dominolist.resize(MAX);
	A.assign(MAX,-1);
	B.assign(MAX,-1);
	dominocheck.assign(MAX,false);
	
	for(int i=1;i<=M*N;i++){
		if(agroup(i,M,N)){
			if(M%2==1){
				if(i>M){
					dominolist[(int)((i-1)/2)].push_back((i-M-2)/2);
				}
				if(i%M!=1){
					dominolist[(int)((i-1)/2)].push_back((i-3)/2);
				}
				if(i%M!=0){
					dominolist[(int)((i-1)/2)].push_back((i-1)/2);
				}
				if(i<=N*M-M){
					dominolist[(int)((i-1)/2)].push_back((i+M-2)/2);
				}	
			}else{
				int a,b;
				if(i>M){
					if(i%2==0){
						a=(i-2)/2;
						b=(i-M-1)/2;
					}else{
						a=(i-1)/2;
						b=(i-M-2)/2+1;
					}
					dominolist[a].push_back(b);
				}
				if((i%M)!=1){
					if(i%2==0){
						a=(i-2)/2;
						b=(i-2)/2;
					}else{
						a=(i-1)/2;
						b=(i-3)/2;
					}
					dominolist[a].push_back(b);
				}
				if((i%M)!=0){
					if(i%2==0){
						a=(i-2)/2;
						b=(i)/2;
					}else{
						a=(i-1)/2;
						b=(i-1)/2;
					}
					dominolist[a].push_back(b);
				}
				if(i<=N*M-M){
					if(i%2==0){
						a=(i-2)/2;
						b=(i+M-1)/2;
					}else{
						a=(i-1)/2;
						b=(i+M-2)/2+1;
					}
					dominolist[a].push_back(b);
				}
			}
		}
	}
	
	
	int wall;
	cin>>wall;
	for(int i=0;i<wall;i++){
		int a,b;
		cin>>a;
		cin>>b;
		if(!agroup(a,M,N)){
			int temp=a;
			a=b;
			b=temp;
		}
		if(M%2==1){
			for(auto &e: dominolist[(int)((a-1)/2)]){
				for(auto iter=dominolist[(int)((a-1)/2)].begin();iter!=dominolist[(int)((a-1)/2)].end();iter++){
					if(*iter==(b-2)/2){
					dominolist[(int)((a-1)/2)].erase(iter);
					break;
					}
				}
			}
		}else{
			int c,d;
			if(a%2==1){
				if(b%2==1){
					c=(a-1)/2;
					d=(b-1)/2;
					
				}else{
					c=(a-1)/2;
					d=(b-2)/2;
				}
			}else{
				if(b%2==1){
					c=(a-2)/2;
					d=(b-1)/2;
				}else{
					c=(a-2)/2;
					d=(b-2)/2;
				}
			}
			for(auto e:dominolist[c]){
				for(auto iter=dominolist[c].begin();iter!=dominolist[c].end();iter++){
					if(*iter==d){
						dominolist[c].erase(iter);
						break;
					}
				}
			}
			
			
		}
	}
	for(int i=0;i<MAX;i++){
		if(A[i]==-1){ 
			dominocheck.assign(MAX,false);
			dfs(i);
		}
	}
	
	
	for(int i=0;i<MAX;i++){
		if(M%2==1){
			cout<<(2*i+1)<<" "<<(2*A[i]+2)<<endl;
		}else{
			int a=i/(M/2);
			int b=a%2;
			int c=A[i]/(M/2);
			int d=c%2;
			if(b==1){
				if(d==1){
					cout<<2*i+2<<" "<<(2*A[i]+1)<<endl;
				}else{
					cout<<2*i+2<<" "<<(2*A[i]+2)<<endl;
				}
			}else{
				if(d==1){
					cout<<2*i+1<<" "<<(2*A[i]+1)<<endl;
				}else{
					cout<<2*i+1<<" "<<(2*A[i]+2)<<endl;
				}
				
			}
			
		}
	}
	
	return 0;
	
}