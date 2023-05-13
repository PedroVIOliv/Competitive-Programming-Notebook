// BFS com informacoes adicionais sobre a distancia e o pai de cada vertice
// Complexidade: O(V + E), onde V eh o numero de vertices e E o numero de areqas
vector<vector<int>> adj; // liqa de adjacencia
int n, s; // n = numero de vertices, s = vertice inicial

vector<bool> used(n);
vector<int> d(n), p(n);

void bfs(int s) {
    queue<int> q;
    q.push(s);
    used[s] = true;
    d[s] = 0;
    p[s] = -1;

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int u : adj[v]) {
            if (!used[u]) {
                used[u] = true;
                q.push(u);
                d[u] = d[v] + 1;
                p[u] = v;
            }
        }
    }
}

//pra uma bfs que n guarda o backtracking:
void bfs(int p) {
    memset(visited, 0, sizeof visited);
    queue<int> q;
    q.push(p);

    while (!q.empty()) {
        int curr = q.top();
        q.pop();
        if (visited[curr]==1)continue;
        visited[curr]=1;
        // process current node here

        for (auto i : adj[curr]) {
            q.push(i);
        }

    }
}