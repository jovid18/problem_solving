//본코드는 https://jason9319.tistory.com/263의 게시물을 공부하고 작성한 코드임을 명시합니다.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX=1<<19;
int now,M;
struct Node {
	int v;
	Node* l;
	Node* r;
	Node(int v, Node* l, Node* r) :v(v), l(l), r(r) {}
	Node* update(int lo, int hi, int pos) {
		if (pos < lo || hi < pos) return this;
		if (lo == hi) return new Node(v + 1, NULL, NULL);
		int mid = (lo + hi) / 2;
		return new Node(v + 1, l->update(lo, mid, pos), r->update(mid + 1, hi, pos));
	}
}*seg[MAX];
int sum(Node* root, int s, int f, int lo, int hi){
	if(f<lo||hi<s) return 0;
	if(lo<=s&&f<=hi) return root->v;
	int m=(s+f)/2;
	return sum(root->l,s,m,lo,hi)+sum(root->r,m+1,f,lo,hi);
}
int kth(Node * Lnode, Node* Rnode,int s, int f, int k){
	if(s==f) return s;
	int m=(s+f)/2;
	if(Rnode->l->v-Lnode->l->v>=k) return kth(Lnode->l,Rnode->l,s,m,k);
	else return kth(Lnode->r,Rnode->r,m+1,f,k-(Rnode->l->v-Lnode->l->v));
}
int Xor(Node *Lnode, Node * Rnode,int s,int f, int k){
	if(s==f) return s;
	int m=(s+f)/2;
	bool chk=((f-s+1)/2)&k;
	if((chk&&Lnode->l->v==Rnode->l->v)||(!chk&&Lnode->r->v!=Rnode->r->v)){
		return Xor(Lnode->r,Rnode->r,m+1,f,k);
	}
	else return Xor(Lnode->l,Rnode->l,s,m,k);
}
int main(){
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	cin>>M;
	seg[0] = new Node(0, NULL, NULL);
	seg[0]->l = seg[0]->r = seg[0];
	while(M--){
		int n,x,L,R;
		cin>>n;
		if(n==1){
			cin>>x;
			now++;
			seg[now]=seg[now-1]->update(0,MAX-1,x);
		}else if(n==2){
			cin>>L>>R>>x;
			cout<<Xor(seg[L-1],seg[R],0,MAX-1,x)<<'\n';
		}else if(n==3){
			cin>>x;
			now-=x;
		}else if(n==4){
			cin>>L>>R>>x;
			cout<<(sum(seg[R],0,MAX-1,1,x)-sum(seg[L-1],0,MAX-1,1,x))<<'\n';
		}else{
			cin>>L>>R>>x;
			cout<<kth(seg[L-1],seg[R],0,MAX-1,x)<<'\n';
		}
	}
}