// Find the minimum spanning tree and return it's cost
// It works only to connected graph. If it's not, apply it to each connected graph

ll r, c;
cin >> r >> c; // r = number of vertex, c = number of edges
vector<pair<int, pair<int, int>>> arestas;

for (int i = 0; i < c; i++){
    ll v, w, p;
    cin >> v >> w >> p; // p = weight, v and w are the two connected vertices 
    arestas.push_back({p, {v - 1, w - 1}});
}

sort(arestas.begin(), arestas.end());
double cost = 0;

vector<int> id(r);
for (int i = 0; i < r; i++) id[i] = i;

for (auto p : arestas){
    
    int x = p.s.f;
    int y = p.s.s;
    double w = p.f;

    if (id[x] != id[y]){
        cost += w;
        int old_id = id[x], new_id = id[y];
            
        for (int i = 0; i < r; i++)
            if (id[i] == old_id) id[i] = new_id;
    }
}

cout << cost << endl;