#include <iostream>
#include <string>
using namespace std;
int N, x, ans;
string s;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>N;
    while(N--){
        cin>>s;
        x=0;
        ans=0;
        for(int i=s.size()-1;i>=0;--i){
            if(s[i]-'0') x+=(1<<(s.size()-i-1));
        }
        bool chk=false;
        for(int bit=s.size()-1;bit>=0;--bit){
            if(x&(1<<bit)){
                chk^=1;
                if(chk) ans+=(1<<(bit+1))-1;
                else ans-=(1<<(bit+1))-1;
            } 
        }
        cout<<ans<<'\n';
    }
}