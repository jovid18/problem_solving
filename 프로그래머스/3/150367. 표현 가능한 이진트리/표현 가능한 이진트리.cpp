#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool check(string &s, int l, int r) {
    if (l >= r)
        return true;
    int m = (l + r) / 2;
    if (s[m] == '0' && (s[l] == '1' || s[r] == '1'))
        return false;
    return check(s, l, m - 1) && check(s, m + 1, r);
}
vector<int> solution(vector<long long> numbers) {
    vector<int> answer;
    for (auto e : numbers) {
        string s = "";
        while (e) {
            s = to_string(e & 1) + s;
            e = e >> 1;
        }
        cout << s << endl;

        int n = 1;
        while (s.size() > (1LL << n) - 1) {
            n++;
        }
        s = string((1LL << n) - 1 - s.size(), '0') + s;
        if (s[(s.size() / 2)] == '0') {
            answer.push_back(0);
            continue;
        }
        answer.push_back(check(s, 0, s.size() - 1));
    }
    return answer;
}