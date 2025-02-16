#include <vector>
#include <iostream>
#include <cstring>
using namespace std;

int tree[1000000][2];
void postorder(int a){
	if(tree[a][0]!=-1){
		postorder(tree[a][0]);
	}
	if(tree[a][1]!=-1){
		postorder(tree[a][1]);
	}
	cout<<a<<'\n';
}
int main(){
	memset(tree,-1,sizeof(tree));
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int now;
	int root;
	int past;
	cin>>now;
	root=now;
	past=root;
	while(cin>>now){
		if (std::cin.fail())
			break;
		past=root;
		while(true){
			if(now>past&&tree[past][1]==-1){
				tree[past][1]=now;
				break;
			}else if(now<past&&tree[past][0]==-1){
				tree[past][0]=now;
				break;
			}else if(now>past){
				past=tree[past][1];
			}else{
				past=tree[past][0];
			}
		}
		past=now;
		
	}
	postorder(root);
}