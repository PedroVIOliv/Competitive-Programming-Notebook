// DFS para percorrer todos os vertices a partir do no inicial u
// Complexidade: O(V + E), onde V eh o numero de vertices e E o numero de arestas
vector<bool> visited;

void dfs(int u, vector<vector<int>> &adj) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v, adj);
        }
    }
}