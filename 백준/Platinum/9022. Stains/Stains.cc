#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <cassert>
#include <cstring>
#include <climits>
using namespace std;
using pii=pair<int,int>;
#define ff first
#define ss second
using ll=long long;
bool comp(pii x, pii y){
    if(x.ss==y.ss){
        return x.ff<y.ff;
    }
    return x.ss>y.ss;
}
bool noneed[10001];
int T,n;
vector<pii> V,R;
vector<pair<double,double>> S;
vector<double> DP;

struct Line {
	mutable ll m, k, p;
	bool operator<(const Line& o) const { return m < o.m; }
	bool operator<(ll x) const { return p < x; }
};

struct LineContainer : multiset<Line, less<>> {
	static const ll inf = LLONG_MAX;
	ll div(ll a, ll b) { //floored division
		return a / b - ((a ^ b) < 0 && a % b != 0);
	}
	bool isect(iterator x, iterator y) {
		if (y == end()) return x->p = inf, 0;
		if (x->m == y->m) x->p = x->k > y->k ? inf : -inf;
		else x->p = div(y->k - x->k, x->m - y->m);
		return x->p >= y->p;
	}
	void add(ll m, ll k) { //add y = mx + k
		auto z = insert({ m, k, 0 }), y = z++, x = y;
		while (isect(y, z)) z = erase(z);
		if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
		while ((y = x) != begin() && (--x)->p >= y->p) isect(x, erase(y));
	}
	ll query(ll x) {
		assert(!empty());
		auto l = *lower_bound(x);
		return l.m * x + l.k;
	}
};
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cout<<fixed;
    cout.precision(1);
    cin>>T;
    while(T--){
        V.clear();
        R.clear();
        DP.clear();
        S.clear();
        memset(noneed,0,sizeof(noneed));
        cin>>n;
        V.resize(n);
        for(int i=0;i<n;++i){
            cin>>V[i].first>>V[i].second;
            V[i].second=abs(V[i].second);
        }
        sort(V.begin(),V.end(),comp);
        for(int i=0;i<n;++i){
            if(noneed[i]) continue;
            for(int j=i+1;j<n;++j){
                int dx=abs(V[i].ff-V[j].ff);
                int dy=abs(V[i].ss-V[j].ss);
                if(dx<=dy) noneed[j]=true;
            }
        }
        for(int i=0;i<n;++i){
            if(noneed[i]) continue;
            R.push_back(V[i]);
        }
        n=R.size();
        sort(R.begin(),R.end());
        S.resize(n+1);
        DP.resize(n+1);
        for(int i=1;i<=n;++i){
            S[i].ff=R[i-1].ff-R[i-1].ss;
            S[i].ss=R[i-1].ff+R[i-1].ss;
        }
        LineContainer LC;
        for(int i=1;i<=n;++i){
            LC.add(2*S[i].ff,-DP[i-1]-S[i].ff*S[i].ff);
            DP[i]=-LC.query(S[i].ss)+S[i].ss*S[i].ss;  
        }
        cout<<DP[n]/2<<'\n';
    }
}