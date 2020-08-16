//
// Created by Mohamed Hashim on 8/16/2020.
//

#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
typedef long long ll;
const int N = 153, M = 5003, OO = 0x3f3f3f3f;

int n, m, q;

vector<pair<int, int>> adj[N];

int dis[N];
int inQ[N], vid;

//returns true if there is no negative cycle
//O(VE)
bool bellman(int src, int snk) {
    ++vid;
    memset(dis, '?', n * sizeof dis[0]);
    queue<int> changed;

    dis[src] = 0;
    inQ[src] = vid, changed.push(src);

    for (int k = 0; k <= 2 * n; ++k) {
        int sz = changed.size();
        while (sz--) {
            int u = changed.front();
            changed.pop();
            inQ[u] = 0;

            for (auto e : adj[u]) {
                int v = e.first;
                int c = e.second;
                if (dis[u] != OO && dis[u] + c < dis[v]) {
                    if (k >= n && v == snk) return false;
                    dis[v] = dis[u] + c;
                    if (inQ[v] != vid) inQ[v] = vid, changed.push(v);
                }
            }
        }
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
#ifdef CLION
    freopen("in", "rt", stdin);
#endif
    while (cin >> n >> m >> q, n || m || q) {
        for (int i = 0; i < n; ++i) {
            adj[i].clear();
        }
        for (int i = 0; i < m; ++i) {
            int u, v, c;
            cin >> u >> v >> c;
            //edges[i] = {u, v, c};
            adj[u].emplace_back(v, c);
        }
        for (int i = 0; i < q; ++i) {
            int u, v;
            cin >> u >> v;
            if (!bellman(u, v)) cout << "-Infinity\n";
            else {
                if (dis[v] >= OO) cout << "Impossible\n";
                else cout << dis[v] << endl;
            }
        }
        cout << endl;
    }

}