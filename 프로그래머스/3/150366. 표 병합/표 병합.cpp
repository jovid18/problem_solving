#include <iostream>
#include <queue>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
int a[51][51];
string m[51][51];
int cnt;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
bool isIn(int x, int y) { return x > 0 && x < 51 && y > 0 && y < 51; }
vector<string> solution(vector<string> commands) {
    vector<string> answer;

    for (int i = 0; i < 51; i++) {
        for (int j = 0; j < 51; j++) {
            a[i][j] = cnt++;
            m[i][j] = "";
        }
    }
    for (auto e : commands) {
        istringstream ss(e);
        string s;
        vector<string> command;
        while (ss >> s) {
            command.push_back(s);
        }
        if (command[0] == "UPDATE") {
            if (command.size() == 4) {
                int r = stoi(command[1]);
                int c = stoi(command[2]);
                string value = command[3];
                for (int i = 1; i <= 50; i++) {
                    for (int j = 1; j <= 50; j++) {
                        if (a[i][j] == a[r][c]) {
                            m[i][j] = value;
                        }
                    }
                }
            } else {
                string value1 = command[1];
                string value2 = command[2];
                for (int i = 1; i <= 50; i++) {
                    for (int j = 1; j <= 50; j++) {
                        if (m[i][j] == value1) {
                            m[i][j] = value2;
                        }
                    }
                }
            }
        } else if (command[0] == "MERGE") {
            int r1 = stoi(command[1]);
            int c1 = stoi(command[2]);
            int r2 = stoi(command[3]);
            int c2 = stoi(command[4]);
            if (r1 == r2 && c1 == c2)
                continue;
            int area1 = a[r1][c1];
            int area2 = a[r2][c2];
            cnt++;
            string value = m[r1][c1] != "" ? m[r1][c1] : m[r2][c2];
            for (int i = 1; i <= 50; i++) {
                for (int j = 1; j <= 50; j++) {
                    if (a[i][j] == area1 || a[i][j] == area2) {
                        a[i][j] = cnt;
                        m[i][j] = value;
                    }
                }
            }
        } else if (command[0] == "UNMERGE") {
            int r = stoi(command[1]);
            int c = stoi(command[2]);
            int area = a[r][c];
            string value = m[r][c];
            for (int i = 1; i <= 50; i++) {
                for (int j = 1; j <= 50; j++) {
                    if (a[i][j] == area) {
                        a[i][j] = ++cnt;
                        m[i][j] = "";
                    }
                }
            }
            m[r][c] = value;
        } else if (command[0] == "PRINT") {
            int r1 = stoi(command[1]);
            int c1 = stoi(command[2]);
            if (m[r1][c1] != "") {
                answer.push_back(m[r1][c1]);
                cout << m[r1][c1] << endl;
            } else {
                answer.push_back("EMPTY");
            }
        }
    }

    return answer;
}