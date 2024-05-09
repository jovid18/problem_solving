#include <bitset>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    for (auto e : numbers) {
        if (e == 0) {
            answer.push_back(1);
            continue;
        }
        int num = __builtin_popcount(e);
        if (e == ((1LL << num) - 1)) {
            e ^= 1LL << num;
            e ^= 1LL << (num - 1);
            answer.push_back(e);
            continue;
        }
        for (int i = 0; i <= 62; ++i) {
            if (e & (1LL << i)) {
            } else {
                bool chk = false;
                e ^= 1LL << i;
                for (int j = i - 1; j >= 0; --j) {
                    if (e & (1LL << j)) {
                        answer.push_back(e ^ (1LL << j));
                        chk = true;
                        break;
                    }
                }
                if (chk)
                    break;
                answer.push_back(e);
                break;
            }
        }
    }
    return answer;
}