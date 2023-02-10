vector<vector<pair<int, int>>> adj;
int n, s; 

vector<int> d(n, LLINF);
vector<int> p(n, -1);
vector<bool> used(n); 

//Complexidade: O((V + E)logV)
void dijkstra(int s) {
    d[s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({0, s});
    while (!q.empty()) {
        int v = q.top().second;
        q.pop();
        if (used[v]) continue;
        used[v] = true;
        for (auto edge : adj[v]) {
            int to = edge.first, len = edge.second;
            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                p[to] = v;
                q.push({d[to], to});
            }
        }
    }
}

//Complexidade: O(V)
vector<int> restorePath(int v) {
    vector<int> path;
    for (int u = v; u != -1; u = p[u])
        path.push_back(u);
    reverse(path.begin(), path.end());
    return path;
}