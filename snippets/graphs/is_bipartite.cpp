#include <vector>
using namespace std;

bool bad = false;

vector<vector<int>> adj;
vector<bool> vis;
vector<bool> col;

void dfs(int u = 0) {
    for (int v : adj[u]) {
        if (vis[v])
            bad |= col[v] == col[u];
        else {
            vis[u] = true;
            col[v] = !col[u];
            dfs(v);
        }
    }
}
