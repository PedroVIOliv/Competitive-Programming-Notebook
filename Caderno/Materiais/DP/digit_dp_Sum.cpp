// soma dos dígitos até n
string n;
int memo[10][2][90];
int dp(int index, bool last, int sum) {
    if(index == n.size()) return sum;
    if(memo[index][last][sum] != -1) return memo[index][last][sum];
    int till = (last ? n[index] - '0' : 9); // limite
    int ans = 0;
    for(int digit = 0; digit <= till; digit++)
        ans += dp(index + 1, (last && (digit == till)), sum + digit);
    return memo[index][last][sum] = ans;
}