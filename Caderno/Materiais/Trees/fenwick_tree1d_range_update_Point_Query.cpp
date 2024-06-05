// 0-based
struct FenwickTreeRangeUpdatePointQuery {
    vector<int> bit;  // binary indexed tree
    int n;

    FenwickTreeRangeUpdatePointQuery(int n) {
        this->n = n + 1;
        bit.assign(n + 1, 0);
    }

    FenwickTreeRangeUpdatePointQuery(vector<int> a)
        : FenwickTreeRangeUpdatePointQuery(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            range_add(i, i, a[i]);
    }

    
    int point_query(int idx) {
        int ret = 0;
        for (++idx; idx > 0; idx -= idx & -idx)
            ret += bit[idx];
        return ret;
    }

    void range_add(int l, int r, int val) {
        add(l, val);
        add(r + 1, -val);
    }


    void add(int idx, int delta) {
        for (++idx; idx < n; idx += idx & -idx)
            bit[idx] += delta;
    }
};