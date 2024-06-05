// Nos podemos simular delecao de arestas atribuindo INF
// a aresta deletada
#include "bits/stdc++.h"
using namespace std;
#define all(x) begin(x),end(x)
typedef long long ll;
typedef vector<int> vi;

const int oo = 1e9;

struct DSU{
    vector<int> sz,parent;
    int components;
    void reset(int n) {
        fill(sz.begin(),sz.begin()+n,1);
        iota(parent.begin(),parent.begin()+n,0);
        components=n;
    }
    DSU(int n) : sz(n),parent(n) {
        reset(n);
    }
    void link(int a, int b) {
        components--;
        if(sz[a]<sz[b]) swap(a,b);
        sz[a]+=sz[b];
        parent[b] = a;
    }
    bool unite(int a, int b) {
        int pa = find(a), pb = find(b);
        if(pa!=pb) {
            link(pa,pb);
            return true;
        }
        return false;
    }
    int find(int a) {
        if(a==parent[a]) return a;
        return parent[a] = find(parent[a]);
    }
};

struct dynamicMST {
    struct edge {
        int l,r;
        int u,v,w;
        bool operator<(const edge& o) {
            return w<o.w;
        }
    };
    vector<edge> ives; // edges + time interval that they are active.
    vector<array<int,3>> startes; 
    vi touch; // last time this edge was touched
    int totaln;
    DSU dsu,dsu2;
    vi id;
    dynamicMST(vector<array<int,3>> ES, int n) : startes(ES), touch(ES.size()), totaln(n), dsu(n),dsu2(n), id(n)  {
        // give all edges upfront.
    }
    int q=0;
    void update(int i, int x) {
        // update edge weight of edge i to x
        // if you want to delete the edge, just set it to infinity
        q++;
        auto& [u,v,w] = startes[i];
        ives.push_back({touch[i],q,u,v,w});
        touch[i]=q;
        w = x;
    }
    vector<ll> ans;
    void solve(int l, int r, vector<edge> es, int n, ll cost=0) {
        // remove edges that don't belong to this interval
        es.erase(stable_partition(all(es),[&](const edge& e) {return !(e.r<=l or r<=e.l);}),es.end());
        dsu.reset(n),dsu2.reset(n);

        // compressing connected components
        for(auto& e : es) if(l<e.l or e.r<r) { // active edges
            dsu.unite(e.u,e.v);
        }
        
        for(auto& e : es) if(e.l<=l and r<=e.r) { // fully overlapping edges
            if(dsu.unite(e.u,e.v)) {
                cost+=e.w;
                dsu2.unite(e.u,e.v);
            }
        }

        if(l+1==r) { // base case, we found the MST.
            ans[l]=cost;
            return;
        }

        int cnt=0; // relabel all connected components to 0...cnt-1
        for(int i=0;i<n;++i) if(dsu2.find(i)==i) id[i]=cnt++;
        dsu.reset(cnt);
        for(auto& e : es) { // relabeling and marking useless edges
            e.u = id[dsu2.find(e.u)], e.v = id[dsu2.find(e.v)];
            if(e.l<=l and r<=e.r) {
                if(!dsu.unite(e.u,e.v)) e.l=oo,e.r=-oo; // mark useless edge, will get deleted in next step
            }
        }
        int m = (l+r)/2;
        solve(l,m,es,cnt,cost);
        solve(m,r,es,cnt,cost);
    }
    vector<ll> run() {
        int m = startes.size();
        q++;
        for(int i=0;i<m;++i) {
            auto& [u,v,w] = startes[i];
            ives.push_back({touch[i],q,u,v,w});
        }
        
        sort(all(ives)); // (q+m) log(q+m) time
        ans.resize(q);
        solve(0,q,ives,totaln); // (q+m) log(q) alpha(n) time
        return ans;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,q; cin >> n >> m >> q;
    vector<array<int,3>> es(m);

    for(auto& [u,v,w] : es) {
        cin >> u >> v >> w;
        --u,--v;
    }

    dynamicMST mst(es,n);

    for(int i=0;i<q;++i) {
        int k,d;
        cin >> k >> d, --k;
        mst.update(k,d);
    }
    auto ans = mst.run();
    for(int i=1;i<=q;++i) { // ans[0] gives the MST cost of the initial MST.
        cout << ans[i] << '\n'; // MST cost after the i first updates
    }
    
}