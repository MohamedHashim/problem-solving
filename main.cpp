#include"bits/stdc++.h"
#include<iostream>

using namespace std;

const int N = 1e5 + 7;
vector<int> adj[N];
int vis[N];
int n, m;

void DFS(int u) {
    vis[u] = true;
    for (int v : adj[u]) {
        if (!vis[v])
            DFS(v);
    }
}

bool singleComponent() {
    int root = 1;
    DFS(root);

    for (int i = 1; i <= n; ++i) {
        if (vis[i] == 0) return false;
    }
    return true;
}

int main() {
#ifndef ONLINE_JUDGE
    FILE *stream;
    freopen_s(&stream, "..//input.in", "r", stdin);
#endif

    return 0;
}