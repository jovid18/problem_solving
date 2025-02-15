#include <vector>
#include <iostream>
#include <string>
#include <map>
using namespace std;
vector<vector<string>> S;
struct Node{
	map<string, Node*> m;
	void insert(vector<string> s, int n){
		if(n==s.size()) return;
		if(this->m.find(s[n])==this->m.end()){
			Node * node= new Node;
			this->m[s[n]]= node;
		}
		this->m[s[n]]->insert(s,n+1);
	}
	void print(int count){
		if(this->m.empty()){
			return;
		}
		for(auto iter=this->m.begin();iter!=this->m.end();iter++){
			for(int i=0;i<count;++i){
				cout<<"--";
			}
			cout<<iter->first<<endl;
			iter->second->print(count+1);
		}
	}
};
int N;
int main(){
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	cin>>N;
	S.resize(N);
	Node* root=new Node;
	int a;
	for(int i=0;i<N;++i){
		cin>>a;
		string s;
		for(int j=0;j<a;++j){
			cin>>s;
			S[i].push_back(s);
		}
	}
	for(int i=0;i<N;++i){
		root->insert(S[i],0);
	}
	root->print(0);
}