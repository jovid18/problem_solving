#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int N;
vector<long long> num;

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N;
	num.resize(N);
	for(int i=0;i<N;++i){
		cin>>num[i];
	}
	sort(num.begin(),num.end());
	long long s=0;
	long long f=0;
	long long answer=2000000000;
	for(auto iter1=num.begin();iter1!=num.end();++iter1){
		auto iter2=lower_bound(iter1+1, num.end(), -1*(*iter1));
		if(iter2==num.end()){
			long long sum=(*iter1)+(*(iter2-1));
			if(answer>abs(sum)&&iter1!=(iter2-1)){
				answer=abs(sum);
				s=*iter1;
				f=*(iter2-1);
			}
		}else{
			long long sum1=(*iter1)+(*iter2);
			if(answer>abs(sum1)&&iter1!=iter2){
				answer=abs(sum1);
				s=*iter1;
				f=*iter2;
			}
			long long sum2=(*iter1)+(*(iter2-1));
			
			if(answer>abs(sum2)&&iter1!=(iter2-1)){
				answer=abs(sum2);
				s=*iter1;
				f=*(iter2-1);
			}
		}
	}
	cout<<s+f;
}
