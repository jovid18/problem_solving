#include <complex>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
using cpx = complex<double>;
using vec=vector<cpx>;
const double PI = acos(-1);
int N,M;
void FFT(vec &v, cpx w){
	int n=v.size();
	if(n==1) return;
	vec even(n/2), odd(n/2);
	for(int i=0;i<n;++i){
		if(i&1) odd[i/2]=v[i];
		else even[i/2]=v[i];
	}
	FFT(even, w*w);
	FFT(odd, w*w);
	cpx z(1,0);
	for(int i=0;i<n/2;++i){
		v[i]=even[i]+z*odd[i];
		v[i+n/2]=even[i]-z*odd[i];
		z *=w;
	}
}
vec mul(vec v){
	int n=1;
	while(n<=v.size()) n*=2;
	n*=2;
	v.resize(n);
	vec w(n);
	cpx unit(cos(2*PI/n),sin(2*PI/n));
	FFT(v,unit);
	for(int i=0;i<n;++i) w[i]=v[i]*v[i];
	FFT(w, cpx(1,0)/unit);
	for(int i=0;i<n;++i){
		w[i]/=cpx(n,0);
		w[i]=cpx(round(w[i].real()),round(w[i].imag()));
	}
	return w;
}
int main(){
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	cin>>N;
	vec v(200001);
	v[0]=cpx(1,0);
	for(int i=0;i<N;++i){
		int x;
		cin>>x;
		v[x]=cpx(1,0);
	}
	vec c=mul(v);
	long long ans=0;
	cin>>M;
	for(int i=0;i<M;++i){
		int x;
		cin>>x;
		if(abs(c[x].real())!=0) ans++;
	}
	cout<<ans;
}
