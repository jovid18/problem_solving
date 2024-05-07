#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    while (1) {
        bool isDone = true;
        int cnt = 0;
        for (int i = 0; i < progresses.size(); i++) {
            progresses[i] += speeds[i];
            if (progresses[i] < 100) {
                isDone = false;
                continue;
            }
            cnt++;
        }
        if (cnt != 0) {
            answer.push_back(cnt);
        }
        if (isDone)
            break;
    }
    for (int i = answer.size() - 1; i > 0; i--) {
        answer[i] -= answer[i - 1];
    }
    return answer;
}