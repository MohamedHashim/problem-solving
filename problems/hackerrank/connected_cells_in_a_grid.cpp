//
// Created by Mohamed Hashim on 8/11/2020.
//
//////
////// DFS in grid
////// Connected Cells in a Grid
////// https://www.hackerrank.com/challenges/connected-cell-in-a-grid/problem
//
#include"bits/stdc++.h"
#include<iostream>
#include <algorithm>

using namespace std;
bool vis[10][10];
int grid[10][10];
int n, m;
int cnt;

int di[] = {0, 1, 1, 0, -1, -1, 1, -1};
int dj[] = {1, 0, 1, -1, 0, -1, -1, 1};

int dfs(int i, int j) {
    vis[i][j] = true;
    cnt += grid[i][j];
    for (int k = 0; k < 8; ++k) {
        if (i + di[k] < n && j + dj[k] < m && i + di[k] >= 0 && j + dj[k] >= 0)
            if (grid[i + di[k]][j + dj[k]] == 1 && !vis[i + di[k]][j + dj[k]])
                dfs(i + di[k], j + dj[k]);
    }
    return cnt;
}

int main() {
#ifndef ONLINE_JUDGE
    FILE *stream;
    freopen_s(&stream, "..//input.in", "r", stdin);
#endif

    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
        }
    }

    int res = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == 1) {
                if (!vis[i][j]) {
                    cnt = 0;
                    res = max(res, dfs(i, j));
                }
            }
        }
    }
    cout << res << endl;
    return 0;
}