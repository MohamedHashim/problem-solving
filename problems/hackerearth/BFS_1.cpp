//
// Created by Mohamed Hashim on 8/11/2020.
//
//////
////// BFS
////// BFS-1
///// https://www.hackerearth.com/problem/algorithm/BFS-1/description/
//
#include"bits/stdc++.h"
#include<iostream>

using namespace std;
const int N = 10e5 + 7;
vector<int> adj[N];
bool vis[N];
int dis[N];
int par[N];

void bfs(int src) {
    vis[src] = true;
    queue<int> q;
    q.push(src);
    par[src] = -1;  //with each push add parent, parent of the root is -1
    int lvl = 0;
    while (!q.empty()) {
        int sz = q.size();
        while (sz--) {
            int u = q.front();
            dis[u] = lvl;
            q.pop();
            for (auto v : adj[u]) {
                if (!vis[v]) {
                    vis[v] = true;
                    q.push(v);
                    par[v] = u; //with each push new node, add it's parent to get the path
                }
            }
        }
        lvl++;
    }
}

void printPath(int u) {
    if (u == -1)return;
    printPath(par[u]);
    cout << u << " ";
}

int main() {
#ifndef ONLINE_JUDGE
    FILE *stream;
    freopen_s(&stream, "..//input.in", "r", stdin);
#endif

    int t, n, v, s, g;
    cin >> t;
    while (t--) {
        cin >> n;
        adj->clear();             // to clear the adjacency list for each test case
        fill_n(vis, N, 0);  // to clear the visited array for each test case
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> v;
                if (v)
                    adj[i].push_back(j);
            }
        }
        cin >> s >> g;
        bfs(s);
        cout << dis[g] << endl;
        printPath(g);
        cout << endl;
    }
    return 0;
}
