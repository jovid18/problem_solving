#include <iostream>
#include <set>
#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<string> operations) {
    multiset<int> ms;
    for (auto e : operations) {
        char c = e[0];
        int n = stoi(e.substr(2));
        if (e[0] == 'I') {
            ms.insert(n);
        } else {
            if (ms.empty())
                continue;
            if (n == 1) {
                ms.erase(prev(ms.end()));
            } else {
                ms.erase(ms.begin());
            }
        }
    }
    vector<int> answer;
    if (ms.empty()) {
        answer = { 0, 0 };
    } else {
        answer = { *ms.rbegin(), *ms.begin() };
    }
    return answer;
}
int main() {
    vector<string> operations = {"I 16", "I -5643", "D -1", "D 1",
                                 "D 1",  "I 123",   "D -1"};
    solution(operations);
    return 0;
}