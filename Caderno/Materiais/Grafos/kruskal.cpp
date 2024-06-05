//vector<pair<int,int>> arestas[MAXN] em que cada aresta[i] contem o peso e o vertice adjacente
//vector<peso,conexao>
vector<pair<int,int>> adj[MAXN];
vector<pair<int,int>> adjtree[MAXN];
vector<pair<int, pair<int, int>>> kruskadj;
int cost;
void kruskal(){
    for(int i = 1;i<MAXN;i++){
        for(auto j:adj[i]){
            kruskadj.push_back({j.first,{i,j.second}});
        }
    }
    // to get the maximum spanning tree, sort in decreasing order

    // Poderiamos ordenar de outra forma, por exemplo: 
    // ordenar (kruskadj.begin(), kruskadj.begin() + F)
    // depois ordenar(kruskadj.begin() + F, kruskadj.end())
    // Por exemplo, queremos minimizar o custo, mas também a quantidade de rodovias
    // Sabendo que rodovias fica depos de kruskadj.begin() + F
    sort(kruskadj.begin(),kruskadj.end());
    cost=0;
    int r = kruskadj.size();
    vector<int> id(r);
    for (int i = 0; i < r; i++) id[i] = i;
    for (auto p : kruskadj){
        int x = p.second.first;
        int y = p.second.second;
        int w = p.first;
        if (id[x] != id[y]){
            cost += w;
            adjtree[x].push_back({w,y});
            int old_id = id[x], new_id = id[y];
            for (int i = 0; i < r; i++)
                if (id[i] == old_id) id[i] = new_id;
        }
    }

}

