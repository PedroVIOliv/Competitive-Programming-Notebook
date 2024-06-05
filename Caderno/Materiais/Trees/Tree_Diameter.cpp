// The maximum distance between two nodes in a tree
void dfs(int cur, int par) {
    int max_1 = 0, max_2 = 0;
    for (auto x : gr[cur]) {
        if (x != par) {
            dfs(x, cur);
            // g for the cur node
            g[cur] = max(g[x] + 1, g[cur]);
            f[cur] = max(f[x], f[cur]);
            // max 2 values of g[x]
            if (g[x] + 1 > max_1) {
                max_2 = max_1;
                max_1 = g[x] + 1;
            }
            else if (g[x] + 1 > max_2)
            max_2 = g[x] + 1;
        }
    }
    f[cur] = max(f[cur], max_1 + max_2);
}