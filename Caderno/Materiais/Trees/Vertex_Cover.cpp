// encontrar o tamanho mínimo de um conjunto de vértices que cobre todas as arestas de uma árvore
const int MAXN = 200010;
int dp[MAXN][2];
vector<int> adj[MAXN];
// vertexCover(node current, free to choose, dad)
int vertexCover(int u, bool color=true, int p=-1) {
    if(dp[u][color] != -1) return dp[u][color];
    
    int case1 = 1, case2 = 0;
    for(int to: adj[u]) {
        if(to == p) continue;
        case1 += vertexCover(to, true, u);
        case2 += vertexCover(to, false, u);
    }
    
    if(color) return dp[u][color] = min(case1, case2);
    else return dp[u][color] = case1;
}

int result = vertexCover(0, true, -1);
cout << "Tamanho mínimo do Vertex Cover: " << result << endl;