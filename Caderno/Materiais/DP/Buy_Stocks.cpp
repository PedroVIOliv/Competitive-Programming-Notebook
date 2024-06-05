// Find the maximum profit you can achieve. You may complete at most k transactions
int dp(vector<int>& prices, int i, int k, bool buy) {
    if(i == prices.size()) return 0;
    if(memo[i][buy][k] != -1) return memo[i][buy][k];

    // neither buy nor sell
    int ans = dp(prices, i+1, k, buy);
    if(k == 0) return 0;

    if(buy) // you can buy or don't buy
        ans = max(ans, dp(prices, i+1, k, false) - prices[i]); // bought
    else
        ans = max(ans, dp(prices, i+1, k-1, true) + prices[i]);

    return memo[i][buy][k] = ans;
}

// You may complete as many transactions as you like
// After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).