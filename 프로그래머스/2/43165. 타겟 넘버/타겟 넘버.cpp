#include <string>
#include <vector>

using namespace std;
int answer = 0;
int tar = 0;
void sol(vector<int> &numbers, int now, int tar, int n) {
    if (n == numbers.size()) {
        if (now == tar)
            answer++;
        return;
    }
    sol(numbers, now + numbers[n], tar, n + 1);
    sol(numbers, now - numbers[n], tar, n + 1);
}

int solution(vector<int> numbers, int target) {
    tar = target;
    sol(numbers, 0, target, 0);
    return answer;
}