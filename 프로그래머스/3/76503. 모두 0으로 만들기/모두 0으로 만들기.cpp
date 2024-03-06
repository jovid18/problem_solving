#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<vector<int>> T;
vector<long long> A;
long long answer = 0;
void dfs(int n, int p) {
    long long ret = 0;
    for (auto e : T[n]) {
        if (e == p)
            continue;
        dfs(e, n);
    }
    if (n == 0)
        return;
    answer += abs(A[n]);
    A[p] += A[n];
    A[n] = 0;
    return;
}
long long solution(vector<int> a, vector<vector<int>> edges) {
    for (auto e : a) {
        A.push_back(e);
    }
    long long sum = 0;
    for (auto e : A) {
        sum += e;
    }
    if (sum != 0)
        return -1;
    T.resize(A.size());
    for (auto e : edges) {
        T[e[0]].push_back(e[1]);
        T[e[1]].push_back(e[0]);
    }
    dfs(0, -1);
    return answer;
}
