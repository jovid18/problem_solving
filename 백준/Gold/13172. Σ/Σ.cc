#include <iostream>
#include <vector>
using namespace std;
int N;
vector<vector<int>> numlist;


int GCD(int a, int b) {
	vector<int> s, t, r, q;
    s = { 1,0 };
    t = { 0,1 };
    r = { a,b };
 
    while (1)
    {
        int r2 = r[r.size() - 2];
        int r1 = r[r.size() - 1];
        q.push_back(r2 / r1);
        r.push_back(r2 % r1);
        if (r[r.size() - 1] == 0)
            break;
        int s2 = s[s.size() - 2];
        int s1 = s[s.size() - 1];
        int t2 = t[t.size() - 2];
        int t1 = t[t.size() - 1];
        int q1 = q[q.size() - 1];
        s.push_back(s2 - s1 * q1);
        t.push_back(t2 - t1 * q1);
    }
    return t[t.size()-1];
}



int main(){
	cin>>N;
	numlist.resize(N);
	for(int i=0;i<N;++i){
		numlist[i].assign(3,0);
		cin>>numlist[i][0];
		cin>>numlist[i][1];
		long long n=GCD(1000000007,numlist[i][0]);
		if(n<0){
			n+=1000000007;
		}
		numlist[i][2]=n*numlist[i][1]%1000000007;
	}
	long long answer=0;
	for(int i=0;i<N;++i){
		answer+=numlist[i][2];
	}
	cout<<answer%1000000007;
	
}
