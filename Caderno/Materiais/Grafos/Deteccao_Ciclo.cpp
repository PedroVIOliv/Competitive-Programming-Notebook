// Detecção de ciclo em grafo direcionado
bool dfs(int node, vector<bool> &visited, vector<bool> &stack) {
    visited[node] = true;
    stack[node] = true;
    for(int nbr : gr[node]) {
        if(stack[nbr]) return true;
        else if(!visited[nbr]) {
            bool nbrFoundACycle = dfs(nbr, visited, stack);
            if(nbrFoundACycle)
            return true;
        }
    }
    stack[node] = false;
    return false;
}
bool isThereCycle() {
    vector<bool> visited(V, false);
    vector<bool> stack(V, false);
    for(int i = 0; i < V; i++) {
        if(!visited[i])
            if(dfs(i, visited, stack)) return true;
    }
    return false;
}

// Detecção de ciclo em grafo não direcionado
bool dfs(int node, vector<int> &visited, int parent) {
    visited[node] = true;
    for(auto nbr : l[node]) {
        if(!visited[nbr]) {
            bool nbrFoundACycle = dfs(nbr, visited, node);
            if(nbrFoundACycle) return true;
        }
        else if(nbr != parent) return true;
    }
    return false;
}
bool contains_cycle() {
    vector<bool> visited(V, false);
    return dfs(0, visited, -1);
}