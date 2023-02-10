// a funcao z gera um vetor z com o tamanho da string s
//z[i] = tamanho do maior prefixo de s que eh sufixo de s[i..n-1]
//Complexidade: O(n)

vector<int> prefix_function(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}