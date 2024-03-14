#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    for (int i = 1; i <= yellow; ++i) {
        if (yellow % i == 0) {
            int a = i;
            int b = yellow / i;
            if ((a + 2) * (b + 2) == brown + yellow) {
                vector<int> answer;
                answer.push_back(b + 2);
                answer.push_back(a + 2);
                return answer;
            }
        }
    }
}