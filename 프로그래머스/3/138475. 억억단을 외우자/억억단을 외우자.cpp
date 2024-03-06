#include <algorithm>
#include <string>
#include <vector>
using namespace std;
int cnt[5000001];
int DP[5000001];
vector<int> solution(int e, vector<int> starts) {

    for (int i = 1; i <= 5000000; ++i) {
        for (int j = i; j <= 5000000; j += i) {
            cnt[j]++;
        }
    }
    auto startscopy = starts;
    int now = startscopy[0];
    int max = -1;
    for (int i = e; i >= 1; --i) {
        if (cnt[i] >= max) {
            max = cnt[i];
            now = i;
        }
        DP[i] = now;
    }
    vector<int> answer;
    for (auto e : starts) {
        answer.push_back(DP[e]);
    }
    return answer;
}