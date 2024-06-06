void compressaoCoordenadas (int *vet , int n){
    int aux[n];
    for(int i = 0; i < n; i++) aux[i] = vet[i];
    sort(aux , aux+n);
    for(int i = 0; i < n; i++) 
        vet[i] = lower_bound(aux , aux+n);
}