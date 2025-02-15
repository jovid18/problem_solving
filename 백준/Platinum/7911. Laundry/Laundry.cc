#include <bits/stdc++.h>
using namespace std;
#define int long long
multiset<int> S;
int n, k;
vector<int> d;
int32_t main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k;
    d.resize(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> d[i];
    }
    for (int i = 0; i < k; ++i)
    {
        int x;
        cin >> x;
        S.insert(x);
    }
    sort(d.begin(), d.end(), greater<>());
    bool imp = false;
    for (int i = 0; i < n; ++i)
    {
        if (imp) break;
        auto iter = S.lower_bound(5 * d[i]);
        if (iter == S.end())
        {
            auto iter1 = S.lower_bound(3 * d[i]);
            if (iter1 == S.end())
            {
                imp = true;
                continue;
            }
            else S.erase(iter1);
            auto iter2 = S.lower_bound(2 * d[i]);
            if (iter2 == S.end())
            {
                imp = true;
                continue;
            }
            else S.erase(iter2);
        }
        else S.erase(iter);
    }
    if (imp) cout << "NIE";
    else cout << k - S.size();
}