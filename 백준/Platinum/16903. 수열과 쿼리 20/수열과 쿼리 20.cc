#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int N;
string to_bstring(int n){
	string s(30,'0');
	for(int i=0;i<30;++i){
		if(n&(1<<i)) s[29-i]='1';
	}
	return s;
}
struct trieNode{
	vector<trieNode *>children;
	int count=0;
	trieNode(): children(2,0) {}
	~trieNode(){
		for(int i=0;i<2;++i){
			if(children[i]){
				delete children[i];
			}
		}
	}
	void insert(string s,int num){
		if(s.size()==num){
			count++;
			return ;
		}
		int now=s[num]-'0';
		count++;
		if(children[now]==NULL){
			trieNode *child=new trieNode;
			children[now]=child;
			children[now]->insert(s,num+1);
		}else{
			children[now]->insert(s,num+1);
		}
	}
	void erase(string s,int num){
		count--;
		if(s.size()==num) return;
		int now=s[num]-'0';
		if(children[now]==NULL) return;
		if(children[now]->count>1){
			children[now]->erase(s,num+1);
		}else{
			delete children[now];
			children[now]=NULL;
		}
	}
	int query(string s, int num){
		if(num==30) return 0;
		int second=s[num]-'0';
		int first=second^1;
		if(children[first]!=NULL){
			return (first<<(29-num))+children[first]->query(s,num+1);
		}else if(children[second]!=NULL){
			return (second<<(29-num))+children[second]->query(s,num+1);
		}
		return 0;
	}
};
int main(){
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	trieNode root;
	cin>>N;
	root.insert(to_bstring(0),0);
	while(N--){
		int a,b;
		cin>>a>>b;
		if(a==1){
			root.insert(to_bstring(b),0);
		}else if(a==2){
			root.erase(to_bstring(b),0);
		}else{
			int num=root.query(to_bstring(b),0);
			cout<<(b^num)<<'\n';
		}
	}
}