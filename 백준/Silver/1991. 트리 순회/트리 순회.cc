#include <vector> 
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct Node{
	char node;
	char left;
	char right;
	Node(char a, char b, char c){
		node=a;
		left=b;
		right=c;
	}
	bool operator <(Node &n){
		return this->node<n.node;
	}
};

vector<Node> tree;

void preorder(int i,vector<Node> &tree){
	cout<<tree[i].node;
	char left=tree[i].left;
	char right=tree[i].right;
	if(left!='.'){
		int l=left-65;
		preorder(l,tree);
	}
	if(right!='.'){
		int r=right-65;
		preorder(r,tree);
	}
}

void inorder(int i,vector<Node> &tree){
	char left=tree[i].left;
	char right=tree[i].right;
	if(left!='.'){
		int l=left-65;
		inorder(l,tree);
	}
	cout<<tree[i].node;
	if(right!='.'){
		int r=right-65;
		inorder(r,tree);
	}
}

void postorder(int i,vector<Node> &tree){
	char left=tree[i].left;
	char right=tree[i].right;
	if(left!='.'){
		int l=left-65;
		postorder(l,tree);
	}
	if(right!='.'){
		int r=right-65;
		postorder(r,tree);
	}
	cout<<tree[i].node;
}


int main(){
	int N;
	cin>>N;
	for(int i=0;i<N;++i){
		char a,b,c;
		cin>>a>>b>>c;
		tree.push_back(Node(a,b,c));
	}
	sort(tree.begin(),tree.end());
	preorder(0,tree);
	cout<<endl;
	inorder(0,tree);
	cout<<endl;
	postorder(0,tree);
	
}
