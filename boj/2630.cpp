#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> paper(128);
int zero = 0;
int one = 0;
void quad(int x, int y, int N) {
    int check = 0;
    for (int i = x; i < x + N; ++i) {
        for (int j = y; j < y + N; ++j) {
            if (paper[i][j] == 1) {
                check++;
            }
        }
    }
    if (check == 0) {
        zero++;
    } else if (check == N * N) {
        one++;
    } else {
        quad(x, y, N / 2);
        quad(x + N / 2, y, N / 2);
        quad(x, y + N / 2, N / 2);
        quad(x + N / 2, y + N / 2, N / 2);
    }
}

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            int k;
            cin >> k;
            paper[i].push_back(k);
        }
    }
    quad(0, 0, N);
    cout << zero << endl << one;
}