// Computa a menor distancia de todos os vertices ate todos os outros vertices
// O(V³)
int g[N][N];
vector< vector<int> > floyd_warshall(vector< vector<int> > g) { // adj matrix
    vector< vector<int> > dis(g);
    int V = g.size();
    for(int k = 0; k < V; k++) {
        for(int i = 0; i < V; i++) {
            for(int j = 0; j < V; j++) {
                if(dis[i][j] > dis[i][k] + dis[k][j])
                    dis[i][j] = dis[i][k] + dist[k][j];
            }
        }
    }
    return dis;
}