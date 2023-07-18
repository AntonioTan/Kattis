//
// Created by Tabbit on 7/17/23.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, s, m;
    int moveCnt = 0;
    int rst = 0;
    string rstMsg[4] = {"magic", "left", "right", "cycle"};
    cin >> n >> s >> m;
    int board[n];
    s -= 1;
    for (int i = 0; i < n; i++) {
        cin >> board[i];
    }
    while (board[s] != m) {
        int diff = board[s];
        board[s] = -201;
        s += diff;
        moveCnt += 1;
        if (s >= n) {
            rst = 2;
            break;
        } else if (s < 0) {
            rst = 1;
            break;
        } else if (board[s] == -201) {
            rst = 3;
            break;
        }
    }
    cout << rstMsg[rst] << '\n' << moveCnt << endl;
}
