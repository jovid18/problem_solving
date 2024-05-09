#include <iostream>
#include <string>
#include <vector>
using namespace std;
int M[1000][1000];
vector<int> solution(int n) {
    vector<int> answer;
    int x = 0, y = 0, cnt = 1;
    int opt = 0;
    int initN = n;
    while (n--) {
        if (opt % 3 == 0) {
            for (int i = 0; i <= n; ++i) {
                M[x++][y] = cnt++;
            }
            x--;
            y++;
            opt++;
        } else if (opt % 3 == 1) {
            for (int i = 0; i <= n; ++i) {
                M[x][y++] = cnt++;
            }
            x--;
            y--;
            y--;
            opt++;
        } else {
            for (int i = 0; i <= n; ++i) {
                M[x--][y--] = cnt++;
            }
            x++;
            x++;
            y++;
            opt++;
        }
    }
    n = initN;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            answer.push_back(M[i][j]);
        }
    }
    return answer;
}