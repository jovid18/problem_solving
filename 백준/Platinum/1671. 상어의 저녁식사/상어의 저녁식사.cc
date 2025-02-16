#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> A;
vector<int> B;
vector<bool> visited;
vector<vector<int>> dinner;
bool dfs(int a){
	visited[a]=true;
	for(auto b:dinner[a]){
		if(B[b] == -1 || (!visited[B[b]] && dfs(B[b]))){
            A[a] = b;
            B[b] = a;
            return true;
        }
	}
	return false;
}

struct shark{
	int a;
	int b;
	int c;
};
bool compare(const shark&a, const shark &b){
	return(a.a>=b.a&&a.b>=b.b&&a.c>=b.c);
}
int main(){
	int N;
	cin>>N;
	vector<shark> sharks(N);
	for(int i=0;i<N;++i){
		cin>>sharks[i].a>>sharks[i].b>>sharks[i].c;
	}
	dinner.resize(2*N);
	for(int i=0;i<N;++i){
		for(int j=0;j<N;++j){
			if(i!=j){
			if(sharks[i].a==sharks[j].a&&sharks[i].b==sharks[j].b&&sharks[i].c==sharks[j].c){
				if(i<j){
				dinner[2*i].push_back(j);
				dinner[2*i+1].push_back(j);
					}
			}else if(sharks[i].a>=sharks[j].a&&sharks[i].b>=sharks[j].b&&sharks[i].c>=sharks[j].c){
				dinner[2*i].push_back(j);
				dinner[2*i+1].push_back(j);
			}
			}
		}
	}
	int match=0;
	A.assign(2*N,-1);
	B.assign(N,-1);
	visited.assign(2*N,false);
	
	for(int i=0;i<2*N; i++){
        if(A[i] == -1){
            visited.assign(2*N,false);
            if(dfs(i)) {
            	match++;
            }
        }
    }

	cout<<N-match;
}
