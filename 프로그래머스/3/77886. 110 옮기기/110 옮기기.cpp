#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

vector<string> solution(vector<string> s) {
    for (auto &str : s) {
        int cnt = 0;
        stack<char> S;
        for (auto e : str) {
            if (e == '0' && S.size() >= 2) {
                char second = S.top();
                S.pop();
                char first = S.top();
                S.pop();
                if (first == '1' && second == '1') {
                    cnt++;
                    continue;
                } else {
                    S.push(first);
                    S.push(second);
                    S.push(e);
                    continue;
                }
            }
            S.push(e);
        }
        str = "";
        while (!S.empty()) {
            str += S.top();
            S.pop();
        }
        reverse(str.begin(), str.end());
        while (cnt--) {
            bool isinserted = false;
            for (int i = 1; i < str.size(); ++i) {
                if (str[i - 1] == '1' && str[i] == '1') {
                    string add = "";
                    for (int i = 0; i < cnt + 1; ++i) {
                        add += "110";
                    }
                    str.insert(i - 1, add);
                    cnt = 0;
                    isinserted = true;
                    break;
                }
            }

            if (!isinserted) {
                for (int i = str.size() - 1; i >= 0; --i) {
                    if (str[i] == '0') {
                        str.insert(i + 1, "110");
                        isinserted = true;
                        break;
                    }
                }
            }
            if (!isinserted) {
                str = "110" + str;
            }
        }
    }
    return s;
}