#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int chk[1000000];
int Min[1000000];
int solution(vector<int> a) {
    int answer = 0;
    int minidx = min_element(a.begin(), a.end()) - a.begin();
    for (int i = 0; i < minidx; i++) {
        if (i == 0) {
            Min[i] = a[i];
            continue;
        }
        Min[i] = min(Min[i - 1], a[i]);
    }
    for (int i = a.size() - 1; i >= minidx; i--) {
        if (i == a.size() - 1) {
            Min[i] = a[i];
            continue;
        }
        Min[i] = min(Min[i + 1], a[i]);
    }
    chk[minidx] = 1;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == Min[i]) {
            answer++;
        }
    }
    return answer;
}