#include <complex>
#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;
using cpx = complex<double>;
using vec=vector<cpx>;
const double PI = acos(-1);
vector<int> V,U;
int N,M,S;
void FFT(vec &v, bool inv){
	int n=v.size();
	for(int i=1,j=0;i<n;++i){
		int bit=n/2;
		while(j>=bit){
			j-=bit;
			bit/=2;
		}
		j+=bit;
		if(i<j) swap(v[i],v[j]);
	}
	for(int k=1;k<n;k*=2){
		double angle = (inv ? PI/k:-PI/k);
		cpx w(cos(angle),sin(angle));
		for(int i=0;i<n;i+=2*k){
		cpx z(1,0);
			for(int j=0;j<k;++j){
				cpx even=v[i+j];
				cpx odd=v[i+j+k];
				v[i+j]=even+z*odd;
				v[i+j+k]=even-z*odd;
				z*=w;
			}
		}
	}
	if(inv) for (int i=0;i<n;++i) v[i]/=n;
}
vector<int> mul(vec &v, vec &u){
	int n=2;
	while(n<v.size()+u.size()) n*=2;
	v.resize(n);
	FFT(v,false);
	u.resize(n);
	FFT(u,false);
	for(int i=0;i<n;++i) v[i]*=u[i];
	FFT(v,true);
	vector<int> w(S);
	for(int i=0;i<S;++i) w[i]=round(v[i].real());
	return w;
}
string a,b;
int main(){
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	cin>>a>>b;
	a+=a;
	S=a.size()+b.size()-1;
	reverse(b.begin(),b.end());
	vec v,u;
	for(int i=0;i<a.size();++i){
		v.push_back(cpx(a[i]-'0',0));
	}
	for(int i=0;i<b.size();++i){
		u.push_back(cpx(b[i]-'0',0));
	}
	vector<int> ans=mul(v,u);
	cout<<*max_element(ans.begin(),ans.end());
}
