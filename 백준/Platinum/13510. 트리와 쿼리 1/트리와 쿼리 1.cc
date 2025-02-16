//https://justicehui.github.io/hard-algorithm/2020/01/24/hld/의 글을 공부하고 작성한 코드임을 명시합니다.
#include <iostream>
#include <vector>
using namespace std;
struct Q{
	int u,v,w;
};
struct Seg{
	int tree[1<<18];
	int sz=1<<17;
	void update(int x, int v){
		x|=sz;
		tree[x]=v;
		while(x>>=1){
			tree[x]=max(tree[x<<1],tree[x<<1|1]);
		}
	}
	int query(int l, int r){
		l|=sz,r|=sz;
		int ret=0;
		while(l<=r){
			if(l&1) ret=max(ret,tree[l++]);
			if(~r&1) ret=max(ret,tree[r--]);
			l>>=1,r>>=1;
		}
		return ret;
	}
}seg;
const int max_v=100001;
int N,M,pv;
int sz[max_v],dep[max_v],par[max_v],top[max_v],in[max_v],out[max_v];
vector<int> g[max_v];
vector<int> inp[max_v];
vector<Q> q;
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
int query(int a, int b){
	int ret=0;
	while(top[a]^top[b]){
		if(dep[top[a]]<dep[top[b]]) swap(a,b);
		int st=top[a];
		ret=max(ret,seg.query(in[st],in[a]));
		a=par[st];
	}
	if(dep[a]>dep[b]) swap(a,b);
	ret=max(ret,seg.query(in[a]+1,in[b]));
	return ret;
}
int main(){
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	cin>>N;
	for(int i=0;i<N-1;++i){
		int u,v,w;
		cin>>u>>v>>w;
		inp[u].push_back(v);
		inp[v].push_back(u);
		q.push_back({u,v,w});
	}
	dfs();
	dfs1();
	dfs2();
	for(auto &e: q){
		if(dep[e.u]<dep[e.v]){
			swap(e.u,e.v);
		}
		update(e.u,e.w);
	}
	cin>>M;
	for(int i=0;i<M;++i){
		int op,a,b;
		cin>>op>>a>>b;
		if(op==1) update(q[a-1].u,b);
		else cout<<query(a,b)<<'\n';
	}
}