//
// Created by Mohamed Hashim on 8/7/2020.
//
//// DFS
////PT07Y - Is it a tree
////https://www.spoj.com/problems/PT07Y/
//
#include"bits/stdc++.h"
#include<iostream>

using namespace std;

const int N = 1e5 + 7;
vector<int> adj[N];
bool vis[N];
int n, m;

void DFS(int u) {
    vis[u] = true;
    for (int v : adj[u]) {
        if (!vis[v])
            DFS(v);
    }
}

// check if the graph if connected or not
bool singleComponent() {
    int root = 1;
    DFS(root);

    for (int i = 1; i <= n; ++i) {
        if (vis[i] == 0) return false;
    }
    return true;
}

bool DFS2(int u, int p) {
    vis[u] = true;
    for (auto v : adj[u]) {
        //cycle mean that child of any node isn't parent but visited before
        if (v == p)continue;
        if (vis[v])return false;
        //cascading to check if any call of recursion return false to break the recursion earlier as performance improvement
        if (!DFS2(v, u)) return false;
    }
    return true;
}

bool Acyclic() {
    for (int i = 1; i <= n; ++i) {
        if (vis[i]) continue; // to increase the performance to not recurse with visited node just recurse if there are not single components (not connected graph)
        if (!DFS2(i, -1))return false;
    }
    return true;
}

int main() {
#ifndef ONLINE_JUDGE
    FILE *stream;
    freopen_s(&stream, "..//input.in", "r", stdin);
#endif
    int u, v;
    cin >> n >> m;
    // building the graph
    for (int i = 0; i < m; ++i) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // check if this graph is tree or not
    // any two of the following three condition are enough to prove this graph is tree
    cout << (Acyclic() && singleComponent() && m == (n - 1) ? "YES" : "NO") << endl;
    return 0;
}
