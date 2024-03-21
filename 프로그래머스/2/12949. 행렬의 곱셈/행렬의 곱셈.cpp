#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1,
                             vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    int n = arr1.size();
    int m = arr2[0].size();
    int l = arr1[0].size();
    answer.resize(arr1.size());
    for (auto &a : answer)
        a.resize(m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int sum = 0;
            for (int k = 0; k < l; k++) {
                sum += arr1[i][k] * arr2[k][j];
            }
            answer[i][j] = sum;
        }
    }
    return answer;
}