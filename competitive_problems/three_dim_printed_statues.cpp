//
// Created by Tabbit on 7/16/23.
//

#include "three_dim_printed_statues.h"

#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    int rst = 0;
    int num_printer = 1;
    while (num_printer < n) {
        num_printer *= 2;
        rst += 1;
    }
    cout << rst+1 << "\n";
}
