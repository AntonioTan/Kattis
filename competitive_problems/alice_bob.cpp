//
// Created by Tabbit on 7/16/23.
//

#include "alice_bob.h"
#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    if (n % 2 == 0) {
        cout << "Bob";
    } else {
        cout << "Alice";
    }
}