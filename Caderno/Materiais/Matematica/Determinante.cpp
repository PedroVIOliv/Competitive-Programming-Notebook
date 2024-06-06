const int N=105;
//calculo do determinante
//COM COEFICIENTES INTEIROS --> PICA!
//segue a ideia do calculo do GCD
//complexidade: O(nˆ3 lg MX)
//0 erro de precisao
//0-based porque sim!
ll mat[N][N];
int n;
void limpa(int a) {
    for(int i=0; i<n; i++)
        mat[a][i] = -mat[a][i];
}
void troca(int a, int b) {
    for(int i=0; i<n; i++)
        swap(mat[a][i], mat[b][i]);
}
ll det() {
    ll ans = 1;
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            int a = i, b = j;
            if(mat[a][i] < 0) limpa(a), ans = -ans;
            if(mat[b][i] < 0) limpa(b), ans = -ans;
            
            while(mat[b][i] != 0) {
                ll q = mat[a][i] / mat[b][i];
                for(int k=0; k<n; k++)
                    mat[a][k] -= q * mat[b][k];
                swap(a, b);
            }
            if(a != i) {
                troca(i, j);
                ans = -ans;
            }
        }
        ans *= mat[i][i];
    }
    return ans;
}