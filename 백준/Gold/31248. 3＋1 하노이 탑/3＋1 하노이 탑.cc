#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>

int ans[21] = {0, 1, 3, 5, 9, 15, 27, 49, 93, 179, 351, 693, 1377, 2743, 5475, 10937, 21861, 43707, 87399, 174781, 349545};
int xyz = 0;
void print(char x, char y) { cout << x << " " << y << '\n'; }

void sol2(int N, char cur, char des) {
    char rem = 'A' + 'B' + 'C' - cur - des;
    if (N == 1) {
        print(cur, des);
        return;
    }
    if (N == 2) {
        print(cur, rem);
        print(cur, des);
        print(rem, des);
        return;
    }
    sol2(N - 1, cur, rem);
    print(cur, des);
    sol2(N - 1, rem, des);
}

void sol(int N, bool isA) {
    if (N == 1) {
        print(isA ? 'A' : 'B', 'D');
        return;
    }
    if (N == 2) {
        print(isA ? 'A' : 'B', 'C');
        print(isA ? 'A' : 'B', 'D');
        print('C', 'D');
        return;
    }
    sol2(N - 2, isA ? 'A' : 'B', isA ? 'B' : 'A');
    print(isA ? 'A' : 'B', 'C');
    print(isA ? 'A' : 'B', 'D');
    print('C', 'D');
    sol(N - 2, !isA);
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int N;
    cin >> N;
    cout << ans[N] << '\n';
    sol(N, 1);
}