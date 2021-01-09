//
// Created by Mohamed Hashim on 1/9/2021.
//
#include"bits/stdc++.h"
#include<iostream>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    FILE *stream;
    freopen_s(&stream, "..//input.in", "r", stdin);
#endif
    int k, n, w, cost = 0;
    cin >> k >> n >> w;
    for (int i = 1; i <= w; i++) {
        cost += i * k;
    }
    if (cost != n)
        cout << abs(cost - n) << endl;
    else
        cout << 0 << endl;
    return 0;
}

