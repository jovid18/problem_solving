#include <bits/stdc++.h>
using namespace std;
const int N=1e6+1;
struct segtree {
    using elem = int;
    int n;
    elem T[2*N];
    
    inline elem agg(elem a, elem b) {
        return max(a, b);
    }
    void build(vector<elem> &v) {
        n = v.size();
        for (int i = 0; i<n; i++)
        T[n+i] = v[i];
        for (int i = n-1; i>0; i--)
        T[i] = agg(T[i<<1], T[(i<<1)|1]);
    }
    void modify(int pos, elem val) {
        for (T[pos += n] = val; pos > 1; pos >>= 1)
        T[pos >> 1] = agg(T[pos], T[pos^1]);
    }
    // query is on [ l , r) ! !
    elem query(int l, int r){
        elem res = 0;
        for (l += n, r += n; l < r; l >>=1, r>>=1) {
            if (l & 1) res = agg(T[l++], res);
            if (r & 1) res = agg(res, T[--r]);
        }
        return res;
    }
};
int h = sizeof(int) * 8 - __builtin_clz(n);
int d[N];
void apply(int p, int value) {
    t[p] += value;
    if (p < n) d[p] += value;
}
void build(int p) {
    while (p > 1) p >>= 1, t[p] = max(t[p<<1], t[p<<1|1]) + d[p];
}
void push(int p) {
    for (int s = h; s > 0; --s) {
        int i = p >> s;
        if (d[i] != 0) {
            apply(i<<1, d[i]);
            apply(i<<1|1, d[i]);
            d[i] = 0;
        }
    }
}
void inc(int l, int r, int value) {
    l += n, r += n;
    int l0 = l, r0 = r;
    for (; l < r; l >>= 1, r >>= 1) {
        if (l&1) apply(l++, value);
        if (r&1) apply(--r, value);
    }
    build(l0);
    build(r0 - 1);
}
int query(int l, int r) {
    l += n, r += n;
    push(l);
    push(r - 1);
    int res = -2e9;
    for (; l < r; l >>= 1, r >>= 1) {
        if (l&1) res = max(res, t[l++]);
        if (r&1) res = max(t[--r], res);
    }
    return res;
}