#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    int zerocnt = 0;
    int cnt = 0;
    while (s != "1") {
        cnt++;
        int zero = 0;
        for (char e : s) {
            if (e == '0') {
                zero++;
                zerocnt++;
            }
        }
        int num = s.size() - zero;
        s = "";
        while (num > 0) {
            string temp = "";
            while (num > 0) {
                temp = to_string(num % 2) + temp;
                num /= 2;
            }
            s = temp;
        }
    }
    answer.push_back(cnt);
    answer.push_back(zerocnt);
    return answer;
}