//
// Created by Tabbit on 7/16/23.
//

#include "weak_vertices.h"
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    while (true) {
        cin >> n;
        if (n == -1) {
            break;
        }
        int nums[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> nums[i][j];
            }
        }
        int rst[n];
        for (int i = 0; i < n; i++) {
            rst[i] = -1;
        }
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i][j] == 0) {
                    continue;
                }
                for (int k = j + 1; k < n; k++) {
                    if (nums[i][k] == 0) {
                        continue;
                    }
                    if (nums[j][k] == 1) {
                        rst[i] = 0;
                        rst[j] = 0;
                        rst[k] = 0;
                    }
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (rst[i] == -1) {
                cout << i << " ";
            }
        }
        cout << '\n';
    }

}
