// Com lazy propagation, podemos fazer atualizações de ranges em O(logn)
struct segtree {
    vector<int> st, lz;
    int n;

    void init(int _n) {
        this->n = _n;
        st.resize(4*n, 0);
        lz.resize(4*n, 0);
    }

    void build(int l, int r, int node, vector<int> &v) {
        if(l == r) st[node] = v[l];
        else {
            int m = (l+r)/2;
            build(l, m, 2*node, v);
            build(m+1, r, 2*node + 1, v);
            st[node] = st[2*node] + st[2*node + 1];
        }
    }

    void push(int node, int l, int r) {
        if(lz[node]) {
            st[node] += lz[node] * (r-l+1);
            if(l != r) {
                lz[2*node] += lz[node];
                lz[2*node+1] += lz[node];
            }
            lz[node] = 0;
        }
    }

    int query(int ql, int qr, int l, int r, int node) {
        push(node, l, r);
        if(ql > r || qr < l) return 0;
        if(ql <= l && r <= qr) return st[node];
        int m = (l+r)/2;
        return query(ql, qr, l, m, 2*node) + 
            query(ql, qr, m+1, r, 2*node + 1);
    }

    void update(int l, int r, int node, int ql, int qr, int value) {
        push(node, l, r);
        if(qr < l || r < ql) return;
        if(ql <= l && r <= qr) {
            lz[node] += value;
            push(node, l, r);
        }
        else {
            int m = (l+r)/2;
            update(l, m, 2*node, ql, qr, value);
            update(m+1, r, 2*node+1, ql, qr, value);

            st[node] = st[2*node] + st[2*node+1];
        }
    }
};