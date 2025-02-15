//https://justicehui.github.io/hard-algorithm/2020/01/24/hld/의 글을 공부하고 작성한 코드임을 명시합니다.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Seg{
	int tree[1<<19];
	int sz=1<<18;
	void update(int x, int v){
		x|=sz;
		tree[x]=v;
		while(x>>=1){
			tree[x]=min(tree[x<<1],tree[x<<1|1]);
		}
	}
	int minquery(int l, int r){
		l|=sz,r|=sz;
		int ret=1e9;
		while(l<=r){
			if(l&1) ret=min(ret,tree[l++]);
			if(~r&1) ret=min(ret,tree[r--]);
			l>>=1,r>>=1;
		}
		return ret;
	}
}seg;
const int max_v=200001;
int N,M,pv;
int sz[max_v],dep[max_v],par[max_v],top[max_v],in[max_v],out[max_v];
vector<int> g[max_v];
vector<int> inp[max_v];
void dfs(int v=1, int p=0){
	for(auto e:inp[v]){
		if(e==p) continue;
		g[v].push_back(e);
		dfs(e,v);
	}
}
void dfs1(int v=1){
	sz[v]=1;
	for(auto &e:g[v]){
		dep[e]=dep[v]+1;
		par[e]=v;
		dfs1(e);
		sz[v]+=sz[e];
		if(sz[e]>sz[g[v][0]]) swap(e,g[v][0]);
	}
}
void dfs2(int v=1){
	in[v]=++pv;
	for(auto e:g[v]){
		top[e]= e==g[v][0] ? top[v] : e;
		dfs2(e);
	}
	out[v]=pv;
}
void update(int v, int w){
	seg.update(in[v],w);
}
bool justquery(int a, int b){
	int ret=1e9;
	while(top[a]^top[b]){
		if(dep[top[a]]<dep[top[b]]) swap(a,b);
		int st=top[a];
		ret=min(ret,seg.minquery(in[st],in[a]));
		a=par[st];
	}
	if(dep[a]>dep[b]) swap(a,b);
	ret=min(ret,seg.minquery(in[a]+1,in[b]));
	return ret==1;
}
void query(int b, int c){
	if(justquery(b,c)){
		cout<<"YES"<<'\n';
		update(b,0);
	}else{
		cout<<"NO"<<'\n';
		update(c,0);
	}
}
int main(){
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	cin>>N>>M;
	for(int i=2;i<=N;++i){
		int x;
		cin>>x;
		inp[i].push_back(x);
		inp[x].push_back(i);
	}
	dfs();
	dfs1();
	dfs2();
	for(int i=2;i<=N;++i){
		update(i,1);
	}
	for(int i=0;i<M;++i){
		int a,b,op;
		cin>>a>>b>>op;
		if(op==0) cout<<(justquery(a,b)?"YES":"NO")<<'\n';
		else query(a,b);
	}
}