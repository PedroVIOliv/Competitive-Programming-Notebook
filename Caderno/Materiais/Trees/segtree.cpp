int v[MAXN];  // input array
Tnode seg[4 * MAXN];  // segment tree

Tnode combine(Tnode left, Tnode right) {
    // definir como combinar dois nós da árvore
}

Tnode build(int p, int l, int r) { // O(n) 
    if (l == r) return seg[p] = ...;  
    int m = (l + r) / 2;
    Tnode left = build(p * 2, l, m);
    Tnode right = build(p * 2 + 1, m + 1, r);
    return seg[p] = combine(left, right);
        
}

Tnode update(int i, int x, int p, int l, int r) { // O(log n)
    if (i < l || r < i) return seg[p];
    if (l == r) {
        seg[p] = ...; // definir o que retornar quando l == r == i
        return seg[p];
    }
    int m = (l + r) / 2;
    Tnode left = update(i, x, p * 2, l, m);
    Tnode right = update(i, x, p * 2 + 1, m + 1, r);
    return seg[p] = combine(left, right);
    
}

Tnode query(int ql, int qr, int p, int l, int r) { // O(log n)
    if (qr < l || r < ql) { 
        return ...;  // definir o que retornar quando não há interseção
    }
    if (ql <= l && r <= qr) { 
        return seg[p];
    }
    int m = (l + r) / 2;
    Tnode left = query(ql, qr, p * 2, l, m);
    Tnode right = query(ql, qr, p * 2 + 1, m + 1, r);
    return combine(left, right);
}