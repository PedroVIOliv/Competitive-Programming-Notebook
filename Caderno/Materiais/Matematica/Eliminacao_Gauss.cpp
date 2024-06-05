const int N=105;
//resolvendo o sisteminha Ax = B
//no final, B tem a solucao x
//det eh o determinante de A
// complexidade: O(nˆ3)
ld A[N][N], B[N];
int n;
12
void solve() {
    ld mult;
    ld det = 1;
    for(int i=0; i<n; i++) {
        int nx = i;
        while(nx < n and fabs(A[nx][i]) < 1e-9) nx++;
        //NO SOLUTION or INFINITY SOLUTIONS
        if(nx == n) det = 0;
        if(nx != i) {
            swap(A[nx], A[i]);
            swap(B[nx], B[i]);
            det = -det;
        }
        det *= A[i][i];
        // normalizando
        mult = 1.00 / A[i][i];
        for(int j=0; j<n; j++)
            A[i][j] *= mult;
        B[i] *= mult;
        for(int j=0; j<n; j++) {
            if(j == i) continue;
            if(fabs(A[j][i]) > 1e-9) {
                mult = A[j][i];
                for(int k=0; k<n; k++)
                    A[j][k] -= mult * A[i][k];
                B[j] -= mult * B[i];
            }
        }
    }
}