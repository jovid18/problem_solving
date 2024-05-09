#include <string>
#include <vector>

using namespace std;
int F[1000001], B[1000001];
bool Fchk[10001], Bchk[10001];
int solution(vector<int> topping) {
    int answer = 0;
    int Fcnt = 0;
    for (int i = 0; i < topping.size(); ++i) {
        if (!Fchk[topping[i]]) {
            Fchk[topping[i]] = true;
            Fcnt++;
        }
        F[i] = Fcnt;
    }
    int Bcnt = 0;
    for (int i = topping.size() - 1; topping.size() >= 0; --i) {
        if (!Bchk[topping[i]]) {
            Bchk[topping[i]] = true;
            Bcnt++;
        }
        B[i] = Bcnt;
    }
    for (int i = 0; i < topping.size(); ++i) {
        if (F[i] == B[i]) {
            answer++;
        }
    }
    return answer;
}