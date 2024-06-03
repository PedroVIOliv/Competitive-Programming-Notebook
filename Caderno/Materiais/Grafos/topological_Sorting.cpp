// Ordem de execução de nodes, por exemplo, o node 1 deve ser executado antes do node 2
// N: number of nodes
// in[i]: quantas arestas 'entram' no vértice i
bool top_sort() {
    // greater<int> to sort it in decreasing order
    priority_queue<int, vector<int>, greater<int> > pq;
    for(int i = 0; i < N; i++)
        // não depende de ninguém
        if(in[i] == 0) pq.push(i);

    while(!pq.empty()) {
        int u = pq.top(); pq.pop();
        top_order.pb(u);
        vis[u] = 1;
        for(auto nbr : gr[u]) {
            if(!vis[nbr] && --in[nbr] == 0)
                pq.push(nbr);
        }
    }

    return N == top_order.sz; // dead-lock
}


// Outra maneira para fazer
// Directed Acyclic Graph
void topological_sort() {
    for(int i = 0; i < V; i++)
        for(auto nbr : g[i])
            indegree[nbr]++;

    queue<int> q;

    for(int i = 0; i < V; i++)
        if(indegree[i] == 0) q.push(i);

    while(!q.empty()) {
        int node = q.front();
        cout << node << endl;
        q.pop();
        for(auto nbr : g[node]) {
            indegree[nbr]--;
            if(!indegree[nbr]) q.push(nbr);
        }
    }
}