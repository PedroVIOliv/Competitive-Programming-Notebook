bool isOdd(int n) { return n&1; }

// Obter o bit "i" de n (sendo que o bit mais à direita é o 0)
int getIthBit(int n, int i) { return (n & (1 << i)) > 0; }

// Limpar o bit "i" de n (sendo que o bit mais à direita é o 0)
int clearIthBit(int n, int i) { return (n & ~(1 << i)); }

// Ligar o bit "i" de n
int setIthBit(int n, int i) { return (n | (1 << i)); }

// Inverter o bit "i" de n
int toggleIthBit(int n, int i) { return (n ^ (1 < i)); }

// Limpar os últimos "i" bits de n
int clearLastIthBits(int n, int i) { return (n & (-1 << i)); }

// Ligar todos os n bits
int turnAllBitsOn(int n) { return (1 << n)-1; }

// Pode obter o bit ligado menos significativo
bool isTwoPower(int n) { return (n & (n-1)); }

int howManyBitsOn(int n) { return __builtin_popcount(n); }

int howManyTrailingZeros(int n) { return __builtin_ctz(n); }

void enumerateAllBitmaskSubsets(int n) {
    for(int subset = n; subset; subset = (n & (subset-1)))
        cout << subset << endl;
}
