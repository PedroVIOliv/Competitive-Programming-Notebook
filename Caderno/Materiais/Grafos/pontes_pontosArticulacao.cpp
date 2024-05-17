// pontes: arestas que se retiradas tornam o grafo desconexo
// pontos de articulação: nodes que se retirados tornam o grafo desconexo
vector< vector<int> > g;
vector< pair<int, int> > bridges;
set<int> articulation_points;
int vis[N], disc[N], low[N], tme = 1;

void dfs(int cur, int par) {
    vis[cur] = 1;
    disc[cur] = low[cur] = tme++;
    int child = 0;
    
    for(auto x : g[cur]) {
        if(!vis[x]) {
            child++;
            
            dfs(x, cur);

            low[cur] = min(low[cur], low[x]);

            if(low[x] > disc[cur])
                bridges.push_back({cur, x});

            if(par != 0 && low[x] >= disc[cur])
                    articulation_points.insert(cur);
        }
        else if(x != par)
            low[cur] = min(low[cur], disc[x]);
    }

    if(par == 0 && child > 1) // Root
        articulation_points.insert(cur);
}