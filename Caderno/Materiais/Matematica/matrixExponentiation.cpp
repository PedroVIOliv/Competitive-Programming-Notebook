// Resolvemos relacoes de recorrencia como fibonacci por exemplo
// T: [ [a, b], [c, d] ]
// F(n): [[f(n)], [f(n - 1)]]
// F(n + 1): [ [f(n + 1)], [f(n)] ] = [ [f(n) + f(n - 1)], [f(n)] ]
// T x F(n) = F(n + 1), tem que achar T
// T^p = [ [F(p+1), F(p)], [F(p), F(p-1)] ]

const int MAX_SZ = 2;
struct Matrix {
    int mat[MAX_SZ][MAX_SZ];
    Matrix() {
        memset(mat, 0, sizeof(mat));
    }
};
int mod(int a, int m) { return ((a%m) + m) % m; }
Matrix matMul(Matrix a, Matrix b) {
    Matrix ans;
    for(int i = 0; i < MAX_SZ; i++) {
        for(int k = 0; k < MAX_SZ; k++) {
            if(a.mat[i][k] == 0) continue;
            for(int j = 0; j < MAX_SZ; j++) {
                ans.mat[i][j] += mod(a.mat[i][k], MOD) * mod(b.mat[k][j], MOD);
                ans.mat[i][j] = mod(ans.mat[i][j], MOD);
            }
        }
    }
    return ans;
}
Matrix matPow(Matrix base, int e) {
    Matrix ans;
    for(int i = 0; i < MAX_SZ; i++)
        for(int j = 0; j < MAX_SZ; j++)
            ans.mat[i][j] = (i == j); // identity matrix
    
    while(e) { // fast exponentiation
        if(e&1) ans = matMul(ans, base);
        base = matMul(base, base);
        e >>= 1;
    }
    return ans;
}