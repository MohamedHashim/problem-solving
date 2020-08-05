//
// Created by Mohamed Hashim on 8/5/2020.
//

#include"bits/stdc++.h"
#include<iostream>

using namespace std;

// Adjency Matrix representation

const int N = 1e5 + 7;
bool adj[N][1000];

//nodes, edges, query
int n, m, q, from, to, x;

int main() {
    cin >> n >> m >> q;
    for (int i = 0; i < m; ++i) {
        cin >> from >> to;
        adj[from][to] = true;
//        adj[to][from] = true;     //if graph is undirected
    }
    for (int j = 0; j < q; ++j) {
        cin >> x;
        int neighbours_size = sizeof(adj[0]) / sizeof(int);
        int cnt = 0;
        for (int i = 0; i < neighbours_size; ++i) {
            if (adj[x][i])
                cnt++;
        }

        cout << cnt << " ";
        for (int i = 0; i < neighbours_size; ++i) {
            if (adj[x][i])
                cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}