//
// Created by Tabbit on 7/17/23.
//

#include<bits/stdc++.h>
using namespace std;
int **nums;
int **color;
int row_num, col_num;
int group = 0;
void dfs(int r, int c, int orig) {
    if (r < 0 || r >= row_num) {
        return;
    }
    if (c < 0 || c >= col_num) {
        return;
    }
    if(nums[r][c] != orig) {
        return ;
    }
    if (color[r][c] != -1) {
        return;
    }
    color[r][c] = group;
    dfs(r - 1, c, orig);
    dfs(r + 1, c, orig);
    dfs(r, c - 1, orig);
    dfs(r, c + 1, orig);
    return ;
}

int main() {
    cin >> row_num >> col_num;
    nums = new int *[row_num];
    color = new int *[row_num];
    for (int i = 0; i < row_num; i++) {
        nums[i] = new int[col_num];
        color[i] = new int[col_num];
        string num;
        cin >> num;
        for (int j = 0; j < col_num; j++) {
            nums[i][j] = num.at(j) - '0';
            color[i][j] = -1;
        }
    }
    for (int i = 0; i < row_num; i++) {
        for (int j = 0; j < col_num; j++) {
            if (color[i][j] == -1) {
                group += 1;
                dfs(i, j, nums[i][j]);
            }
        }
    }

    int query_num;
    cin >> query_num;
    for (int i = 0; i < query_num; i++) {
        bool binary = false;
        bool decimal = false;
        int startX, startY, endX, endY;
        cin >> startX >> startY >> endX >> endY;
        startX--;
        startY--;
        endX--;
        endY--;
        if (color[startX][startY] == color[endX][endY]) {
            if (nums[startX][startY] == 0) {
                binary = true;
            } else {
                decimal = true;
            }
        }
        if (binary) {
            cout << "binary" << endl;
        } else if (decimal) {
            cout << "decimal" << endl;
        } else {
            cout << "neither" << endl;
        }

    }
}
