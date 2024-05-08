#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<string> dict;
void ins(string s) {
    if (s.length() == 6) {
        return;
    }
    if (s != "") {
        dict.push_back(s);
    }
    ins(s + 'A');
    ins(s + 'E');
    ins(s + 'I');
    ins(s + 'O');
    ins(s + 'U');
}
int solution(string word) {
    int answer = 0;
    ins("");
    sort(dict.begin(), dict.end());
    auto iter = find(dict.begin(), dict.end(), word);
    return iter - dict.begin() + 1;
}