#include <iostream>
using namespace std;
int group[9] = {0};
bool checked[9] = {false};
int n, m;
void dfs(int count) {
    if (count == m) {
        for (int i = 0; i < m; ++i) {
            cout << group[i] << " ";
        }
        cout << endl;
        return;
    }
    for (int i = 1; i <= n; ++i) {
        if (count == 0 && !checked[i]) {
            group[count] = i;
            checked[i] = true;
            dfs(count + 1);
            checked[i] = false;
        } else if (group[count - 1] < i && !checked[i]) {
            group[count] = i;
            checked[i] = true;
            dfs(count + 1);
            checked[i] = false;
        }
    }
}
int main() {
    cin >> n >> m;
    dfs(0);
}