#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

long long solution(int n, int m, int x, int y, vector<vector<int>> queries) {
    long long N = n;
    long long M = m;
    long long xmin = x;
    long long xmax = x;
    long long ymin = y;
    long long ymax = y;
    reverse(queries.begin(), queries.end());
    for (auto e : queries) {
        int command = e[0];
        long long dx = e[1];
        if (command == 0) {
            if (ymin + dx >= M && ymin != 0) {
                return 0;
            }
            long long newymin = M;
            long long newymax = 0;
            if (ymin == 0) {
                newymin = min(newymin, 0LL);
                newymax = max(newymax, min(dx, M - 1));
            }
            newymin = min(newymin, min(ymin + dx, M - 1));
            newymax = max(newymax, min(ymax + dx, M - 1));
            ymin = newymin;
            ymax = newymax;
        } else if (command == 1) {
            if (ymax - dx < 0 && ymax != M - 1) {
                return 0;
            }
            long long newymin = M;
            long long newymax = 0;
            if (ymax == M - 1) {
                newymin = min(newymin, max(M - 1 - dx, 0LL));
                newymax = max(newymax, M - 1);
            }
            newymin = min(newymin, max(ymin - dx, 0LL));
            newymax = max(newymax, max(ymax - dx, 0LL));
            ymin = newymin;
            ymax = newymax;
        } else if (command == 2) {
            if (xmin + dx >= N && xmin != 0) {
                return 0;
            }
            long long newxmin = N;
            long long newxmax = 0;
            if (xmin == 0) {
                newxmin = min(newxmin, 0LL);
                newxmax = max(newxmax, min(dx, N - 1));
            }
            newxmin = min(newxmin, min(xmin + dx, N - 1));
            newxmax = max(newxmax, min(xmax + dx, N - 1));
            xmin = newxmin;
            xmax = newxmax;
        } else if (command == 3) {
            if (xmax - dx < 0 && xmax != N - 1) {
                return 0;
            }
            long long newxmin = N;
            long long newxmax = 0;
            if (xmax == N - 1) {
                newxmin = min(newxmin, max(N - 1 - dx, 0LL));
                newxmax = max(newxmax, N - 1);
            }
            newxmin = min(newxmin, max(xmin - dx, 0LL));
            newxmax = max(newxmax, max(xmax - dx, 0LL));
            xmin = newxmin;
            xmax = newxmax;
        }
        // cout << command << " " << dx << endl;
        // cout << xmin << " " << xmax << " " << ymin << " " << ymax << endl;
        if (xmin > xmax || ymin > ymax)
            return 0;
        if (xmin < 0 || xmax >= n || ymin < 0 || ymax >= m)
            return 0;
        if (xmin >= n || xmax < 0 || ymin >= m || ymax < 0)
            return 0;
    }

    return (xmax - xmin + 1) * (ymax - ymin + 1);
}
