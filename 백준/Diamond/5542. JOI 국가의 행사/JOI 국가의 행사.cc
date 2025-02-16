#include <bits/stdc++.h>
using namespace std;
#define int long long
using pii = pair<int, int>;
const int MAXN = 1e6 + 1;
struct edge
{
    int v, w;
    bool operator<(const edge &p) const
    {
        return w > p.w;
    }
};
struct DSU
{
    int par[MAXN], sz[MAXN];
    DSU() { init(MAXN); }
    void init(int n)
    {
        for (int i = 0; i < n; i++)
            par[i] = i, sz[i] = 1;
    }
    int find(int x)
    {
        return x == par[x] ? x : (par[x] = find(par[x]));
    }
    bool unite(int x, int y)
    {
        int u = find(x), v = find(y);
        if (u == v)
            return false;
        if (sz[u] > sz[v])
            swap(u, v);
        sz[v] += sz[u];
        sz[u] = 0;
        par[u] = par[v];
        return true;
    }
} dsu;
const int INF = 1LL << 62;
// N:도시 수, M:간선수, K:축제가 열리는 도시 수, Q:축제를 싫어하는 사람 수
int N, M, K, Q;
vector<edge> G[100001];
int dist[100001];
// F: 축제가 난 도시
vector<int> F;
// H: 시작점, 끝점
vector<pii> H;
// L: 도시의 거리값, 도시번호
vector<pii> L;
// QSE i번 쿼리의 lo, high 관리
pii QSE[MAXN];
bool checked[MAXN];
priority_queue<edge> pq;
void dijkstra(){
    while (!pq.empty())
    {
        auto t = pq.top();
        int v = t.v, w = t.w;
        pq.pop();
        if (w > dist[v])
            continue;
        for (auto p : G[v])
        {
            if (dist[p.v] > dist[v] + p.w)
            {
                dist[p.v] = dist[v] + p.w;
                pq.push({p.v, dist[p.v]});
            }
        }
    }
}
const bool comp(pii a, pii b)
{
    return a.first > b.first;
}
int32_t main()
{
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> N >> M >> K >> Q;
    for (int i = 0; i < M; ++i)
    {
        int a, b, w;
        cin >> a >> b >> w;
        G[a].push_back({b, w});
        G[b].push_back({a, w});
    }
    F.resize(K);
    for (auto &e : F)
        cin >> e;
    H.resize(Q);
    for (auto &e : H)
        cin >> e.first >> e.second;
    fill(dist, dist + 100001, INF);
    for (auto e : F){
        dist[e]=0;
        pq.push({e,0});
    }
    dijkstra();
    for (int i = 1; i <= N; ++i)
    {
        L.push_back({dist[i], i});
    }
    sort(L.begin(), L.end(), comp);
    for (int i = 0; i < Q; ++i)
    {
        QSE[i].first = 0;
        QSE[i].second = 1e7 + 1;
    }

    for (int t = 1; t <=25 ; ++t){
        vector<pii> qi;
        dsu.init(N + 1);
        memset(checked, 0, sizeof(checked));
        for (int i = 0; i < Q; ++i)
        {
            int mid = (QSE[i].first + QSE[i].second) / 2;
            if (QSE[i].second - QSE[i].first == 1) mid++;
            qi.push_back({mid, i});
        }
        sort(qi.begin(), qi.end(), comp);
        int idx = 0;
        for (auto e : qi)
        {
            vector<int> newupdate;
            int querymid = e.first;
            int queryidx = e.second;
            while (idx < L.size() && L[idx].first >= querymid){
                int nowcity = L[idx].second;
                checked[nowcity] = true;
                newupdate.push_back(nowcity);
                idx++;
            }
            for (auto e : newupdate) for (auto f : G[e]) if (checked[f.v]) dsu.unite(e, f.v);
            if (dsu.find(H[queryidx].first) == dsu.find(H[queryidx].second)) QSE[queryidx].first = querymid;
            else QSE[queryidx].second = querymid - 1; 
        }
    }
    for (int i = 0; i < Q; ++i)  cout << QSE[i].first << '\n';
}
