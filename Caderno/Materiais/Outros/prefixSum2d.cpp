inline void fill_prefix_sum() {
    prefix_sum[0][0] = mat[0][0];

    for(int i = 1; i < N; i++)
        prefix_sum[i][0] = prefix_sum[i-1][0] + mat[i][0];
    
    for(int i = 1; i < N; i++)
        prefix_sum[0][i] = prefix_sum[0][i-1] + mat[0][i];
    
    for(int i = 1; i < N; i++) {
        for(int j = 1; j < N; j++)
            prefix_sum[i][j] = prefix_sum[i-1][j] + prefix_sum[i][j-1] - prefix_sum[i-1][j-1] + mat[i][j];
    }
}