//
// Created by Tabbit on 7/17/23.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    int s = 3;
    int n;
    cin >> n;
    int nums[n - 1];
    for (int i = 0; i < n - 1; i++) {
        cin >> nums[i];
    }
    double need = 2;
    int idx = 0;
    double cost = 0.0;
    while (need > 0 && idx < n - 1) {
        if (nums[idx] >= need * pow(2, idx)) {
            nums[idx] = need * pow(2, idx);
            break;
        } else {
            need -= nums[idx] / pow(2, idx);
        }
        idx += 1;
    }
    cout << setprecision(11);
    if (idx == n - 1) {
        cout << "impossible" << endl;
    } else {
        for (int i = idx; i >= 0; i--) {
            if (i > 0) nums[i - 1] += nums[i] / 2;
            cost += (pow(2.0, (-3.0 - i * 2.0) / 4.0) * nums[i] / 2.0);
        }
        cout << cost << endl;
    }

}

