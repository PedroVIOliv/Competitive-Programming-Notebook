// encontrar o emparelhamento máximo em um grafo bipartido não ponderado
// Um grafo bipartido é um grafo cujos vértices podem ser divididos em dois conjuntos disjuntos
// Um emparelhamento em um grafo bipartido é um conjunto de arestas tal que nenhuma aresta compartilha um vértice
#define NIL 0
#define INF INT_MAX
class BipGraph { // O(E sqrt(V))
    // m and n are number of vertices on left and right sides of bipartite graph
    int m, n;
    list<int> *adj;
    int *pairU, *pairV, *dist;

    public:
        BipGraph(int m, int n);
        void addEdge(int u, int v);
        bool bfs();
        bool dfs(int u);
        int hopcroftKarp();
};

// Returns size of maximum matching
int BipGraph::hopcroftKarp() { // O(V^(1/2) * E)
    // pairU[u] stores pair of u in matching (u is from left side)
    // If u doesn't have any pair, then pairU[u] is NIL
    pairU = new int[m + 1];
    pairV = new int[n + 1];

    // dist[u] stores distance of left side vertices
    // dist[u] is one more than dist[u'] if u is next to u' in augmenting path
    dist = new int[m + 1];

    for(int u = 0; u <= m; u++) pairU[u] = NIL;
    for(int v = 0; v <= n; v++) pairV[v] = NIL;

    int result = 0;
    // While there is an augmenting path
    while(bfs()) {
        // Find a free vertex
        for(int u = 1; u <= m; u++) {
            if(pairU[u] == NIL && dfs(u)) result++;
        }
    }
    return result;
}

// Returns true if there is an augmenting path
bool BipGraph::bfs() {
    queue<int> Q;
    for(int u = 1; u <= m; u++) {
        // Free vertex
        if(pairU[u] == NIL) {
            dist[u] = 0; // u is not matched
            Q.push(u);
        }
        else dist[u] = INF;
    }

    dist[NIL] = INF;
    // Q is going to contain vertices of left side only
    while(!Q.empty()) {
        int u = Q.front();
        Q.pop();

        // If this node is not NIL and can provide a shorter path to NIL
        if(dist[u] < dist[NIL]) {
            list<int>::iterator i;
    
            for(i = adj[u].begin(); i != adj[u].end(); ++i) {
                int v = *i;
    
                if(dist[pairV[v]] == INF) {
                dist[pairV[v]] = dist[u] + 1;
                Q.push(pairV[v]);
                }
            }
        }
    }
    return (dist[NIL] != INF);
}

// Returns true if there is an augmenting path beginning with free vertex u
bool BipGraph::dfs(int u) {
    if(u != NIL) {
        list<int>::iterator i;
        for(i = adj[u].begin(); i != adj[u].end(); ++i) {
            int v = *i;

            if(dist[pairV[v]] == dist[u] + 1) {
                if(dfs(pairV[v]) == true) {
                    pairV[v] = u;
                    pairU[u] = v;
                    return true;
                }
            }
        }
        dist[u] = INF;
        return false;
    }
    return true;
}

BipGraph::BipGraph(int m, int n) {
    this->m = m;
    this->n = n;
    adj = new list<int>[m + 1];
}

// ********* ONE BASED **************
void BipGraph::addEdge(int u, int v) {
    adj[u].pb(v);
}


// OUTRA MANEIRA
vi match, vis;
vector<vi> AL;

int Aug(int L) {
    if (vis[L]) return 0;
    vis[L] = 1;
    for (auto &R : AL[L])
        if ((match[R] == -1) || Aug(match[R])) {
            match[R] = L;
            return 1;
        }
    return 0;
}

int max_card() { // O(VE)
    int ans = 0;
    for(int i = 0; i < V; i++) {
        vis.assign(V, 0);;
        ans += Aug(i);
    }
    return ans;
}