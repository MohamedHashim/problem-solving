//
// Created by Mohamed Hashim on 8/12/2020.
//
#include<iostream>
#include"../bits/stdc++.h"

#define endl '\n'

using namespace std;
typedef long long ll;
const int N = 1e5 + 7, M = 2 * N;

vector <pair<int, int>> adj[N];

int t, n, m;
string s, g;

int dis[N];

void dijkstra(int src) {
    priority_queue <pair<int, int>> q;
    memset(dis, '?', n * sizeof dis[0]);
    dis[src] = 0;
    q.push({0, src});
    while (!q.empty()) {
        int u = q.top().second;
        int d = -q.top().first;
        q.pop();
        if (d != dis[u]) continue;
        for (auto e : adj[u]) {
            int v = e.first, c = e.second;

            int nd = dis[u] + c;
            if (nd < dis[v]) {
                dis[v] = nd;
                q.push({-nd, v});
            }
        }
    }
}

/*
s [the number of tests <= 10]
n [the number of cities <= 10000]
NAME [city name]
p [the number of neighbours of city NAME]
nr cost [nr - index of a city connected to NAME (the index of the first city is 1)]
           [cost - the transportation cost]
r [the number of paths to find <= 100]
NAME1 NAME2 [NAME1 - source, NAME2 - destination]
[empty line separating the tests]

 */

map<string, int> nameToIdx;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
#ifdef CLION
    freopen("in", "rt", stdin);
#endif
    cin >> t;
    while (t--) {
        nameToIdx.clear();
        cin >> n;
        for (int i = 0; i < n; ++i) {
            adj[i].clear();
            cin >> s >> m;
            nameToIdx[s] = i;
            while (m--) {
                int v, cst;
                cin >> v >> cst;
                adj[i].emplace_back(--v, cst);
            }
        }
        int r;
        cin >> r;
        while (r--) {
            cin >> s >> g;
            int u = nameToIdx[s], v = nameToIdx[g];
            dijkstra(u);
            cout << dis[v] << endl;
        }
    }

}