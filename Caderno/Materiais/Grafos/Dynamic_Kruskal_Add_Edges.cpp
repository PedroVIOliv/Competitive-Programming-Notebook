/*
* Code for URI 1887
* It gives an tree and a bunch of queries to add
* edges from a to b with cost c.
*/
const int MOD = 1e9 + 9;
struct ed{
    int u,v,w,t;
    ed(int _u, int _v, int _w, int _t){ u=_u,v=_v,w=_w,t=_t;}
    ed(){};
    bool operator < ( const ed &a) const {
        return w<a.w;
    }
};
const int N=50010;
int p[N],id[N];
void init(int n) {
    for(int i=1;i<=n;i++) p[i]=i;
}
int findSet(int i) {
    if(p[i]==i) return i;
    return p[i]=findSet(p[i]);
}
bool unionSet(int i, int j) {
    int x=findSet(i),y=findSet(j);
    if(x==y) return false;
    p[x]=y;
    return true;
}
void reduction(int l,int r,int &n,vector<ed> &graph,int &res) {
    vector<ed> g;
    init(n);
    sort(graph.begin(),graph.end());
    for(int i=0;i<graph.size();i++)
        if(graph[i].t<=r and (graph[i].t>=l or unionSet(graph[i].u,graph[i].v)))
            g.pb(graph[i]);
    graph=g;
}
void contraction(int l,int r,int &n,vector<ed> &graph,int &res) {
    vector<ed> g;
    init(n);
    sort(graph.begin(),graph.end());
    for(int i=0;i<(int)graph.size();i++)
        if(graph[i].t>=l) unionSet(graph[i].u,graph[i].v);
    for(int i=0;i<(int)graph.size();i++){
        if(graph[i].t<l and unionSet(graph[i].u,graph[i].v)){
            g.pb(graph[i]);
            res+=graph[i].w;
        }
    }
    init(n);
    for(int i=0;i<g.size();i++)
        unionSet(g[i].u,g[i].v);
    int tot=0;
    for(int i=1;i<=n;i++) id[i]=0;
    for(int i=1;i<=n;i++){
        int f=findSet(i);
        if(!id[f]) id[f]=++tot;
        id[i]=id[f];
    }
    for(int i=0;i<graph.size();i++)
        graph[i].u=id[graph[i].u],graph[i].v=id[graph[i].v];
    n=tot;
}
void solve(int l,int r,int n,vector<ed> graph,int res) {
    reduction(l,r,n,graph,res);
    contraction(l,r,n,graph,res);
    if(l==r) {
        init(n);
        sort(graph.begin(),graph.end());
        for(int i=0;i<(int)graph.size();i++)
            if(unionSet(graph[i].u,graph[i].v))
                res+=graph[i].w;
        cout << res << endl;
        return;
    }
    int mid=(l+r)/2;
    solve(l,mid,n,graph,res);
    solve(mid+1,r,n,graph,res);
}
int main() {
    int T;
    cin >> T;
    while(T--) {
        int n,m,q;
        cin >> n >> m >> q;
        vector<ed> graph;
        for(int i=1;i<=m;i++) {
            int u,v,w;
            cin >> u >> v >> w;
            int t=0;
            graph.pb(ed(u,v,w,t));
        }
        for(int i=1;i<=q;i++) {
            int u,v,w;
            cin >> u >> v >> w;
            int t=i;
            graph.pb(ed(u,v,w,t));
        }
        solve(1,q,n,graph,0);
    }
    return 0;
}