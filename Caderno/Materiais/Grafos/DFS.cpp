// DFS para percorrer todos os vertices a partir do no inicial u
// Complexidade: O(V + E), onde V eh o numero de vertices e E o numero de arestas
int explore(int u)
{
    visited[u] = true;
    int c = 1;
    for (int v : adj[u])
        if (!visited[v])
           c += explore(v);
    return c;
}