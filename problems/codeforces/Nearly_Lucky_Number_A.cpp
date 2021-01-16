//
// Created by Mohamed Hashim on 1/16/2021.
//
#include"bits/stdc++.h"
#include<iostream>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    FILE *stream;
    freopen_s(&stream, "..//input.in", "r", stdin);
#endif
    string str;
    int cnt = 0;
    cin >> str;
    for (char chr : str) {
        if (chr == '4' || chr == '7')
            cnt++;
    }
    if (cnt == 4 || cnt == 7)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}

