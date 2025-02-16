#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int T,N;
vector<int> num;
vector<bool> checked;
vector<bool> haveteam;
vector<bool> noteam;
int main(){
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	cin>>T;
	for(int t=0;t<T;++t){
		cin>>N;
		num.assign(N,0);
		checked.assign(N,0);
		haveteam.assign(N,0);
		noteam.assign(N,0);
		for(int i=0;i<N;++i){
			cin>>num[i];
			num[i]--;
		}
		int count=0;
		for(int i=0;i<N;++i){
			if(checked[i]){
				continue;
			}
			vector<int> checkspace;
			checked[i]=true;
			checkspace.push_back(i);
			int a=num[i];
			while(!checked[a]){
				checkspace.push_back(a);
				checked[a]=true;
				a=num[a];
			}
			bool turn=false;
			for(int j=0;j<checkspace.size();++j){
				if(checkspace[j]==a){
					turn=true;
				}
				if(turn){
					haveteam[checkspace[j]]=true;
				}else{
					noteam[checkspace[j]]=true;
					count++;
				}
			}	
		}
		cout<<count<<'\n';
	}
}
