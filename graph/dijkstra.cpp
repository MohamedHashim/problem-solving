//
// Created by Mohamed Hashim on 8/12/2020.
//
#include"bits/stdc++.h"
#include<iostream>

using namespace std;
const int N = 10e5 + 7;
// for each node save ( cost , toNode)
vector <pair<int, int>> adj[N];
//save shortest distance of each node from the source
int dis[N];
int n;  //number of nodes

// dijkstra goal is set the shortest path to each node from the source in weighted graph
void dijkstra(int src) {
    priority_queue <pair<int, int>> q;   // cost and node in priority queue to sort nodes instantly
    memset(dis, '?',n * sizeof dis[0]);    // fill all distance array with infinity because char '?' =(0x3f) in 4 bytes > 1e9

    dis[src] = 0;   //set first distance of source with 0
    q.push({0, src});

    while (!q.empty()) {
        //pop first item
        int d = -q.top().first;
        int u = q.top().second;
        q.pop();

        //compare the distance value in priority queue and distance array if diff continue because the value in distance array is already updated and has smaller value
        if (d != dis[u])continue;
        // loop on neighbours
        for (auto e :adj[u]) {
            int c = e.first;
            int v = e.second;
            //relaxation, check if the new distance is shorter than it's saved value or not
            int nd = dis[u] + c;
            if (nd < dis[v]) {
                dis[v] = nd;
                q.push({-nd, v});
            }
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    FILE *stream;
    freopen_s(&stream, "..//input.in", "r", stdin);
#endif

    int m, u, v, w;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> u >> v >> w;
        u--, v--;
        adj[u].emplace_back(w, v);
    }
    dijkstra(0);
    for (int i = 0; i < n; ++i) {
        cout << i + 1 << " : " << dis[i] << endl;
    }
    return 0;
}