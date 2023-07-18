//
// Created by Tabbit on 7/16/23.
//

#include <bits/stdc++.h>

using namespace std;

int getComplexNum(int nums[2], int col_num) {
    return nums[0] * col_num + nums[1];
}

int main() {
    int diffs[4][2] = {{0,  1},
                       {0,  -1},
                       {1,  0},
                       {-1, 0}};
    int row_num, col_num;
    cin >> row_num >> col_num;
    int nums[row_num][col_num];
    int mem[row_num][col_num];
    for (int i = 0; i < row_num; i++) {
        string num;
        cin >> num;
        for (int j = 0; j < col_num; j++) {
            nums[i][j] = num.at(j) - '0';
            mem[i][j] = -1;
        }
    }
    int query_num;
    cin >> query_num;
    int group = 0;
    for (int i = 0; i < query_num; i++) {
        int start[2];
        int end[2];
        bool binary = false;
        bool decimal = false;
        cin >> start[0] >> start[1] >> end[0] >> end[1];
        start[0] -= 1;
        start[1] -= 1;
        end[0] -= 1;
        end[1] -= 1;
        if (nums[start[0]][start[1]] == nums[end[0]][end[1]]) {
            if (mem[start[0]][start[1]] != -1 || mem[end[0]][end[1]] != -1) {
                if (mem[start[0]][start[1]] == mem[end[0]][end[1]]) {
                    if (nums[start[0]][start[1]] == 0) {
                        binary = true;
                    } else {
                        decimal = true;
                    }
                }
            } else {
                queue<int> q;
                q.push(getComplexNum(start, col_num));
                int *point;
                while (!q.empty()) {
                    int x = q.front() / col_num;
                    int y = q.front() % col_num;
                    mem[x][y] = group;
                    if (x == end[0] && y == end[1]) {
                        if (nums[start[0]][start[1]] == 0) {
                            binary = true;
                        } else {
                            decimal = true;
                        }
                    }
                    for (int *diff: diffs) {
                        point = new int[2];
                        point[0] = x + diff[0];
                        point[1] = y + diff[1];
                        int p_complex_num = getComplexNum(point, col_num);
                        if (point[0] >= 0 && point[0] < row_num &&
                            point[1] >= 0 && point[1] < col_num && mem[point[0]][point[1]] == -1 &&
                            nums[point[0]][point[1]] == nums[start[0]][start[1]]) {
                            mem[point[0]][point[1]] = group;
                            q.push(p_complex_num);
                        }
                    }
                    q.pop();
                }
            }
        }
        if (binary) {
            cout << "binary" << '\n';
        } else if (decimal) {
            cout << "decimal" << '\n';
        } else {
            cout << "neither" << '\n';
        }
        group += 1;
    }
}