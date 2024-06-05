// Resolver problemas em que ha varias equacoes do tipo
// X = r1 (mod m1)
// X = r2 (mod m2)
// X = r3 (mod m3)...
// Queremos descobrir X
typedef __int128 big;
ll mulmod(ll a, ll b, ll m){
    return ll(big(a)*big(b))%m;
}
ll expmod(ll a, ll e, ll m){
    ll ret = 1;
    while (e > 0) {
        if (e % 2 != 0) ret = mulmod(ret, a, m);
        a = mulmod(a, a, m);
        e >>= 1;
    }
    return ret;
}
ll invmul(ll a, ll m) {
    return expmod(a, m - 2, m);
}
ll chinese(vector<ll> r, vector<ll> m) {
    int sz = m.size();
    ll M = 1;
    for (int i = 0; i < sz; i++)
        M *= m[i];
    ll ret = 0;
    for (int i = 0; i < sz; i++) {
        ret += mulmod(mulmod(M / m[i], r[i], M), invmul(M / m[i], m[i]), M);
        ret = ret % M;
    }
    return ret;
}