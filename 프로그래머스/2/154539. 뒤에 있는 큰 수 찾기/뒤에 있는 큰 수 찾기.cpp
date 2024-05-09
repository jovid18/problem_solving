#include <algorithm>
#include <stack>
#include <string>
#include <vector>
using namespace std;
stack<int> S;
vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    int n = numbers.size();
    for (int i = n - 1; i >= 0; --i) {
        int now = numbers[i];
        if (S.empty()) {
            answer.push_back(-1);
            S.push(now);
        } else if (now < S.top()) {
            answer.push_back(S.top());
            S.push(now);
        } else if (now == S.top()) {
            S.pop();
            if (S.empty()) {
                answer.push_back(-1);
            } else {
                answer.push_back(S.top());
            }
            S.push(now);
        } else {
            while (!S.empty() && S.top() <= now) {
                S.pop();
            }
            if (S.empty()) {
                answer.push_back(-1);
            } else {
                answer.push_back(S.top());
            }
            S.push(now);
        }
    }
    reverse(answer.begin(), answer.end());
    return answer;
}