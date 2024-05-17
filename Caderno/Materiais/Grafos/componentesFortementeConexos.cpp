// Verificar se é possível ir para todos os vértices partindo de qualquer vértice
// Para grafos direcionados
// O(V+E)
class Graph {
    int V;    // No. of vertices
    list<int> *adj; // An array of adjacency lists
    void DFSUtil(int v, bool visited[]);
public:
    Graph(int V) { this->V = V;  adj = new list<int>[V];}
    ~Graph() { delete [] adj; }
    void addEdge(int v, int w);
    bool isSC();
    Graph getTranspose();
};
 
// A recursive function to print DFS starting from v
void Graph::DFSUtil(int v, bool visited[]) {
    visited[v] = true;
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFSUtil(*i, visited);
}
 
// Function that returns reverse (or transpose) of this graph
Graph Graph::getTranspose() {
    Graph g(V);
    for (int v = 0; v < V; v++) {
        list<int>::iterator i;
        for(i = adj[v].begin(); i != adj[v].end(); ++i) {
            g.adj[*i].push_back(v);
        }
    }
    return g;
}
 
void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);
}
 
// returns true if graph is strongly connected
bool Graph::isSC() {
    bool visited[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
 
    DFSUtil(0, visited);
 
    for (int i = 0; i < V; i++)
        if (visited[i] == false)
             return false;
 
    Graph gr = getTranspose();
 
    for(int i = 0; i < V; i++)
        visited[i] = false;
 
    // Do DFS for reversed graph starting from
    // first vertex. Starting Vertex must be same starting
    // point of first DFS
    gr.DFSUtil(0, visited);
 
    for (int i = 0; i < V; i++)
        if (visited[i] == false)
             return false;
 
    return true;
}