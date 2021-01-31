//
// Created by Mohamed Hashim on 1/31/2021.
//

#include"bits/stdc++.h"
#include<iostream>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    FILE *stream;
    freopen_s(&stream, "..//input.in", "r", stdin);
#endif
    string str1, str2;
    cin >> str1 >> str2;
    for (int i = 0; i < str1.size(); i++) {
        if (str1[i] != str2[str2.size() - 1 - i]) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}