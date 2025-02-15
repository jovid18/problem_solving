#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int N,M;
struct piece{
	double weight;
	int idx,cutting=1;
	piece(double weight_,int idx_,int cutting_=1):weight(weight_),idx(idx_),cutting(cutting_){}
	bool operator <(const piece &a)const{
		return this->weight<a.weight;
	}
};
priority_queue<piece> pq;
vector<double> orig;
double ans=1e9,MIN=1e9;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N;
	orig.resize(N);
	for(int i=0;i<N;++i){
		cin>>orig[i];
		pq.push({orig[i],i});
	}
	double MIN=*min_element(orig.begin(),orig.end());
	ans=min(ans,pq.top().weight-MIN);
	cin>>M;
	for(int i=0;i<M;++i){
		auto MAX=pq.top();
		pq.pop();
		MAX.weight=orig[MAX.idx]/(++MAX.cutting);
		MIN=min(MIN,MAX.weight);
		pq.push(MAX);
		ans=min(ans,pq.top().weight-MIN);
	}
	cout.precision(15);
	cout<<ans;
}