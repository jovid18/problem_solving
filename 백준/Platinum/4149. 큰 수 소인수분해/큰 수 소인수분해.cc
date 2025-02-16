#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll=long long;
using ull=unsigned long long;
using i128=__int128;
ll N;
vector<ll> ans;
ll gcd(ll a, ll b){
    if(b==0) return a;
    else return gcd(b, a%b);
}
ull mul(ull x,ull y,ull n){
	return (ull)((i128)x*y%n);
}
ull pow(ull x,ull y,ull n){
	ull ret=1;
	x%=n;
	while(y){
		if(y%2==1) ret=mul(ret,x,n);
		x=mul(x,x,n);
		y/=2;
	}
	return ret;
}
bool MR(ull n,ull a){
	if(n%a==0) return false;
	int cnt=-1;
	ull d=n-1;
	while(d%2==0){
		d/=2;
		cnt++;
	}
	ull p=pow(a,d,n);
	if(p==1||p==n-1) return true;
	while(cnt--){
		p=mul(p,p,n);
		if(p==n-1) return true;
	}
	return false;
}
bool checkMR(ll n){
	for(auto e:{2,3,5,7,11,13,17,19,21,23,29,31,37}){
		if(n==e) return true;
		if(n>40&&!MR(n,e)) return false;
	}
	if(n<=40) return false;
	return true;
}
ll PR(ll n){
	if(n==9) return 3;
	ll x=rand()%(n-2)+2;
	ll y=x;
	ll c=rand()%(n-1)+1;
	while(true){
		x=(mul(x,x,n)+c)%n;
		y=(mul(y,y,n)+c)%n;
		y=(mul(y,y,n)+c)%n;
		ll d=gcd(abs(x-y),n);
		if(d==1) continue;
		if(!checkMR(d)) return PR(d);
		else return d;
	}
}

void getfact(ll n){
	while(n%2==0){
		n/=2;
		ans.push_back(2);
	}
	if(n==1) return;
	while(!checkMR(n)){
		ll d=PR(n);
		while(n%d==0){
			ans.push_back(d);
			n/=d;
		}
		if(n==1) break;
	}
	if(n!=1) ans.push_back(n);
}
int main(){
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	cin>>N;
	getfact(N);
	sort(ans.begin(),ans.end());
	for(auto e:ans){
		cout<<e<<'\n';
	}
}
