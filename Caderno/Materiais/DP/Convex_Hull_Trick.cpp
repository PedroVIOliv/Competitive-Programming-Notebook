struct line {
    ll m, b;
    ll eval(ll x) { return m * x + b; }
    ld inter(line &l) { return (ld) (b - l.b) / (l.m - m); }
};
// otimizacao de DP para obter o maximo
// pode haver varias funcoes (linhas)
// ha um determinado x e queremos saber o valor maximo que alguma
// das funcoes pode retornar
struct cht {
    vector<line> lines;
    vector<ld> inter;
    int n;
    inline bool ok(line &a, line &b, line &c) {
        return a.inter(c) > a.inter(b);
    }
    void add(line &l) { /// m1 < m2 < m3 ...
        n = sz(lines);
        if(n && lines.back().m == l.m && lines.back().b >= l.b) return;
        if(n == 1 && lines.back().m == l.m 
            && lines.back().b < l.b) lines.pop_back(), n--;

        while(n >= 2 && !ok(lines[n-2], lines[n-1], l)) {
            --n;
            lines.pop_back(); inter.pop_back();
        }
        lines.pb(l); n++;
        if(n >= 2) inter.pb(lines[n-2].inter(lines[n-1]));
    }
    ll get_max(ld x) {
        if(sz(lines) == 0) return LLONG_MIN;
        if(sz(lines) == 1) return lines[0].eval(x);
        int pos = lower_bound(all(inter), x) - inter.begin();
        return lines[pos].eval(x);
    }
};


/* Esse convex hull trick e para achar a reta minima!
* Para maximizar a reta dada , basta trocar o ’>’ para
* para ’<’ na funcao query;
* Nao chamar query com B ou A vazios! Atualizar dp para
* depois fazer a query =)
* ATENCAO COM O DOUBLE!! ESTA EM LONG LONG :)
*/
vi A[N], B[N];
int pont[N];
bool odomeioehlixo(int r1, int r2, int r3, int j) {
    return (B[j][r1] - B[j][r3]) * (A[j][r2] - A[j][r1]) <
        (B[j][r1] - B[j][r2]) * (A[j][r3] - A[j][r1]);
}
void add(ll a, ll b, int j) {
    B[j].pb(b);
    A[j].pb(a);
    while (B[j].size() >= 3 and
    odomeioehlixo(B[j].size() - 3, B[j].size() - 2, B[j].size() - 1, j)) {
        B[j].erase(B[j].end() - 2);
        A[j].erase(A[j].end() - 2);
    }
}
ll query(ll x, int j) {
    if (pont[j] >= B[j].size()) pont[j] = B[j].size() - 1;
    while (pont[j] < B[j].size() - 1 and
        (A[j][pont[j] + 1] * x + B[j][pont[j] + 1] >
        A[j][pont[j]] * x + B[j][pont[j]]))
            pont[j]++;
    return A[j][pont[j]] * x + B[j][pont[j]];
}