#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;
vector<vector<int>> G;
int cnt[20003];
bool visited[20003];
int solution(int n, vector<vector<int>> edge) {
    G.resize(n+1);
    for(auto e:edge){
        G[e[0]].push_back(e[1]);
        G[e[1]].push_back(e[0]);
    }
    queue<pair<int,int>> q;
    q.push({1,0});
    visited[1]=true;
    cnt[0]++;
    while(!q.empty()){
        auto [now,d]=q.front();
        cout<<now<<'\n';
        q.pop();
        for(auto e:G[now]){
            if(visited[e]) continue;
            visited[e]=true;
            cnt[d]++;
            q.push({e,d+1});
        }
    }
    for(int i=20001;i>=0;--i){
        if(cnt[i]>0) return cnt[i];
    }
}