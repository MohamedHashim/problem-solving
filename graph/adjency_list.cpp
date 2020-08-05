//
// Created by Mohamed Hashim on 8/5/2020.
//

#include"bits/stdc++.h"
#include<iostream>

using namespace std;

// Adjency List representation

const int N = 1e5 + 7;
vector<int> adj[N];

//nodes, edges, query
int n, m, q, from, to, x;

int main() {
    cin >> n >> m >> q;
    for (int i = 0; i < m; ++i) {
        cin >> from >> to;
        adj[from].push_back(to);
//        adj[to].push_back(from);      //if graph is undirected
    }
    for (int j = 0; j < q; ++j) {
        cin >> x;
        cout << adj[x].size() << " ";
        for (int i = 0; i < adj[x].size(); ++i) {
            cout << adj[x][i] << " ";
        }
        cout << endl;
    }

    return 0;
}