int dist[MAX][ MAX], memo[MAX ][1 << MAX];
int tsp(int pos , int bitmask ){
    if(bitmask == (1 << (n+1)) - 1)
        return dist[pos ][0];
    if(memo[pos][ bitmask] != -1)
        return memo[pos][ bitmask ];
    int ans = 2000000000;
    for(int nxt = 0; nxt <= n; nxt ++)
        if(nxt != pos && !( bitmask & (1 << nxt )))
        ans = min(ans , dist[pos][nxt] + tsp(nxt , bitmask | (1 << nxt )));
    return memo[pos][ bitmask] = ans;
}