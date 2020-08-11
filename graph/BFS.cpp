//
// Created by Mohamed Hashim on 8/11/2020.
//
#include"bits/stdc++.h"
#include<iostream>

using namespace std;

const int N = 1e5 + 7;
vector<int> adj[N];
bool vis[N];
int dis[N];
int n, m;

// add src in queue and push all it's neighbours then pop that source and so on till queue became empty
void bfs_basic(int src) {
    vis[src] = true;
    queue<int> q;
    q.push(src);
    while (!q.empty()) {
        int u = q.front();
        cout << u << " ";
        q.pop();
        for (auto v : adj[u]) {
            if (!vis[v]) {
                vis[v] = true;
                q.push(v);
            }
        }
    }
}

void bfs(int src) {       // to traverse on graph and get the distance between each node and the source (as levels)
    vis[src] = true;
    queue<int> q;
    q.push(src);
    int lvl = 0;
    while (!q.empty()) {
        int sz = q.size();
        while (sz--) {
            int u = q.front();
            cout << u << " ";
            q.pop();
            dis[u] = lvl;
            for (auto v :adj[u]) {
                if (!vis[v]) {
                    vis[v] = true;
                    q.push(v);
                }
            }
        }
        lvl++;
    }
}

int main() {
#ifndef ONLINE_JUDGE
    FILE *stream;
    freopen_s(&stream, "..//input.in", "r", stdin);
#endif
    int u, v;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
//    bfs_basic(1);
    bfs(1);

    //print distances between each node to the source
    for (int i = 0; i < 10; ++i) {
        cout << i << "  " << dis[i] << endl;
    }
    return 0;
}
