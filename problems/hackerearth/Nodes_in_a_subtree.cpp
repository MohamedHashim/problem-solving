//
// Created by Mohamed Hashim on 8/9/2020.
//
////
//// SubTree
////Nodes in a subtree
////https://www.hackerearth.com/practice/data-structures/trees/binary-and-nary-trees/practice-problems/algorithm/magical-tree-1-e7f8cabd/submissions/

#include"bits/stdc++.h"
#include<iostream>

using namespace std;

const int N = 1e5 + 7;
vector<int> adj[N];
string s;
int arr[N][26];

void DFS(int u, int p) {
    arr[u][s[u] - 'a']++;
    for (auto v: adj[u]) {
        if (v == p)continue;
        DFS(v, u);
        for (int i = 0; i < 26; ++i) {
            arr[u][i] += arr[v][i];
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    FILE *stream;
    freopen_s(&stream, "..//input.in", "r", stdin);
#endif
    int n, q, u, v, x;
    char ch;
    cin >> n >> q >> s;
    for (int i = 0; i < n - 1; ++i) {
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    DFS(0, -1);
    for (int i = 0; i < q; ++i) {
        cin >> x >> ch;
        cout << arr[x - 1][ch - 'a'] << endl;
    }
    return 0;
}