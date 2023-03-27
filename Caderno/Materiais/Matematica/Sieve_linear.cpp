// Sieve de Eratosthenes com linear sieve
// Encontra todos os números primos no intervalo [2, N]
// Complexidade: O(N)

const int N = 10000000;
vector<int> lp(N + 1); // lp[i] = menor fator primo de i
vector<int> pr;        // vetor de primos

for (int i = 2; i <= N; ++i)
{
    if (lp[i] == 0)
    {
        lp[i] = i;
        pr.push_back(i);
    }
    for (int j = 0; i * pr[j] <= N; ++j)
    {
        lp[i * pr[j]] = pr[j];
        if (pr[j] == lp[i])
        {
            break;
        }
    }
}