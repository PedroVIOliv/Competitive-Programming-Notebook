// Para modulo de numero negativo
int mod(int a, int b) { return ((a % b) + b) % b; }
int addm(int x, int y, int P) { return ((x % P) + (y % P)) % P; }
int subm(int x, int y, int P) { return mod(x-y, P); }
int mulm(int x, int y, int P) { return ((x % P) * (y % P)) % P; }
// Using Fermats Theorem
int divm(int x, int y) { 
    return mulm(x, fexp(y, p-2)); // fast exponentiation
}