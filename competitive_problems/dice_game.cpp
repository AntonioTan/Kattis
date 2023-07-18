//
// Created by Tabbit on 7/16/23.
//

#include "dice_game.h"
#include <bits/stdc++.h>
using namespace std;

int main() {
    int nums[] = {0, 0};

    for(int i=0; i<2; i++) {
        for(int j=0; j<4; j++) {
            int num = 0;
            cin >> num;
            nums[i] += num;
        }
    }
    if(nums[0]<nums[1]) {
        cout << "Emma";
    } else if(nums[0]==nums[1]){
        cout << "Tie";
    } else {
        cout << "Gunnar";
    }
}
