#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> days;
    days.resize(progresses.size());
    for (int i = 0; i < progresses.size(); ++i) {
        if ((100 - progresses[i]) % speeds[i] == 0) {
            days[i] = (100 - progresses[i]) / speeds[i];
        } else {
            days[i] = (100 - progresses[i]) / speeds[i] + 1;
        }
    }
    int mindays = days[0];
    for (int i = 0; i < days.size(); ++i) {
        mindays = max(mindays, days[i]);
        if (days[i] >= mindays) {
            continue;
        }
        days[i] = mindays;
    }

    int now = days[0];
    int cnt = 0;
    for (auto e : days) {
        if (e == now) {
            cnt++;
            continue;
        } else {
            answer.push_back(cnt);
            cnt = 1;
            now = e;
        }
    }
    answer.push_back(cnt);

    return answer;
}