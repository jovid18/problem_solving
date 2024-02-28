#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<string> answer;
bool finished = false;
int bn, bm;
int fc, fr;
bool isIn(int x, int y) { return (x >= 1 && x <= bn && y >= 1 && y <= bm); }
char c[] = {'d', 'l', 'r', 'u'};
int dx[] = {1, 0, 0, -1};
int dy[] = {0, -1, 1, 0};
string solution(int n, int m, int x, int y, int r, int c, int k) {
    bn = n;
    bm = m;
    int move = abs(x - r) + abs(y - c);
    if ((k % 2) != (move % 2))
        return "impossible";
    if (move > k)
        return "impossible";
    int leftmove = 0, rightmove = 0, upmove = 0, downmove = 0;
    if (r > x)
        downmove = r - x;
    else
        upmove = x - r;
    if (c > y)
        rightmove = c - y;
    else
        leftmove = y - c;
    int remaink = k - leftmove - rightmove - upmove - downmove;
    int cnt = k;
    int initdown = downmove;
    int initup = upmove;
    int initleft = leftmove;
    int initright = rightmove;
    int initx = x;
    int inity = y;
    for (int i = 0; i <= remaink; i += 2) {
        cnt = k;
        downmove += i / 2;
        upmove += i / 2;
        leftmove += (remaink - i) / 2;
        rightmove += (remaink - i) / 2;
        string res = "";
        while (cnt--) {
            if (downmove && isIn(x + 1, y)) {
                res += "d";
                downmove--;
                x++;
            } else if (leftmove && isIn(x, y - 1)) {
                res += "l";
                leftmove--;
                y--;
            } else if (rightmove && isIn(x, y + 1)) {
                res += "r";
                rightmove--;
                y++;
            } else if (upmove && isIn(x - 1, y)) {
                res += "u";
                upmove--;
                x--;
            }
        }
        downmove = initdown;
        upmove = initup;
        leftmove = initleft;
        rightmove = initright;
        x = initx;
        y = inity;
        if (res.size() == k)
            answer.push_back(res);
    }
    sort(answer.begin(), answer.end());

    return answer[0];
}