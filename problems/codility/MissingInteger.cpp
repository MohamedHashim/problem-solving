//
// Created by Mohamed Hashim on 10/28/2020.
//

#include"bits/stdc++.h"
#include<iostream>

using namespace std;

int solution(vector<int> &A) {
    set<int> s;
    for (int &i : A)
        s.insert(i);
    auto iter = s.begin();
    int x =1;
    while (iter != s.end()) {
        if (*iter < 1) {
            iter++;
            continue;
        } else {
            if (*iter != x)
                return x;
            iter++;
            x++;
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    FILE *stream;
    freopen_s(&stream, "..//input.in", "r", stdin);
#endif

    vector<int> v = {-1, 3, 6, 4, 1, 2};
    cout << solution(v) << endl;
    return 0;
}