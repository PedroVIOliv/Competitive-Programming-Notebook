typedef pair<int,int> pt;

ll sarea2(pt p, pt q, pt r) { // 2 * area com sinal
    return (q.first-p.first)*(ll)(r.second-q.second) - (q.second-p.second)*(ll)(r.first-q.first);
}

bool ccw(pt p, pt q, pt r) { // se p, q, r sao ccw
    return sarea2(p, q, r) > 0;
}

vector<pt> convex_hull(vector<pt> v) { // convex hull - O(n log(n))
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    if (v.size() <= 1) return v;
    vector<pt> l, u;
    for (int i = 0; i < v.size(); i++) {
        while (l.size() > 1 and !ccw(l.end()[-2], l.end()[-1], v[i]))
            l.pop_back();
        l.push_back(v[i]);
    }
    for (int i = v.size() - 1; i >= 0; i--) {
        while (u.size() > 1 and !ccw(u.end()[-2], u.end()[-1], v[i]))
            u.pop_back();
        u.push_back(v[i]);
    }
    l.pop_back(); u.pop_back();
    for (pt i : u) l.push_back(i);
    return l;
}

// overall O(n log n)
vector<point> CH_Andrew(vector<point> &Pts) {
    int n = Pts.size(), k = 0;
    vector<point> H(2*n);
    sort(Pts.begin(), Pts.end());
    // sort the points by x/y
    for (int i = 0; i < n; ++i) {
        // build lower hull
        while ((k >= 2) && !ccw(H[k-2], H[k-1], Pts[i])) --k;
        H[k++] = Pts[i];
    }
    for (int i = n-2, t = k+1; i >= 0; --i) {
        // build upper hull
        while ((k >= t) && !ccw(H[k-2], H[k-1], Pts[i])) --k;
        H[k++] = Pts[i];
    }
    H.resize(k);
    return H;
}