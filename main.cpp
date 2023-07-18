#include<bits/stdc++.h>
//#include<iostream.h>
using namespace std;

void swap(int *arr, int a, int b) {
    int tmp = arr[a];
    arr[a] = arr[b];
    arr[b] = tmp;
}

void bubble_sort(int *arr) {
    int len = 5;
//    int len = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len - 1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(arr, j, j+1);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a, b;
//    scanf("%d %d", &a, &b);
//    cout << "Hello World" << " " << a << " " << b << "\n";
//    int x;
//    while(cin >> x) {
//       printf("%d\n", x);
//    }
//    freopen("input.txt", "r", stdin);
//    cout << stdin->_blksize << "\n";
    int * test = new int(5);
    const int *p = test;
    char carr[] = "Hello World";
    for(int i=0; carr[i]!='\0'; i++) {
        cout << carr[i] << '\n';
    }
    int arr1[5];
    int arr2[5];
    for (int i = 4; i >= 0; i--) {
        arr1[4-i] = i;
    }
    bubble_sort(arr1);
    for(int i : arr1) {
        cout << i << "\n";
    }
    int aaa  = 10;
    int* aaa_p = &aaa;
    int& aaa_r = aaa;
    aaa_r = 12;
    *aaa_p = 11;

    cout << aaa << " " << aaa_r << '\n';
    cout << *aaa_p << '\n';
    cout << aaa_p << " " << &aaa << '\n';
    cout << &aaa_r << '\n';
    int arr[4][2] = {{0, 0}, {0, 1}};
    queue<int> q;
    cout << &q << '\n';
    q.push(12);
    cout << &q << '\n';
    return 0;
}
