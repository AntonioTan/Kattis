//
// Created by Tabbit on 7/17/23.
//

#include <bits/stdc++.h>

using namespace std;

int board[4][4];
int diffs[4][2] = {{0,  -1},
                   {1,  0},
                   {0,  1},
                   {-1, 0}};

int main() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> board[i][j];
        }
    }
    int move;
    cin >> move;
    if (move == 0) {
        for (int i = 0; i < 4; i++) {
            for (int j = 1; j < 4; j++) {
                int x = i;
                int y = j;
                if (board[x][y] == 0) {
                    continue;
                }
                while (y > 0) {
                    int leftX = x;
                    int leftY = y - 1;
                    if (board[leftX][leftY] == 0) {
                        board[leftX][leftY] = board[x][y];
                        board[x][y] = 0;
                        y -= 1;
                    } else if (board[leftX][leftY] == board[x][y]) {
                        board[leftX][leftY] *= -2;
                        board[x][y] = 0;
                        break;
                    } else {
                        break;
                    }
                }
            }
        }
    } else if (move == 1) {
        for (int j = 0; j < 4; j++) {
            for (int i = 1; i < 4; i++) {
                int x = i;
                int y = j;
                if (board[x][y] == 0) {
                    continue;
                }
                while (x > 0) {
                    int upX = x - 1;
                    int upY = y;
                    if (board[upX][upY] == board[x][y]) {
                        board[upX][upY] *= -2;
                        board[x][y] = 0;
                        break;
                    } else if (board[upX][upY] == 0) {
                        board[upX][upY] = board[x][y];
                        board[x][y] = 0;
                        x -= 1;
                    } else {
                        break;
                    }
                }
            }
        }
    } else if (move == 2) {
        for (int i = 0; i < 4; i++) {
            for (int j = 2; j >= 0; j--) {
                int x = i;
                int y = j;
                if (board[x][y] == 0) {
                    continue;
                }
                while (y < 3) {
                    int rightX = x;
                    int rightY = y + 1;
                    if (board[rightX][rightY] == board[x][y]) {
                        board[rightX][rightY] *= -2;
                        board[x][y] = 0;
                        break;
                    } else if (board[rightX][rightY] == 0) {
                        board[rightX][rightY] = board[x][y];
                        board[x][y] = 0;
                        y += 1;
                    } else {
                        break;
                    }
                }
            }
        }
    } else {
        for (int j = 0; j < 4; j++) {
            for (int i = 2; i >= 0; i--) {
                int x = i;
                int y = j;
                if (board[x][y] == 0) {
                    continue;
                }
                while (x < 3) {
                    int downX = x + 1;
                    int downY = y;
                    if (board[downX][downY] == board[x][y]) {
                        board[downX][downY] *= -2;
                        board[x][y] = 0;
                        break;
                    } else if(board[downX][downY]==0){
                        board[downX][downY] = board[x][y];
                        board[x][y] = 0;
                        x += 1;
                    } else {
                        break;
                    }
                }
            }
        }
    }
    for(int i=0; i<4; i++) {
        for(int j=0; j<4; j++) {
            board[i][j] = abs(board[i][j]);
            cout << board[i][j] << ' ';
        }
        cout << endl;
    }

}

