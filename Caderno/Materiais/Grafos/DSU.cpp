// id: iota(id.bb, id.ee, 0);
// sz: every el starts with 1
int numSets = N;
int find(int p) { // representative of each disjoint set
    return id[p] = (id[p] == p ? p : find(id[p]));
}
void set_union(int p, int q) {
    p = find(p); q = find(q);
    if(p == q) return;
    if(sz[p] > sz[q]) swap(p, q);
    id[p] = q; sz[q] += sz[p];
    numSets--;
}

// Tamanho do set que contém o elemento i
int sizeOfSet(int i) { return sz[find(i)]; }



// DSU 2D
int get_id(int i, int j) {
    return (i * M) + j;
}
int find(int p) {
    return p == id[p] ? p : find(id[p]);
}

void set_union_dsu(pair<int, int> p, pair<int, int> q) {
    int p_id = find(get_id(p.ff, p.ss));
    int q_id = find(get_id(q.ff, q.ss));
    if(p_id == q_id) return;
    if(sizes[p_id] > sizes[q_id]) swap(p, q);
    id[p_id] = q_id;
    sizes[q_id] += sizes[p_id];
}