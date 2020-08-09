////
//// Created by Mohamed Hashim on 8/9/2020.
////
////// DFS
//////PT07Z - Longest path in a tree
/////https://www.spoj.com/problems/PT07Z/
////
//#include"bits/stdc++.h"
//#include<iostream>
//
//using namespace std;
//const int N = 1e5 + 7;
//vector<int> adj[N];
//int n, best, mx = 0;
//
//void DFS(int u, int p, int d) {
//    if (d > mx) {
//        mx = d;
//        best = u;
//    }
//
//    for (auto v : adj[u]) {
//        if (v == p) continue;
//        DFS(v, u, d + 1);
//    }
//}
//
//int FarthestFrom(int u) {
//    mx = 0;
//    DFS(u, -1, 0);
//    return best;
//}
//
//int longestPath() {
//    int r = FarthestFrom(1);
//    FarthestFrom(r);
//    return mx;
//}
//
//int main() {
//#ifndef ONLINE_JUDGE
//    FILE *stream;
//    freopen_s(&stream, "..//input.in", "r", stdin);
//#endif
//
//    int u, v;
//    cin >> n;
//    for (int i = 0; i < n - 1; ++i) {
//        cin >> u >> v;
//        adj[u].push_back(v);
//        adj[v].push_back(u);
//    }
//    cout << longestPath() << endl;
//    return 0;
//}