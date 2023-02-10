// pre() gera um vetor pi com o tamanho da string ne
// pi[i] = tamanho do maior prefixo de ne que eh sufixo de ne[0..i]
// Complexidade: O(n)
vector<int> pre(string ne) 
{
    int n = ne.size();
    vector<int> pi(n, 0);
    for (int i = 1, j = 0; i < n; i++)
    {
        while (j > 0 && ne[i] != ne[j]) j = pi[j - 1];
        if (ne[i] == ne[j]) j++;
        pi[i] = j;
    }
    return pi;
}
// search() retorna o numero de ocorrencias de ne em hay
// complexidade: O(n+m)
int search(string hay, string ne) 
{
    vector<int> pi = pre(ne);
    int c = 0;
    for (int i = 0, j = 0; i < hay.size(); i++)
    {
        while (j > 0 && hay[i] != ne[j]) j = pi[j - 1];
        if (hay[i] == ne[j]) j++;
        if (j == ne.size())
        {
            c++;
            // match at (i-j+1)
            j = pi[j - 1];
        }
    }
    return c;
}