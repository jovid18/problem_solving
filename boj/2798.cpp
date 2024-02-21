#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> card;
    for (int i = 0; i < N; ++i) {
        int a;
        cin >> a;
        card.push_back(a);
    }
    sort(card.begin(), card.end(), greater<>());
    int sum = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            for (int k = j + 1; k < N; ++k) {
                int a = card[i] + card[j] + card[k];
                if (a <= M && a > sum) {
                    sum = a;
                    break;
                }
            }
        }
    }
    cout << sum;
}