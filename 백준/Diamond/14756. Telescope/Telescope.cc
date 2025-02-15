#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
typedef vector<ll> vi;
typedef complex<double> base;
void fft(vector<base> &a, bool invert){
    int n=sz(a);
    for(int i=1,j=0;i<n;++i){
        ll bit=n>>1;
        for(;j>=bit;bit>>=1) j-=bit;
        j+=bit;
        if(i<j) swap(a[i],a[j]);
    }
    for(int len=2;len<=n;len<<=1){
        double ang=2*M_PI/len*(invert?-1:1);
        base wlen(cos(ang),sin(ang));
        for(int i=0;i<n;i+=len){
            base w(1);
            for(int j=0;j<len/2;++j){
                base u=a[i+j],v=a[i+j+len/2]*w;
                a[i+j]=u+v;
                a[i+j+len/2]=u-v;
                w*=wlen;
            }
        }
    }
    if(invert){
        for(int i=0;i<n;++i) a[i]/=n;
    }
}
void multiply(const vi &a, const vi &b, vi&res){
    vector<base> fa(all(a)), fb(all(b));
    int n=1;
    while(n<max(sz(a),sz(b))) n<<=1;
    fa.resize(n);fb.resize(n);
    fft(fa,false);
    fft(fb,false);
    for(int i=0;i<n;++i) fa[i]*=fb[i];
    fft(fa,true);
    res.resize(n);
    for(int i=0;i<n;++i) res[i]=(ll)(fa[i].real()+(fa[i].real()>0?0.5:-0.5));
}
int n,l,m,cnt;
ll W;
vector<ll> P[10000],T[100],F[100];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    cin>>n>>l>>m>>W;
    for(int i=0;i<m;++i){
        P[i].resize(n);
        for(int j=0;j<n;++j) cin>>P[i][j];  
    }
    for(int i=0;i<m;++i){
        T[i].resize(l);
        for(int j=l-1;j>=0;--j) cin>>T[i][j];
    }
    for(int i=0;i<m;++i) multiply(P[i],T[i],F[i]);
    for(int i=l-1;i<=n-1;++i){
        ll sum=0;
        for(int j=0;j<m;++j) sum+=F[j][i];
        if(sum>W) cnt++;
    }
    cout<<cnt;
}

