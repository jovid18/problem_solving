#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
map<string, int> m;
vector<vector<int>> G;
int profit[10001];
void distrubute(int v, int money) {
    if (G[v].empty() || money == 0) {
        return;
    }
    int submit = money / 10;
    int my = money - submit;
    profit[v] += my;
    distrubute(G[v][0], submit);
}
vector<int> solution(vector<string> enroll, vector<string> referral,
                     vector<string> seller, vector<int> amount) {
    int n = 0;
    for (auto i : enroll) {
        m[i] = n++;
    }
    m["minho"] = n;
    G.resize(n + 1);
    for (int i = 0; i < n; ++i) {
        int e = m[enroll[i]], r = m[referral[i]];
        if (referral[i] == "-") {
            G[e].push_back(n);
        } else {
            G[e].push_back(r);
        }
    }
    for (int i = 0; i < seller.size(); ++i) {
        int e = m[seller[i]];
        distrubute(e, amount[i] * 100);
    }
    vector<int> answer;
    for (int i = 0; i < n; ++i) {
        answer.push_back(profit[m[enroll[i]]]);
    }
    return answer;
}