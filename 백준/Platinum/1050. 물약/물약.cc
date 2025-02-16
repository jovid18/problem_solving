#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
int N,M;
map<string,double>  m;
vector<string> recipe;
int32_t main(){
    cin.tie(0)->sync_with_stdio(0);
    cin>>N>>M;
    for(int i=0;i<N;++i){
        string s;
        double val;
        cin>>s>>val;
        m[s]=val;
    }
    recipe.resize(M);
    for(auto &e: recipe) cin>>e;
    int rec=100;
    while(rec--){
        for(auto s:recipe){
            int equalidx=s.find("=");
            vector<pair<double,string>> Ingredient;
            string Result=s.substr(0,equalidx);
            int splitidx=equalidx;
            s=s.substr(splitidx+1);
            while(s.find("+")!=string::npos){
                splitidx=s.find("+");
                Ingredient.push_back({s[0]-'0',s.substr(1,splitidx-1)});
                s=s.substr(splitidx+1);
            }
            Ingredient.push_back({s[0]-'0',s.substr(1)});
            double cost=0;
            bool imp=0;
            for(auto e: Ingredient){
                if(m.find(e.second)!=m.end()){
                    cost+=e.first*m[e.second];
                }else{
                    imp=1;
                    break;
                }
            }
            if(imp) continue;
            else{
                if(m.find(Result)==m.end()){
                    m[Result]=cost;
                }else{
                    m[Result]=min(m[Result],cost);
                }
            }
        }
    }
    if(m.find("LOVE")==m.end()) cout<<-1;
    else{
        double love=m["LOVE"];
        cout<<fixed;
        cout.precision(0);
        if(love>1000000000.99) cout<<1000000001;
        else cout<<love;
    }
}