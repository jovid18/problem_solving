#include <iostream>
#include <string>
#include <vector>
using namespace std;
int answer = -1;
vector<vector<int>> DG;
void find(vector<int> v, int p, int n) {
    answer = max(answer, n);
    for (int i = 0; i < v.size(); ++i) {
        if (v[i] == 0 && p >= DG[i][0]) {
            v[i] = 1;
            p -= DG[i][1];
            find(v, p, n + 1);
            v[i] = 0;
            p += DG[i][1];
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    DG = dungeons;
    int n = DG.size();
    vector<int> v(n, 0);
    find(v, k, 0);
    return answer;
}