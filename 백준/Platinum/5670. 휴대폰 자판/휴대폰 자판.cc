#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;
vector<string> V;
int ans=0;
int toint(const char c){
	return c-'a';
}
struct Node{
	vector<Node *> children;
	int stnum=-1;
	int matchcount=0;
	Node(): children(26,0) {}
	~Node(){
		for(int i=0;i<26;++i){
			if(children[i]){
				delete children[i];
			}
		}
	}
	void insert(int num, int nth){
		if(V[num].size()==nth) return;
		int pointernum=toint(V[num][nth]);
		if(children[pointernum]==NULL){
			Node *child=new Node;
			child->stnum=num;
			child->matchcount=V	[num].size()-nth;
			children[pointernum]=child;
		}else{
			int i=0;
			bool match=true;
			int childstnum=children[pointernum]->stnum;
			for(;i<children[pointernum]->matchcount;++i){
				if(V[num].size()==nth+i||V[childstnum][nth+i]!=V[num][nth+i]){
					match=false;
					break;
				}
			}
			if(!match){
				Node * newchild=new Node();
				newchild->stnum=num;
				newchild->matchcount=i;
				int childpointernum=toint(V[childstnum][nth+i]);
				children[pointernum]->matchcount-=i;
				newchild->children[childpointernum]=children[pointernum];
				children[pointernum]=newchild;
			}
		}
		children[pointernum]->insert(num,nth+children[pointernum]->matchcount);
	}
	void find(int num, int nth){
		if(V[num].size()==nth) return;
		++ans;
		int pointernum=toint(V[num][nth]);
		children[pointernum]->find(num,nth+children[pointernum]->matchcount);
	}
};
int main(){
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int N;
	while(cin>>N){
		ans=0;
		V.resize(N);
		Node * root= new Node;
		for(int i=0;i<N;++i){
			cin>>V[i];
			root->insert(i,0);
		}
		for(int i=0;i<N;++i){
			root->find(i,0);
		}
		cout<<fixed<<setprecision(2)<<(double)ans/N<<'\n';
	}
}