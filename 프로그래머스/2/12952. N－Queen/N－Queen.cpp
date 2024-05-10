#include <cmath>
#include <iostream>
#include <vector>

using namespace std;
int N;
int col[15];
int Count;
bool checking(int i);
void nqueens(int i) {
    if (i == N) {
        Count++;
        return;
    }
    if (i == 0) {
        for (int j = 1; j <= N; ++j) {
            col[i] = j;
            nqueens(i + 1);
        }
    } else {
        for (int j = 1; j <= N; ++j) {
            col[i] = j;
            if (checking(i)) {
                nqueens(i + 1);
            }
        }
    }
}
bool checking(int i) {
    int k = 0;
    bool flag = true;
    while (k < i && flag) {
        if (col[k] == col[i] || (abs(col[k] - col[i]) == i - k)) {
            flag = false;
        }
        k++;
    }
    return flag;
}

int solution(int n) {
    int answer = 0;
    N = n;
    nqueens(0);
    answer = Count;
    return answer;
}