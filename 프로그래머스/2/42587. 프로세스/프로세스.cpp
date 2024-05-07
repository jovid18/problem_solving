#include <algorithm>
#include <queue>
#include <string>
#include <vector>
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<pair<int, int>> q;
    for (int i = 0; i < priorities.size(); i++) {
        q.push({priorities[i], i});
    }
    vector<int> sorted = priorities;
    sort(sorted.begin(), sorted.end());
    while (!q.empty()) {
        if (q.front().second == location && q.front().first == sorted.back()) {
            answer++;
            break;
        } else if (q.front().first == sorted.back()) {
            answer++;
            q.pop();
            sorted.pop_back();
        } else {
            q.push(q.front());
            q.pop();
        }
    }
    return answer;
}