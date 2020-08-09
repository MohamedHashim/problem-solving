//
// Created by Mohamed Hashim on 8/9/2020.
//
// Tree
//Monk at the Graph Factory
//https://www.hackerearth.com/practice/algorithms/graphs/graph-representation/practice-problems/algorithm/monk-at-the-graph-factory/description/
#include"bits/stdc++.h"
#include<iostream>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    FILE *stream;
    freopen_s(&stream, "..//input.in", "r", stdin);
#endif

    int n, e, sum = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> e;
        sum += e;
    }
    cout << (((sum / 2) == (n - 1)) ? "Yes" : "No");
    return 0;
}