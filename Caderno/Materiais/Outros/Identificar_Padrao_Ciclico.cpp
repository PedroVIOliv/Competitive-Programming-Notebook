// Utiliza a técnica de prefixo-sufixo do algoritmo KMP para encontrar o ponto de início
// e o tamanho de um ciclo dentro de um vetor de inteiros
// O(n)
pii identifyPattern(vector<int> v){
    int n = v.size();
    reverse(v.begin(), v.end());
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 and v[i] != v[j])
            j = pi[j-1];
        if (v[i] == v[j]) j++;
        pi[i] = j;
    }
    tuple<int, int, int> ans(n, 1, n-1);
    for(int i=1; i<=n; i++){
        int p = i - pi[i-1];
        if(p == 0) continue;
        int idx = n-i;
        ans = min(ans, {idx+p, p, idx});
    }
    auto [sum, p, idx] = ans;
    return pii(idx, p);
}