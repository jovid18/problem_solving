#include <cstdio>
#include <cstring>
#include <vector>
using namespace  std;
vector<vector<bool>> count(5001,vector<bool>(5001,false));

int main(){
	int T;
	scanf("%d",&T);
	for(int i=0;i<T;++i){
		int N;
		int M;
		scanf("%d %d",&N,&M);
		for(int j=1;j<=M;++j){
			int b;
			int a;
			scanf("%d %d",&a,&b);
			count[a][b]=true;
			count[b][a]=true;
		}
		long long twotri=0;
		for(int j=1;j<=N;j++){
			int o=0;
			for(int k=1;k<=N;k++){
				if(count[j][k]){
					o++;
				}
			}
			twotri=twotri+(N-1-o)*o;
		}
		twotri/=2;
		long long total=(long long)N*(N-1)*(N-2)/6;
		printf("%lld\n",total-twotri);
		fill(count.begin(), count.end(), vector<bool>(5001, false));
	}
}