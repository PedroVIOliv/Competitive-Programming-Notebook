// Verificar se o grafo é bipartido
bool dfsHelper(vector<int> graph[], int node, int *vis, int parent, int color) {
    vis[node] = color; // 2 or 1
    for(auto nbr : graph[node]) {
        if(!vis[nbr]) {
            int subprob = dfsHelper(graph, nbr, vis, node, 3 - color);
            if(!subprob) return false;
        }
        else if(nbr != parent && color == vis[nbr]) return false;
    }
    return true;
}

bool dfs(vector<int> graph, int N) {
    int vis[N] = {0};
    int color = 1;
    int ans = dfsHelper(graph, 0, vis, -1, color);
    return ans;
}