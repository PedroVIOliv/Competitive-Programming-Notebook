// Grafo com peso e peso pode ser qualquer valor
// Single source
// O(EV²)
vector<int> bellman_ford(int V, int src, vector< vector<int> > edges) {
    vector<int> dist(n+1, INT_MAX);
    dist[src] = 0;
    for(int i = 0; i < V - 1; i++) {
        for(auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            if(dist[u] != INT_MAX && dist[v] > dist[u] + wt)
                dist[v] = dist[u] + wt;
        }
    }
    for(auto edge : edges) {
        int u = edge[0];
        int v = edge[1];
        int wt = edge[2];
        if(dist[u] != INT_MAX and dist[v] > dist[u] + wt) // negative edge cycle
            exit(0);
    }
}