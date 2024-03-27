#include <map>
#include <string>
#include <vector>
using namespace std;
map<string, int> m;
int solution(vector<vector<string>> clothes) {
    int answer = 1;
    for (int i = 0; i < clothes.size(); i++) {
        if (m.find(clothes[i][1]) == m.end())
            m[clothes[i][1]] = 1;
        else
            m[clothes[i][1]]++;
    }
    for (auto e : m) {
        answer *= e.second + 1;
    }
    return answer - 1;
}