#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    for (auto &e : s) {
        e = tolower(e);
    }
    bool is_first = true;
    for (auto &e : s) {
        if (is_first && e != ' ') {
            e = toupper(e);
            is_first = false;
            continue;
        }
        if (e == ' ') {
            is_first = true;
        }
    }
    return s;
}