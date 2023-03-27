// Crivo de Eratóstenes para gerar primos até um limite 'lim'
// Complexidade: O(n log log n), onde n é o limite
const int ms = 1e6 + 5;
bool notPrime[ms];   // notPrime[i] é verdadeiro se i não é um número primo
int primes[ms], qnt; // primes[] armazena os números primos e qnt é a quantidade de primos encontrados

void sieve(int lim)
{
  primes[qnt++] = 1; // adiciona 1 como um número primo se ele for válido no problema
  for (int i = 2; i <= lim; i++)
  {
    if (notPrime[i])
      continue;                           // se i não é primo, pula
    primes[qnt++] = i;                    // i é primo, adiciona em primes[]
    for (int j = i + i; j <= lim; j += i) // marca todos os múltiplos de i como não primos
      notPrime[j] = true;
  }
}