#include <iostream>
#include <string>
#include <vector>
using namespace std;
int findLCM(int a, int b) {
    int origa = a;
    int origb = b;
    int GCD = a;
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    GCD = a;
    return origa * origb / GCD;
}
int solution(vector<int> arr) {
    int answer = arr[0];
    for (int i = 1; i < arr.size(); i++) {
        answer = findLCM(answer, arr[i]);
    }
    return answer;
}