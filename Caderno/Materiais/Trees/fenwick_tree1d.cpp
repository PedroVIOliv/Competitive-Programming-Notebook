// Fenwick Tree (Binary Indexed Tree) para somas de intervalos
// Complexidade:
vector<int> bit; // vetor da arvore
int n;

// Construtor da Fenwick tree usando add()
// O(n log n)
void build(vector<int> &a) {
    n = a.size() + 1;
    bit.assign(n + 1, 0);
    for (size_t i = 0; i < a.size(); i++)
        add(i, a[i]);
}

// Construtor da Fenwick tree usando prefix sums
// O(n)
void build2(vector<int> &a) {
    n = a.size() + 1;
    bit.assign(n + 1, 0);
    for (int i = 1; i < n; i++)
        bit[i] += a[i - 1]; 
    for (int i = 1; i < n; i++) {
        int j = i + (i & -i);
        if (j < n)
            bit[j] += bit[i];
    }
}

// Retorna a soma dos valores dos primeiros 'idx + 1' elementos
// O(logn)
int sum(int idx) {
    int ret = 0;
    for (++idx; idx > 0; idx -= idx & -idx)
        ret += bit[idx];
    return ret;
}

// Retorna a soma dos valores dos elementos no intervalo [l, r]
// O(logn)
int sum(int l, int r) {
    return sum(r) - sum(l - 1);
}

// Adiciona 'delta' ao valor na posicao 'idx' do vetor
// O(logn)
void add(int idx, int delta) {
    for (++idx; idx < n; idx += idx & -idx)
        bit[idx] += delta;
}