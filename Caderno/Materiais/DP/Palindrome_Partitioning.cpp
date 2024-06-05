/* partition s such that every substring
of the partition is a palindrome */
// minimum cuts needed for a palindrome partitioning of s

bool is_palindrome(int i, int j) {
    if(i == j) return true;
    else if(i == j-1) return this->str[i] == this->str[j];

    if(memo2[i][j] != -1) return memo2[i][j];
    return memo2[i][j] = this->str[i] == this->str[j] && is_palindrome(i+1, j-1);
}

int dp(int i) {
    int size = str.length();
    if(i == size) return 0;
    if(memo[i] != -1) return memo[i];
    int ans = INT_MAX;
    for(int j = i; j < size; j++) {
        if(is_palindrome(i, j)) {
            ans = min(ans, dp(j+1) + 1);
        }
    }

    return memo[i] = ans;
}