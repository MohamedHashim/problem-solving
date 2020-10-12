#include"bits/stdc++.h"
#include<iostream>
#include <iterator>

using namespace std;

const int N = 1e5 + 7;


int main() {
#ifndef ONLINE_JUDGE
    FILE *stream;
    freopen_s(&stream, "..//input.in", "r", stdin);
#endif
    int dx[7] = {0, 0, 0, 1, 2, 2, 2};
    int dy[7] = {0, 1, 2, 1, 0, 1, 2};
    int sum, mx = -1e7;
    int arr[6][6];
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 6; ++j) {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            sum = 0;
            for (int k = 0; k < 7; ++k) {
                sum += arr[i + dx[k]][j + dy[k]];
            }
            mx = max(mx, sum);
        }
    }
    cout << mx << endl;
    return 0;
}