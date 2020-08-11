//
// Created by Mohamed Hashim on 8/11/2020.
//

#include"bits/stdc++.h"
#include<iostream>

using namespace std;
const int N = 10e5 + 7;
vector<int> adj[N];

int main() {
#ifndef ONLINE_JUDGE
    FILE *stream;
    freopen_s(&stream, "..//input.in", "r", stdin);
#endif


    int n, v;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> v;
            if (v)
                adj[i].push_back(j);
        }
    }

    return 0;
}