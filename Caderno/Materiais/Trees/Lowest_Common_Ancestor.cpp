// 1 based
const int N = 1e5 + 1, M = 20; // log (N)
vector<int> gr[N];
int dep[N], Par[N][M];
void dfs(int cur, int par) {
    Par[cur][0] = par;
    dep[cur] = dep[par] + 1;
    for(int j = 1; j < M; j++)
        Par[cur][j] = Par[Par[cur][j-1]][j-1];
    
    for(auto x : gr[cur])
        if(x != par) dfs(x, cur);
}

int LCA(int u, int v) {
    if(u == v) return u;
    if(dep[u] < dep[v]) swap(u, v);
    int diff = dep[u] - dep[v];
    // same level
    for(int j = M - 1; j >= 0; j--) {
        if((diff >> j) & 1) // jth bit set
        u = Par[u][j];
        if(u == v) return u;
    }
    // The nodes below the lca
    for(int j = M - 1; j >= 0; j--) {
        if(Par[u][j] != Par[v][j]) { // jth bit set
            u = Par[u][j];
            v = Par[v][j];
        }
    }
    return Par[u][0];
}

int lengthUtoV(int u, int v) {
    int lca = LCA(u, v);
    return dep[u] + dep[v] - 2 * dep[lca];
}