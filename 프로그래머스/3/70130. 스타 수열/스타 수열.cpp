#include <iostream>
#include <string>
#include <vector>
using namespace std;
int cnt[500001];
int solution(vector<int> a) {
    for (auto e : a)
        cnt[e]++;
    int s = 0;
    int f = a.size() / 2;
    int answer = -1;
    while (s + 1 < f) {
        int m = (s + f) / 2;
        bool isPossible = false;
        for (int i = 0; i < a.size(); i++) {
            if (isPossible)
                break;
            if (cnt[i] < m) {
                continue;
            }
            int icnt = 0;
            int noticnt = 0;
            for (int j = 0; j < a.size(); j++) {
                if (icnt == noticnt) {
                    if (a[j] == i) {
                        icnt++;
                    } else {
                        noticnt++;
                    }
                } else if (icnt > noticnt) {
                    if (a[j] != i) {
                        noticnt++;
                    }
                } else if (icnt < noticnt) {
                    if (a[j] == i) {
                        icnt++;
                    }
                }
            }
            if (icnt >= m && noticnt >= m) {
                isPossible = true;
                break;
            }
        }
        if (isPossible) {
            s = m;
        } else {
            f = m;
        }
    }
    return 2 * s;
}

int main() {
    vector<int> a = {0, 3, 0, 3, 3, 2, 3, 2, 2, 0, 0, 0, 0, 0, 0, 3, 0, 0, 3};
    cout << solution(a) << endl;
    return 0;
}