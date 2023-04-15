//encontra arvore geradora minima dado um ponto inicial
//melhor para grafos densos - O(V^2)

vector<pair<double,int>> adj[MAXN];
vector<pair<double,int>> mst[MAXN];

double prim(int start) { 
    double cost = 0;
    vector<double> dist(MAXN, DBL_MAX);
    vector<bool> vis(MAXN, false);
    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;
    pq.push({0, start});
    dist[start] = 0;
    while(!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        if(vis[u]) continue;
        vis[u] = true;
        cost += dist[u];
        for(auto v : adj[u]) {
            double weight = v.first;
            int next = v.second;
            if(!vis[next] && weight < dist[next]) {
                dist[next] = weight;
                pq.push({dist[next], next});
                mst[u].push_back({weight, next});
                mst[next].push_back({weight, u});
            }
        }
    }
    return cost;
}