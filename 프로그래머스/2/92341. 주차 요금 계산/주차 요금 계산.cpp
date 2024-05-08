#include <iostream>
#include <set>
#include <string>
#include <vector>
using namespace std;
int Time[10000], totalTime[10000], cost[10000];
bool carlist[10000];

vector<int> solution(vector<int> fees, vector<string> records) {
    for (int i = 0; i < 10000; ++i) {
        Time[i] = -1;
    }
    vector<int> answer;
    for (auto e : records) {
        int hour = stoi(e.substr(0, 2));
        int minute = stoi(e.substr(3, 2));
        int total = 60 * hour + minute;
        int car = stoi(e.substr(6, 4));
        carlist[car] = true;
        bool isIn = e[11] == 'I';
        if (isIn) {
            Time[car] = total;
        } else {
            totalTime[car] += total - Time[car];
            Time[car] = -1;
        }
    }
    for (int i = 0; i <= 9999; ++i) {
        if (carlist[i] && Time[i] >= 0) {
            totalTime[i] += 60 * 23 + 59 - Time[i];
        }
    }
    for (int i = 0; i <= 9999; ++i) {
        if (!carlist[i])
            continue;
        if (totalTime[i] <= fees[0]) {
            cost[i] = fees[1];
        } else {
            cost[i] = fees[1] + ((totalTime[i] - fees[0]) % fees[2] == 0
                                     ? (totalTime[i] - fees[0]) / fees[2]
                                     : (totalTime[i] - fees[0]) / fees[2] + 1) *
                                    fees[3];
        }
    }
    for (int i = 0; i <= 9999; ++i) {
        if (carlist[i]) {
            answer.push_back(cost[i]);
        }
    }
    return answer;
}