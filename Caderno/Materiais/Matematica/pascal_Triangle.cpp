vector< vector<int> > pascal;
vector< vector<int> > pascalTable() { // C(n,r)
    vector< vector<int> > vec;
    vec.pb({1});
    vec.pb({1, 1});

    for(int i = 2; i < n; i++) { // row: n
        vector<int> v(i + 1, 1);
        int size = i+1;

        for(int j = 1; j < size - 1; j++) // column: r
            v[j] = vec[i - 1][j] + vec[i - 1][j - 1];
        vec.pb(v);
    }
    return vec;
}