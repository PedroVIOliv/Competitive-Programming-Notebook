// Fenwick Tree (BIT) para somas de intervalos em uma matriz
// 0-based
struct FenwickTree2D {
    vector<vector<int>> bit;
    int n, m; // linhas, colunas

    FenwickTree2D(int n, int m) {
        this->n = n;
        this->m = m;
        this->bit.resize(n, vector<int>(m, 0));
    }

    // O(n)
    FenwickTree2D(vector<vector<int>> &a, int n, int m) : FenwickTree2D(n, m) {
        for (size_t i = 0; i < n; i++)
            for(size_t j = 0; j < m; j++)
                add(i, j, a[i][j]);
    }

    // O(logn)
    int sum(int x, int y) {
        int ret = 0;
        for (int i = x; i >= 0; i = (i & (i + 1)) - 1)
            for (int j = y; j >= 0; j = (j & (j + 1)) - 1)
                ret += bit[i][j];
        return ret;
    }

    // Retorna a soma dos elementos no intervalo em que (xr, yr) é o inferior direito
    // e (xl, yl) é o superior esquerdo
    // O(logn)
    int sum(int xl, int yl, int xr, int yr) {
        return sum(xr, yr) - sum(xr, yl-1) - sum(xl-1, yr) + sum(xl-1, yl-1); 
    }

    // O(logn)
    void add(int x, int y, int delta) { // add delta em (x, y)
        for (int i = x; i < n; i = i | (i + 1))
            for (int j = y; j < m; j = j | (j + 1))
                bit[i][j] += delta;
    }
};